#include <QApplication>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>
#include "src/linear_algebra/CPULinearAlgebra.h"
#include "src/neural_network/CPUNeuralNetwork.h"
#include "src/neural_network/GPUNeuralNetwork.h"
#include "src/chess/MinimaxMovePredictor.h"
#include "src/chess/NeuralMinimaxMovePredictor.h"
#include "src/chess/Board.h"
#include "test.h"
#include "cuda.h"
#include "ui/mainwindow.h"

using namespace std;

float cpsToWin(float cps) {
    return 0.5 + 0.5 * (2 / (1 + expf(-0.00368208 * cps)) - 1);
}

void loadData(std::string fileName, float **&labels, float **&pixels, int cnt) {
    std::ifstream in("../" + fileName);
    labels = new float *[cnt];
    pixels = new float *[cnt];
    for (int i = 0; i < cnt; i++) {
        labels[i] = new float[10];
        for (int j = 0; j < 10; j++)
            labels[i][j] = 0;
        pixels[i] = new float[28 * 28];
    }
    for (int i = 0; i < cnt; i++) {
        std::string s;
        getline(in, s, ',');
        labels[i][std::stoi(s)] = 1;
        for (int j = 0; j < 784; j++) {
            char sep = ',';
            if (j == 783)
                sep = '\n';
            getline(in, s, sep);
            pixels[i][j] = std::stof(s);
        }
    }
    in.close();
}

void shuffle(float **x, float **y, int n, int cnt) {
    while (cnt--) {
        auto i1 = doRandomInt(0, n - 1);
        auto i2 = doRandomInt(0, n - 1);
        std::swap(x[i1], x[i2]);
        std::swap(y[i1], y[i2]);
    }
}

void mnist_network() {
    int test_cnt = 10000, train_cnt = 60000;
    float **labels_test, **labels_train;
    float **pixels_test, **pixels_train;
    loadData("MNIST_test.txt", labels_test, pixels_test, test_cnt);
    loadData("MNIST_train.txt", labels_train, pixels_train, train_cnt);
    for (int i = 0; i < test_cnt; i++) {
        for (int j = 0; j < 28 * 28; j++) {
            pixels_test[i][j] /= 256;
        }
    }
    for (int i = 0; i < train_cnt; i++) {
        for (int j = 0; j < 28 * 28; j++) {
            pixels_train[i][j] /= 256;
        }
    }

    int n = 7;
    std::vector<int> sizes(n);
    std::vector<ActivationType> types(n);
    for (int i = 1; i < n - 1; i++)
        types[i] = ActivationType::LRelu;
    types[0] = ActivationType::Nothing;
    types[n - 1] = ActivationType::Sigmoid;
    sizes[0] = 784;
    sizes[1] = 256;
    sizes[2] = 256;
    sizes[3] = 256;
    sizes[4] = 256;
    sizes[5] = 256;
    sizes[6] = 10;
    GPUNeuralNetwork nn(sizes);
    nn.setErrorActivationType(ActivationType::SquaredError);
    nn.setActivationType(types);
    float alpha = 0.001;
    train_cnt = 60000;

    while (true) {
        std::cout << "what do you want?\n1)train n times\n2)test\n3)set alpha\n";
        int op;
        std::cin >> op;

        switch (op) {
            case (1): {
                std::cout << "enter n: ";
                int n;
                std::cin >> n;
                auto start = clock();
                for (int j = 0; j < n; j++) {
                    float error = 0.0;
                    for (int i = 0; i < train_cnt; i++) {
                        if ((i * 100) / train_cnt > ((i - 1) * 100) / train_cnt) {
//                            std::cout<<"training "<<100 * i / train_cnt<<" %\n";
                        }
                        std::pair<float, bool> res = nn.train(pixels_train[i % train_cnt], labels_train[i % train_cnt],
                                                              alpha);
                        error += res.first;
                    }
                    error /= train_cnt;
                    std::cout << "error " << error << '\n';
                    shuffle(pixels_train, labels_train, train_cnt, 10000);
                    float correct = 0;
                    for (int i = 0; i < test_cnt; i++) {
                        float *res = nn.predict(pixels_test[i]);
                        float mx = -1e9;
                        int ind = -1;
                        for (int j = 0; j < 10; j++) {
                            if (res[j] > mx) {
                                mx = res[j];
                                ind = j;
                            }
                        }
                        if (labels_test[i][ind] >= 0.99)
                            correct++;
                    }
                    std::cout << "correct " << correct / test_cnt << '\n';
                }
                std::cout << "time: " << (clock() - start) << '\n';
                break;
            }
            case (2): {
                float correct = 0;
                for (int i = 0; i < test_cnt; i++) {
                    float *res = nn.predict(pixels_test[i]);
                    float mx = -1e9;
                    int ind = -1;
                    for (int j = 0; j < 10; j++) {
                        if (res[j] > mx) {
                            mx = res[j];
                            ind = j;
                        }
                    }
                    if (labels_test[i][ind] >= 0.99)
                        correct++;
                }
                std::cout << "correct " << correct / test_cnt << '\n';
                break;
            }
            case (3): {
                std::cout << "enter alpha: ";
                std::cin >> alpha;
            }

        }
    }
}

void gameToMoves(const string &game, vector<string> &moves) {
    string ts = "";
    for (int i = 0; i < game.size(); i++) {
        if (game[i] == ' ') {
            moves.push_back(ts);
            ts = "";
            continue;
        }
        ts += game[i];
    }
}

void loadChessData(std::string fileName, vector<string> &data, int &cnt) {
    std::ifstream in("../" + fileName);
    string s;
    while (getline(in, s)) {
        cnt++;
        data.push_back(s);
    }
}

//winner 0 - draw, 1 - white, 2 - black
void evaluatorGameToMoves(const string &game, vector<string> &moves, int &winner) {
    string ts = "";
    int ind = 0;
    for (int i = 0; i < game.size(); i++) {
        if (game[i] == ' ') {
            if (ind == 0) {
                if (ts == "0-1")
                    winner = 2;
                else if (ts == "1-0")
                    winner = 1;
                else
                    winner = 0;
            } else {
                moves.push_back(ts);
            }
            ts = "";
            ind++;
            continue;
        }
        ts += game[i];
    }
}

void stockfishGameToMoves(const string &game, vector<string> &moves, vector<float> &values) {
    std::string ts = "";
//    cout<<game<<'\n';
    int ind = 0;
    for (char c: game) {
        if (c == ' ') {
            if(ts.empty())
                continue;
            if (ind % 2 == 0)
                moves.push_back(ts);
            else
                values.push_back(cpsToWin(stof(ts)));
            ind++;
            ts = "";
        } else {
            ts += c;
        }
    }
}

void loadEvaluatorChessData(std::string fileName, vector<string> &data, int &cnt) {
    std::ifstream in("../" + fileName);
    string s;
    while (getline(in, s)) {
        cnt++;
        data.push_back(s);
    }
}

void newestEvaluator() {
    vector<int> sizes(5);
    sizes[0] = 1122;
    sizes[1] = 512;
    sizes[2] = 256;
    sizes[3] = 128;
    sizes[4] = 1;

    vector<ActivationType> types(5);
    types[0] = ActivationType::Nothing;
    for (int i = 1; i < 5; i++)
        types[i] = ActivationType::LRelu;
    types[4] = ActivationType::Sigmoid;
    BaseNeuralNetwork *network = new GPUNeuralNetwork(sizes);
    network->setActivationType(types);
    network->setErrorActivationType(ActivationType::SquaredError);
    vector<string> data, testData;
    int cnt = 0, testCnt = 0;
    loadEvaluatorChessData("stockfish_dataset/train", data, cnt);
    loadEvaluatorChessData("stockfish_dataset/test", testData, testCnt);
    data.pop_back();
//    for(int i = 0; i < cnt / 100; i++){
//        testData.push_back(data.back());
//        testCnt++;
//        data.pop_back();
//        cnt--;
//    }
    float alpha = 0.00001;
    cout<<cnt<<' '<<testCnt<<'\n';

    cnt *= 0.95;
    testCnt *= 0.95;
    cout<<cnt<<' '<<testCnt<<'\n';
    while (true) {
        std::cout << "what do you want?\n1)train\n2)save\n3)load\n4)new alpha\n";
        int op;
        cin >> op;
        switch (op) {
            case (1): {
                int n;
                cout << "enter n:\n";
                cin >> n;
                const int N = 250000;
                for (int t = 1; t <= n; t++) {

                    int ind = doRandomInt(0, cnt - 1);
                    if ((t * 100) / n > ((t - 1) * 100) / n) {
                        std::cout << (t * 100) / n << " %\n";
                    }
                    vector<float> values;
                    vector<string> moves;
                    stockfishGameToMoves(data[ind], moves, values);
                    if (moves.size() == 0)
                        continue;
                    int moveInd = doRandomInt(0, moves.size() - 1);

                    Board board;
                    for (int i = 0; i <= moveInd; i++) {
                        if(!board.isPossibleMove(moves[i])){
                            std::cout<<"cant move: "<<ind<<' '<<' '<<i<<' '<<moves[i]<<'\n';
                        }
                        board.move(moves[i]);
                    }
                    auto *y = new float[1];
                    y[0] = values[moveInd];
                    float *x = board.extendedEncodeBoard();

                    network->train(x, y, alpha);
                    delete[] x;
                    delete[] y;

                    if (t % N == 0) {
                        const string fileName = "../evaluator_statictics.txt";
                        ofstream out(fileName, ios::out | ios::app);
                        const int TEST_COUNT = 50000;
                        long double error = 0, errorCnt = 0;
                        for (int i = 0; i < TEST_COUNT; i++) {
                            int ind = doRandomInt(0, testCnt - 1);
                            vector<float> values;
                            vector<string> moves;
                            stockfishGameToMoves(testData[ind], moves, values);
                            if (moves.size() == 0)
                                continue;
                            int moveInd = doRandomInt(0, moves.size() - 1);
                            Board board;
                            for (int i = 0; i <= moveInd; i++) {
                                board.move(moves[i]);
                            }
                            float *x = board.extendedEncodeBoard();
                            float *y = network->predict(x);
                            error += powl(*y - values[moveInd], 2);
                            errorCnt++;
                            delete[] x;
                            delete[] y;
                        }
                        out << (error / errorCnt) << ' ';

                        error = 0, errorCnt = 0;
                        for (int i = 0; i < TEST_COUNT; i++) {
                            int ind = doRandomInt(0, cnt - 1);
                            vector<float> values;
                            vector<string> moves;
                            stockfishGameToMoves(data[ind], moves, values);
                            if (moves.size() == 0)
                                continue;
                            int moveInd = doRandomInt(0, moves.size() - 1);
                            Board board;
                            for (int i = 0; i <= moveInd; i++) {
                                board.move(moves[i]);
                            }
                            float *x = board.extendedEncodeBoard();
                            float *y = network->predict(x);
                            error += powl(*y - values[moveInd], 2);
                            errorCnt++;
                            delete[] x;
                            delete[] y;
                        }
                        out << (error / errorCnt) << '\n';
                        out.close();
                    }
                }
                break;
            }
            case (2): {
                network->save("evaluator.txt");
                break;
            }
            case (3): {
                network->load("evaluator.txt");
                break;
            }
            case (4): {
                cout << "enter new alpha: ";
                cin >> alpha;
                break;
            }
        }
    }

}

void evaluator() {
    vector<int> sizes(5);
    sizes[0] = 1122;
    sizes[1] = 256;
    sizes[2] = 256;
    sizes[3] = 256;
    sizes[4] = 1;

    vector<ActivationType> types(5);
    types[0] = ActivationType::Nothing;
    for (int i = 1; i < 5; i++)
        types[i] = ActivationType::LRelu;
    types[4] = ActivationType::Sigmoid;
    BaseNeuralNetwork *network = new GPUNeuralNetwork(sizes);
    network->setActivationType(types);
    network->setErrorActivationType(ActivationType::SquaredError);
    vector<string> data, testData;
    int cnt = 0, testCnt = 0;
    loadEvaluatorChessData("evaluator/train", data, cnt);
    loadEvaluatorChessData("evaluator/test", testData, testCnt);
    std::cout << "games " << cnt << '\n';
    vector<long double> correctCount(250, 0);
    vector<long double> movesCount(250, 0);
    vector<long double> sum(250, 0);
    float alpha = 0.001;
    float beta = 0.0001;
//    float alpha = 0;
//    float beta = 0;
    int randomMoves = 0;

//    std::map<unsigned long long, pair<double, double>> boards;
//    for(int i = 0; i < cnt; i++){
//        if(i % 10000 == 0 && boards.size() >= 200000000){
//            std::map<unsigned long long, pair<double, double>> newBoards;
//            for(auto t : boards){
//                if(t.second.second > 1)
//                    newBoards[t.first] = t.second;
//            }
//            boards.clear();
//            boards = newBoards;
//        }
//        if(i % 10000 == 0){
//            std::cout<<(long double)i / cnt * 100<<"%"<<' '<<"size: "<<boards.size()<<'\n';
//        }
//        Board board;
//        std::vector<std::string> moves;
//        int winner;
//        evaluatorGameToMoves(data[i], moves, winner);
//        for(int j = 0; j <= moves.size(); j++){
//            double toAdd = 0;
//            if(winner == 0) {
//                toAdd = 0.5;
//            }
//            else if(winner == 1){
//                if(j % 2 == 0)
//                    toAdd = 1;
//                else
//                    toAdd = 0;
//            }
//            else{
//                if(j % 2 == 0){
//                    toAdd = 0;
//                }
//                else{
//                    toAdd = 1;
//                }
//            }
//            unsigned long long hsh = board.hashBoard();
//            pair<double, double> p = boards[hsh];
//            p.second++;
//            p.first += toAdd;
//            boards[hsh] = p;
//            if(j == moves.size())
//                continue;
//            string m = moves[j];
//            board.move(m);
//        }
//    }
//    ofstream outBoards("../boards.txt");
//    for(auto t : boards){
//        if(t.second.second >= 2 && t.second.first != t.second.second && t.second.first  != 0)
//            outBoards<<t.first<<' '<<(t.second.first / t.second.second)<<'\n';
//    }
//    outBoards.close();

    ifstream inBoards("../boards.txt");
    map<unsigned long long, double> boards;
    unsigned long long curHash;
    while (inBoards >> curHash) {
        double chance;
        inBoards >> chance;
        boards[curHash] = chance;
    }
    while (true) {
        std::cout << "what do you want?\n1)train\n2)save\n3)load\n4)new alpha\n5)test\n";
        int op;
        cin >> op;
        switch (op) {
            case (1): {
                int n;
                cout << "enter n:\n";
                cin >> n;
                long double correct = 0, error = 0, testCount = 0;
//                const int N = 2500000;
                const int N = 25000;
                for (int t = 1; t <= n; t++) {

                    int ind = doRandomInt(0, cnt - 1);

                    if ((t * 100) / n > ((t - 1) * 100) / n) {
                        std::cout << (t * 100) / n << " %\n";
                    }
                    Board board, parentBoard;
                    vector<string> tempData;
                    int winner;
                    evaluatorGameToMoves(data[ind], tempData, winner);

                    if (tempData.size() <= 1) {
                        continue;
                    }
                    int i = doRandomInt(1, (int) tempData.size() - 1);
                    for (int j = 0; j < i; j++) {
                        if (j != i - 1) {
                            parentBoard.move(tempData[j]);
                        }
                        board.move(tempData[j]);
                    }
                    float *x = board.extendedEncodeBoard();
                    auto *y = new float[1];
                    unsigned long long boardHash = board.hashBoard();
//                    double chance = boards[boardHash];
                    double chance = 0;
                    if (chance == 0.0) {
                        if (winner == 0) {
                            y[0] = 0.5;
                        } else if (winner == 1) {
                            if (i % 2 == 0)
                                y[0] = 1;
                            else
                                y[0] = 0;
                        } else {
                            if (i % 2 == 0) {
                                y[0] = 0;
                            } else {
                                y[0] = 1;
                            }
                        }
                    } else {
                        y[0] = chance;
                    }
                    pair<float, bool> res = network->train(x, y, alpha);
                    if (winner != 0) {
                        error += res.first;
                        testCount++;
                        if (res.second) {
                            correct++;
                            if (i < correctCount.size())
                                correctCount[i]++;
                        }
                        if (i < movesCount.size())
                            movesCount[i]++;
                    }
//                    float *ev = network->predict(x);
//                    sum[0] += *ev;
//                    movesCount[0] += 1.0;
//                    if(winner != 0) {
//                        if (i < 250)
//                            sum[i] += *ev;
//                    }
                    delete[] x;
                    delete[] y;

//                    network->setErrorActivationType(ActivationType::CustomError);
                    for (int j = 0; j < randomMoves; j++) {
                        string move = Board::numberToUci(doRandomInt(0, 64 * 64 - 1));
                        if (!parentBoard.isPossibleMove(move))
                            continue;
                        if (move[0] == tempData[i - 1][0] && move[1] == tempData[i - 1][1] &&
                            move[2] == tempData[i - 1][2] && move[3] == tempData[i - 1][3])
                            continue;

                        Board tempBoard = Board(parentBoard);
                        tempBoard.move(move);
                        float *x = tempBoard.extendedEncodeBoard();
                        float *tev = network->predict(x);

                        auto *y = new float[1];
                        const float C = 10.0f;
//                        y[0] = -expf(C * (*ev - *tev)) / (1 + expf(C * (*ev - *tev)));
                        network->train(x, y, beta);

                        delete[] y;
                        delete[] tev;
                        delete[] x;
                    }
//                    network->setErrorActivationType(ActivationType::SquaredError);
//                    delete[] ev;
                    if (t % N == 0) {
                        const string fileName = "../evaluator_statictics.txt";
                        ofstream out(fileName, ios::out | ios::app);
                        out << fixed << setprecision(10);
//                        const int TEST_COUNT = 1000000;
                        const int TEST_COUNT = 10000;
                        long double correct = 0, count = 0;
                        for (int tt = 0; tt < TEST_COUNT; tt++) {
                            int ind = doRandomInt(0, testCnt - 1);
                            Board board, parentBoard;
                            vector<string> tempData;
                            int winner;
                            evaluatorGameToMoves(testData[ind], tempData, winner);
                            if (winner == 0)
                                continue;
                            if (tempData.size() <= 1) {
                                continue;
                            }
                            int i = doRandomInt(1, (int) tempData.size() - 1);
                            for (int j = 0; j < i; j++) {
                                if (j != i - 1) {
                                    parentBoard.move(tempData[j]);
                                }
                                board.move(tempData[j]);
                            }
                            float *x = board.extendedEncodeBoard();
                            auto *y = new float[1];

                            if (winner == 0) {
                                y[0] = 0.5;
                            } else if (winner == 1) {
                                if (i % 2 == 0)
                                    y[0] = 1;
                                else
                                    y[0] = 0;
                            } else {
                                if (i % 2 == 0) {
                                    y[0] = 0;
                                } else {
                                    y[0] = 1;
                                }
                            }

                            float *res = network->predict(x);
                            if (fabs(*res - *y) < 0.5f) {
                                correct++;
                            }
                            count++;

                            delete[] res;
                            delete[] x;
                            delete[] y;
                        }
                        out << (correct / count) << ' ';

                        correct = 0, count = 0;
                        for (int tt = 0; tt < TEST_COUNT; tt++) {
                            int ind = doRandomInt(0, cnt - 1);
                            Board board, parentBoard;
                            vector<string> tempData;
                            int winner;
                            evaluatorGameToMoves(data[ind], tempData, winner);
                            if (winner == 0)
                                continue;
                            if (tempData.size() <= 1) {
                                continue;
                            }
                            int i = doRandomInt(1, (int) tempData.size() - 1);
                            for (int j = 0; j < i; j++) {
                                if (j != i - 1) {
                                    parentBoard.move(tempData[j]);
                                }
                                board.move(tempData[j]);
                            }
                            float *x = board.extendedEncodeBoard();
                            auto *y = new float[1];

                            if (winner == 0) {
                                y[0] = 0.5;
                            } else if (winner == 1) {
                                if (i % 2 == 0)
                                    y[0] = 1;
                                else
                                    y[0] = 0;
                            } else {
                                if (i % 2 == 0) {
                                    y[0] = 0;
                                } else {
                                    y[0] = 1;
                                }
                            }

                            float *res = network->predict(x);
                            if (fabs(*res - *y) < 0.5f) {
                                correct++;
                            }
                            count++;

                            delete[] res;
                            delete[] x;
                            delete[] y;
                        }
                        out << (correct / count) << '\n';
                        out.close();
                    }
                }
                std::cout << "result: " << correct / testCount << ' ' << error / testCount << '\n';
                for (int j = 0; j < correctCount.size(); j++) {
                    std::cout << j << ") " << correctCount[j] / movesCount[j] << ' ' << sum[j] / movesCount[j] << ' '
                              << movesCount[j] << '\n';
                }
                break;
            }
            case (2): {
                network->save("evaluator.txt");
                break;
            }
            case (3): {
                network->load("evaluator.txt");
                break;
            }
            case (4): {
                cout << "enter new alpha: ";
                cin >> alpha;
                break;
            }
            case (5): {
                std::cout << testCnt << '\n';
                int n;
                cin >> n;
                long double correct = 0, count = 0;
                for (int t = 0; t < n; t++) {
                    int ind = doRandomInt(0, testCnt - 1);


                    if ((t * 100) / n > ((t - 1) * 100) / n) {
                        std::cout << (t * 100) / n << " %\n";
                    }
                    Board board, parentBoard;
                    vector<string> tempData;
                    int winner;
                    evaluatorGameToMoves(testData[ind], tempData, winner);
                    if (winner == 0)
                        continue;
                    if (tempData.size() <= 1) {
                        continue;
                    }
                    int i = doRandomInt(1, (int) tempData.size() - 1);
                    for (int j = 0; j < i; j++) {
                        if (j != i - 1) {
                            parentBoard.move(tempData[j]);
                        }
                        board.move(tempData[j]);
                    }
                    float *x = board.extendedEncodeBoard();
                    auto *y = new float[1];

                    if (winner == 0) {
                        y[0] = 0.5;
                    } else if (winner == 1) {
                        if (i % 2 == 0)
                            y[0] = 1;
                        else
                            y[0] = 0;
                    } else {
                        if (i % 2 == 0) {
                            y[0] = 0;
                        } else {
                            y[0] = 1;
                        }
                    }

                    float *res = network->predict(x);
                    if (fabs(*res - *y) < 0.5f) {
                        correct++;
                    }
                    count++;

                    delete[] res;
                    delete[] x;
                    delete[] y;
                }
                std::cout << "result " << (correct / count) << '\n';
            }
        }
    }
}

void predictor() {
    vector<int> sizes(8);
    sizes[0] = 1122;
    sizes[1] = 1024;
    sizes[2] = 1024;
    sizes[3] = 1024;
    sizes[4] = 1024;
    sizes[5] = 1024;
    sizes[6] = 1024;
    sizes[7] = 4184;
    vector<ActivationType> types(8);
    types[0] = Nothing;
    for (int i = 1; i < 8; i++)
        types[i] = LRelu;
    types[7] = SoftMax;
    BaseNeuralNetwork *predictor = new GPUNeuralNetwork(sizes);
    predictor->setActivationType(types);
    predictor->setErrorActivationType(CrossEntropyError);

    vector<string> data, testData;
    int cnt = 0, testCnt = 0;
    loadEvaluatorChessData("evaluator/train", data, cnt);
    loadEvaluatorChessData("evaluator/test", testData, testCnt);

    float alpha = 0.0001;
    while (true) {
        std::cout << "what do you want?\n1)train\n2)new alpha\n3)save\n4)load\n";
        int op;
        std::cin >> op;
        switch (op) {
            case (1): {
                std::cout << "enter n: ";
                int n;
                std::cin >> n;
                long double error = 0, correct = 0, movesCnt = 0;
                for (int q = 1; q <= n; q++) {
                    const int N = 2500, TEST_COUNT = 500;
//                    if(q > 0 && q % N == 0){
                    if (q % N == 0) {

                        const string fileName = "../predictor_statictics.txt";
                        ofstream out(fileName, ios::out | ios::app);
                        long double correct = 0, all = 0;
                        for (int i = 0; i < TEST_COUNT; i++) {
                            int ind = doRandomInt(0, testCnt - 1);

                            Board board;
                            bool isWhite = true;
                            vector<string> tempData;
                            int winner;
                            evaluatorGameToMoves(testData[ind], tempData, winner);
                            for (string s: tempData) {
                                float *x = board.extendedEncodeBoard();
                                float *y = predictor->predict(x);
                                string tempMove = s;
                                if (!isWhite)
                                    tempMove = Board::reverseUci(s);
                                if (getMaxIndex(y, 4184) == Board::uciToNumber(tempMove))
                                    correct++;
                                all++;
                                board.move(s);
                                isWhite = !isWhite;
                                delete[] x;
                                delete[] y;
                            }
                        }
                        out << correct / all << ' ';
                        correct = 0, all = 0;
                        for (int i = 0; i < TEST_COUNT; i++) {
                            int ind = doRandomInt(0, cnt - 1);

                            Board board;
                            bool isWhite = true;
                            vector<string> tempData;
                            int winner;
                            evaluatorGameToMoves(data[ind], tempData, winner);
                            for (string s: tempData) {
                                float *x = board.extendedEncodeBoard();
                                float *y = predictor->predict(x);
                                string tempMove = s;
                                if (!isWhite)
                                    tempMove = Board::reverseUci(s);
                                if (getMaxIndex(y, 4184) == Board::uciToNumber(tempMove))
                                    correct++;
                                all++;
                                board.move(s);
                                isWhite = !isWhite;
                                delete[] x;
                                delete[] y;
                            }
                        }
                        out << correct / all << '\n';
                        out.close();
                    }
                    int i = doRandomInt(0, cnt - 1);
                    Board board;
                    bool isWhite = true;
                    vector<string> tempData;
                    int winner;
                    evaluatorGameToMoves(data[i], tempData, winner);

                    for (int j = 0; j < tempData.size(); j++) {
                        string move = tempData[j];
                        if (!isWhite)
                            move = Board::reverseUci(move);
                        int num = Board::uciToNumber(move);
                        float *x = board.extendedEncodeBoard();
                        float *y = new float[4184];
                        for (int i = 0; i < 4184; i++)
                            y[i] = 0.0f;
                        y[num] = 1.0f;
                        pair<float, bool> res = predictor->train(x, y, alpha);
                        error += res.first;
                        correct += res.second;
                        movesCnt++;
                        delete[] x;
                        delete[] y;
                        board.move(tempData[j]);
                        isWhite = !isWhite;
                    }
                    if ((q * 100) / n > ((q - 1) * 100) / n) {
                        std::cout << (q * 100) / n << " %\n";
                    }
                }
                std::cout << "error: " << error / movesCnt << " correct: " << correct / movesCnt << '\n';
                break;
            }
            case (2): {
                std::cout << "enter new alpha: ";
                std::cin >> alpha;
                break;
            }
            case (3): {
                predictor->save("predictor.txt");
                break;
            }
            case (4): {
                predictor->load("predictor.txt");
                break;
            }

        }
    }
}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    mainwindow *mw = new mainwindow();
    mw->show();

    return QApplication::exec();
    //    mnist_network();
//    mnist_network();
//    newestEvaluator();
//    predictor();
//    evaluator();
    std::cout << fixed << setprecision(10);
    int cnt = 0, cntTest = 0;
    vector<string> data;
    loadChessData("train", data, cnt);
    vector<string> testData;
    loadChessData("test", testData, cntTest);


    vector<int> sizes0(4);
    sizes0[0] = 1;
    sizes0[1] = 1;
    sizes0[2] = 1;
    sizes0[3] = 64;
    BaseNeuralNetwork *neuralFrom;
    BaseNeuralNetwork *neuralPredictor = new GPUNeuralNetwork(sizes0);
    neuralFrom = new GPUNeuralNetwork(sizes0);
    vector<ActivationType> types0(4);
    types0[0] = ActivationType::Nothing;
    for (int i = 1; i < 4; i++)
        types0[i] = ActivationType::LRelu;
    types0[3] = ActivationType::SoftMax;
    neuralFrom->setActivationType(types0);
    vector<int> sizes(4);
    sizes[0] = 1;
    sizes[1] = 1;
    sizes[2] = 5;
    sizes[3] = 64;
    vector<ActivationType> types(4);
    types[0] = ActivationType::Nothing;
    for (int i = 1; i < 4; i++)
        types[i] = ActivationType::LRelu;
    types[3] = ActivationType::SoftMax;
    ActivationType errorType = ActivationType::CrossEntropyError;
    neuralFrom->setErrorActivationType(errorType);

    vector<BaseNeuralNetwork *> neuralTo(64);
    for (int i = 0; i < 64; i++) {
        neuralTo[i] = new GPUNeuralNetwork(sizes);
        neuralTo[i]->setActivationType(types);
        neuralTo[i]->setErrorActivationType(errorType);
    }

    BaseNeuralNetwork *evaluator = new GPUNeuralNetwork(sizes0);
    evaluator->setActivationType(types0);
    evaluator->setErrorActivationType(ActivationType::CrossEntropyError);

    float alpha = 0.00033;
    while (true) {
        std::cout
                << "what do you want?\n1)train\n2)new alpha\n3)save\n4)load\n5)play\n6)test\n7)test engine\n8)play with engine\n";
        int op;
        std::cin >> op;
        switch (op) {
            case (1): {
                std::cout << "enter n: ";
                int n;
                std::cin >> n;
                int movesCnt = 0;
                float error1 = 0, error2 = 0, correct1 = 0, correct2 = 0;
                for (int q = 0; q < n; q++) {
                    int i = doRandomInt(0, cnt - 1);
                    Board board;
                    bool isWhite = true;
                    vector<string> tempData;
                    gameToMoves(data[i], tempData);

                    for (int j = 0; j < tempData.size(); j++) {
                        string move = tempData[j];
                        if (!isWhite)
                            move = Board::reverseUci(move);
                        string part1 = move.substr(0, 2), part2 = move.substr(2, 2);
                        int part1Num = Board::partUciPartToPartInt(part1);
                        if (!isWhite)
                            move = Board::reverseUci(move);

                        auto y1 = new float[64];
                        auto y2 = new float[64];

                        for (int k = 0; k < 64; k++) {
                            y1[k] = 0;
                            y2[k] = 0;
                        }

                        auto x1 = board.extendedEncodeBoard();
                        auto x2 = board.extendedEncodeBoard();
                        y1[Board::partUciPartToPartInt(part1)] = 1;
                        y2[Board::partUciPartToPartInt(part2)] = 1;

                        pair<float, bool> res1 = neuralFrom->train(x1, y1, alpha);
                        pair<float, bool> res2 = neuralTo[part1Num]->train(x2, y2, alpha);

                        error1 += res1.first;
                        error2 += res2.first;
                        if (res1.second)
                            correct1 += 1;
                        if (res2.second)
                            correct2 += 1;

                        movesCnt++;
                        board.move(move);
                        isWhite = !isWhite;
                        delete[] x1;
                        delete[] x2;
                        delete[] y1;
                        delete[] y2;
                    }
                    if ((q * 100) / n > ((q - 1) * 100) / n) {
                        std::cout << (q * 100) / n << " %\n";
                    }
                }
                std::cout << "error1: " << error1 / movesCnt << " correct1: " << correct1 / movesCnt << '\n';
                std::cout << "error2: " << error2 / movesCnt << " correct2: " << correct2 / movesCnt << '\n';
                break;
            }
            case (2): {
                std::cout << "enter new alpha: ";
                std::cin >> alpha;
                break;
            }
            case (3): {
//                evaluator->save("evaluator.txt");
                break;
            }
            case (4): {
                neuralPredictor->load("predictor.txt");
                evaluator->load("evaluator.txt");
                break;
            }
            case (5): {
                std::cout << "bot white(1), black(0)";
                bool isWhite;
                std::cin >> isWhite;
                Board board;
                while (true) {
                    if (!isWhite) {
                        board.printBoard();
                        string yourUci;
                        float *chances = evaluator->predict(board.extendedEncodeBoard());
                        std::cout << "your chances: " << chances[0] << '\n';
                        std::cout << "enter your uci(stop if you want to stop): ";
                        std::cin >> yourUci;
                        if (yourUci == "stop")
                            break;
                        board.move(yourUci);
                        board.printBoard();
                        float *result1 = neuralFrom->predict(board.encodeBoard());
                        float **results = new float *[64];
                        for (int i = 0; i < 64; i++) {
                            results[i] = neuralTo[i]->predict(board.encodeBoard());
                        }
                        while (true) {
                            int mxInd1 = getMaxIndex(result1, 64);
                            int mxInd2 = getMaxIndex(results[mxInd1], 64);
                            string resUci = Board::partNumToPartUci(mxInd1) + Board::partNumToPartUci(mxInd2);
                            resUci = Board::reverseUci(resUci);
                            result1[mxInd1] *= 0.5;
                            results[mxInd1][mxInd2] = 0;

                            float *chances = evaluator->predict(board.extendedEncodeBoard());
                            std::cout << "bot chances: " << chances[0] << '\n';
                            std::cout << resUci << '\n';
                            std::cout << "is it correct?(1/0)\n";
                            bool isCorrect;
                            std::cin >> isCorrect;
                            if (isCorrect) {
                                board.move(resUci);
                                break;
                            }
                        }
                    } else {
                        board.printBoard();
                        float *result1 = neuralFrom->predict(board.extendedEncodeBoard());
                        float **results = new float *[64];
                        for (int i = 0; i < 64; i++) {
                            results[i] = neuralTo[i]->predict(board.encodeBoard());
                        }
                        while (true) {
                            int mxInd1 = getMaxIndex(result1, 64);
                            int mxInd2 = getMaxIndex(results[mxInd1], 64);
                            string resUci = Board::partNumToPartUci(mxInd1) + Board::partNumToPartUci(mxInd2);

                            result1[mxInd1] *= 0.5;
                            results[mxInd1][mxInd2] = 0;

                            float *chances = evaluator->predict(board.encodeBoard());
                            std::cout << "bot chances: " << chances[0] << '\n';
                            std::cout << resUci << '\n';

                            std::cout << "is it correct?(1/0)\n";
                            bool isCorrect;
                            std::cin >> isCorrect;
                            if (isCorrect) {
                                board.move(resUci);
                                break;
                            }
                        }
                        board.printBoard();
                        string yourUci;

                        float *chances = evaluator->predict(board.encodeBoard());
                        std::cout << "your chances: " << chances[0] << '\n';

                        std::cout << "enter your uci(stop if you want to stop): ";
                        std::cin >> yourUci;
                        if (yourUci == "stop")
                            break;
                        board.move(yourUci);
                    }
                }
                break;
            }
            case (6): {
                std::cout << "enter n: ";
                int n;
                std::cin >> n;
                const int MOVES = 100, UNDER = 1000, MAX_FIGURE_MOVES = 2;
                vector<float> statictics(MOVES, 0);
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    vector<string> tempData;
                    gameToMoves(data[i], tempData);
                    Board board;

                    bool isWhite = true;
                    for (int j = 0; j < tempData.size(); j++) {
                        vector<int> result1Cnt(64, 0);
                        float *x = board.extendedEncodeBoard();
                        float *result1 = neuralFrom->predict(x);
                        auto results = new float *[64];
                        for (int k = 0; k < 64; k++) {
                            results[k] = neuralTo[k]->predict(x);
                        }
                        int inStatictics = 0;
                        for (int k = 0; k < UNDER; k++) {
                            if (inStatictics >= MOVES)
                                break;
                            int mxInd1 = getMaxIndex(result1, 64);
                            if (result1Cnt[mxInd1] > MAX_FIGURE_MOVES) {
                                result1[mxInd1] = 0;
                                continue;
                            }
                            int mxInd2 = getMaxIndex(results[mxInd1], 64);
                            string resUci = Board::partNumToPartUci(mxInd1) + Board::partNumToPartUci(mxInd2);
                            if (!isWhite)
                                resUci = Board::reverseUci(resUci);
                            result1[mxInd1] *= 0.5;
                            results[mxInd1][mxInd2] = 0;
                            result1Cnt[mxInd1]++;
                            if (board.isPossibleMove(resUci))
                                inStatictics++;
                            else
                                continue;

                            if (resUci[0] == tempData[j][0] && resUci[1] == tempData[j][1] &&
                                resUci[2] == tempData[j][2] && resUci[3] == tempData[j][3]) {
                                statictics[inStatictics - 1]++;
                            }
                        }
                        isWhite = !isWhite;

                        board.move(tempData[j]);
                        cnt++;
                        for (int k = 0; k < 64; k++) {
                            delete[] results[k];
                        }
                        delete[] results;
                        delete[] result1;
                        delete[] x;
                    }
                    if ((i * 100) / n > ((i - 1) * 100) / n) {
                        std::cout << (i * 100) / n << " %\n";
                    }
                }

                std::cout << "result\n";
                for (int i = 1; i < MOVES; i++) {
                    statictics[i] += statictics[i - 1];
                }
                for (int i = 0; i < MOVES; i++) {
                    statictics[i] /= cnt;
                }
                for (int i = 0; i < MOVES; i++) {
                    std::cout << i + 1 << ") " << statictics[i] << '\n';
                }
                std::cout << '\n';
                break;
            }
            case (7): {
                MinimaxMovePredictor *predictor = new NeuralMinimaxMovePredictor(neuralPredictor, evaluator);
                std::cout << "enter n: ";
                int n;
                std::cin >> n;
                float result = 0;
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    vector<string> tempData;
                    gameToMoves(data[i], tempData);
                    Board board;

                    for (int j = 0; j < tempData.size(); j++) {
                        std::cout << "move: " << j << '\n';

                        std::string move = predictor->predictMove(board);

                        if (move[0] == tempData[j][0] && move[1] == tempData[j][1] && move[2] == tempData[j][2] &&
                            move[3] == tempData[j][3]) {
                            result++;
                            std::cout << tempData[j] << ' ' << move << '\n';
                            std::cout << "true\n";
                        } else {
                            std::cout << tempData[j] << ' ' << move << '\n';
                            std::cout << "false\n";
                        }

                        board.move(tempData[j]);
                        cnt++;
                    }
                    if ((i * 100) / n > ((i - 1) * 100) / n) {
                        std::cout << (i * 100) / n << " %\n";
                    }
                }

                std::cout << "result\n";
                std::cout << result / cnt << '\n';
                std::cout << '\n';
                break;
            }
            case (8): {
                int ind = 1;
                MinimaxMovePredictor *predictor = new NeuralMinimaxMovePredictor(neuralPredictor, evaluator);
                std::cout << "bot white(1), black(0)";
                bool isWhite;
                std::cin >> isWhite;
                Board board;
                while (true) {
                    ind++;
                    if (!isWhite) {
                        board.printBoard();
                        string yourUci;
                        float *chances = evaluator->predict(board.extendedEncodeBoard());
                        std::cout << "your chances: " << chances[0] << '\n';
                        std::cout << "enter your uci(stop if you want to stop): ";
                        std::cin >> yourUci;
                        if (yourUci == "stop")
                            break;
                        board.move(yourUci);
                        board.printBoard();

                        std::string resUci = predictor->predictMove(board, 2, 0.000f / ind / ind);
                        cout << "moves: " << resUci << '\n';
                        board.move(resUci);
                    } else {
                        board.printBoard();

                        std::string resUci = predictor->predictMove(board, 2, 0.000f / ind / ind);
                        cout << "moves: " << resUci << '\n';
                        board.move(resUci);
                        board.printBoard();
                        string yourUci;
                        float *chances = evaluator->predict(board.extendedEncodeBoard());
                        std::cout << "your chances: " << chances[0] << '\n';
                        std::cout << "enter your uci(stop if you want to stop): ";
                        std::cin >> yourUci;
                        if (yourUci == "stop")
                            break;
                        board.move(yourUci);
                    }
                }
                break;
            }
        }
    }
}
