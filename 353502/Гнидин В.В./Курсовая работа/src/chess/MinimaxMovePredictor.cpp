//
// Created by volodya-petarda on 4/6/24.
//

#include "MinimaxMovePredictor.h"
std::map<unsigned long long, float> used;

std::vector<std::string> MinimaxMovePredictor::getMoves(Board board) {
    std::vector<std::string> moves;
    for(int i = 0; i < 64 * 64; i++){
        if(board.isPossibleMove(Board::numberToUci(i)))
            moves.push_back(Board::numberToUci(i));
    }
    return moves;
}

float MinimaxMovePredictor::evaluateBoard(Board board) {
    int** field = board.getField();
    bool isWhiteMove = board.getIsWhiteMove();
    int P = 100, N = 320, B = 330, R = 500, Q = 900, K = 20000;
    int pawns[]{ 0,  0,  0,  0,  0,  0,  0,  0,
                 50, 50, 50, 50, 50, 50, 50, 50,
                 10, 10, 20, 30, 30, 20, 10, 10,
                 5,  5, 10, 25, 25, 10,  5,  5,
                 0,  0,  0, 20, 20,  0,  0,  0,
                 5, -5,-10,  0,  0,-10, -5,  5,
                 5, 10, 10,-20,-20, 10, 10,  5,
                 0,  0,  0,  0,  0,  0,  0,  0};
    int knights[]{-50,-40,-30,-30,-30,-30,-40,-50,
                  -40,-20,  0,  0,  0,  0,-20,-40,
                  -30,  0, 10, 15, 15, 10,  0,-30,
                  -30,  5, 15, 20, 20, 15,  5,-30,
                  -30,  0, 15, 20, 20, 15,  0,-30,
                  -30,  5, 10, 15, 15, 10,  5,-30,
                  -40,-20,  0,  5,  5,  0,-20,-40,
                  -50,-40,-30,-30,-30,-30,-40,-50,};
    int bishops[]{
            -20,-10,-10,-10,-10,-10,-10,-20,
            -10,  0,  0,  0,  0,  0,  0,-10,
            -10,  0,  5, 10, 10,  5,  0,-10,
            -10,  5,  5, 10, 10,  5,  5,-10,
            -10,  0, 10, 10, 10, 10,  0,-10,
            -10, 10, 10, 10, 10, 10, 10,-10,
            -10,  5,  0,  0,  0,  0,  5,-10,
            -20,-10,-10,-10,-10,-10,-10,-20,};
    int rooks[]{0,  0,  0,  0,  0,  0,  0,  0,
                5, 10, 10, 10, 10, 10, 10,  5,
                -5,  0,  0,  0,  0,  0,  0, -5,
                -5,  0,  0,  0,  0,  0,  0, -5,
                -5,  0,  0,  0,  0,  0,  0, -5,
                -5,  0,  0,  0,  0,  0,  0, -5,
                -5,  0,  0,  0,  0,  0,  0, -5,
                0,  0,  0,  5,  5,  0,  0,  0};
    int queen[]{
            -20,-10,-10, -5, -5,-10,-10,-20,
            -10,  0,  0,  0,  0,  0,  0,-10,
            -10,  0,  5,  5,  5,  5,  0,-10,
            -5,  0,  5,  5,  5,  5,  0, -5,
            0,  0,  5,  5,  5,  5,  0, -5,
            -10,  5,  5,  5,  5,  5,  0,-10,
            -10,  0,  5,  0,  0,  0,  0,-10,
            -20,-10,-10, -5, -5,-10,-10,-20};
    int king[]{-30,-40,-40,-50,-50,-40,-40,-30,
               -30,-40,-40,-50,-50,-40,-40,-30,
               -30,-40,-40,-50,-50,-40,-40,-30,
               -30,-40,-40,-50,-50,-40,-40,-30,
               -20,-30,-30,-40,-40,-30,-30,-20,
               -10,-20,-20,-20,-20,-20,-20,-10,
               20, 20,  0,  0,  0,  0, 20, 20,
               20, 30, 10,  0,  0, 10, 30, 20};
    float score1 = 0, score2 = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(field[i][j] == 1) {
                score1 += pawns[i * 8 + j];
                score1 += P;
            }
            if(field[i][j] == 2) {
                score1 += rooks[i * 8 + j];
                score1 += R;
            }
            if(field[i][j] == 3) {
                score1 += bishops[i * 8 + j];
                score1 += B;
            }
            if(field[i][j] == 4) {
                score1 += knights[i * 8 + j];
                score1 += N;
            }
            if(field[i][j] == 5) {
                score1 += queen[i * 8 + j];
                score1 += Q;
            }
            if(field[i][j] == 6)
                score1 += king[i * 8 + j];
                score1 += K;

            if(field[i][j] == 7) {
                score2 += pawns[(7 - i) * 8 + (7 - j)];
                score2 += P;
            }
            if(field[i][j] == 8){
                score2 += rooks[(7 - i) * 8 + (7 - j)];
                score2 += R;
            }
            if(field[i][j] == 9) {
                score2 += bishops[(7 - i) * 8 + (7 - j)];
                score2 += B;
            }
            if(field[i][j] == 10) {
                score2 += knights[(7 - i) * 8 + (7 - j)];
                score2 += N;
            }
            if(field[i][j] == 11) {
                score2 += queen[(7 - i) * 8 + (7 - j)];
                score2 += Q;
            }
            if(field[i][j] == 12) {
                score2 += king[(7 - i) * 8 + (7 - j)];
                score2 += K;
            }
        }
    }
    if(isWhiteMove)
        return score1 - score2;
    if(!isWhiteMove)
        return score2 - score1;
}


float MinimaxMovePredictor::maxi(float alpha, float beta, Board board, int depth, float prior) {
    int isEnd = board.isEnd();
    if(isEnd == 1)
        return 10 * depth;
    if(isEnd == 2)
        return -10 * depth;
    if(isEnd == 3)
        return 0.5;

    unsigned long long hash = board.hashBoard();
    if(used.find(hash) != used.end())
        return used[hash];
    if(depth == 0) {
        float ev = evaluateBoard(board);
        float p = std::min(ev, 1.0f - ev) * prior;
        return ev + p;
    }

    float mx = -1e18;
    std::vector<std::string> moves = getMoves(board);
//    const float MOVE_PRIORITY = 0.00001f * depth;
    const float MOVE_PRIORITY = 0.0f;
    for(int i = 0; i < moves.size(); i++){
        std::string m = moves[i];
        Board nboard(board);
        nboard.move(m);
        float val = mini(alpha, beta, nboard, depth - 1, prior - i * MOVE_PRIORITY);
        mx = std::max(mx, val);
        alpha = std::max(alpha, mx);
        if(beta <= alpha)
            break;
    }
    used[hash] = mx;
    return mx;
}


float MinimaxMovePredictor::mini(float alpha, float beta, Board board, int depth, float prior) {
    int isEnd = board.isEnd();
    if(isEnd == 1)
        return 10 * depth;
    if(isEnd == 2)
        return -10 * depth;
    if(isEnd == 3)
        return 0.5;

    unsigned long long hash = board.hashBoard();
    if(used.find(hash) != used.end())
        return used[hash];
    if(depth == 0) {
        float ev = evaluateBoard(board);
        float p = std::min(ev, 1.0f - ev) * prior;
        return ev + p;
    }

    float mn = 1e18;

    std::vector<std::string> moves = getMoves(board);
//    const float MOVE_PRIORITY = 0.00001f * depth;
    const float MOVE_PRIORITY = 0.0f;
    for(int i = 0; i < moves.size(); i++){
        std::string m = moves[i];
        Board nboard(board);
        nboard.move(m);
        float val = maxi(alpha, beta, nboard, depth - 1, prior + i * MOVE_PRIORITY);
        mn = std::min(mn, val);
        beta = std::min(beta, mn);
        if(beta <= alpha)
            break;
    }
    used[hash] = mn;
    return mn;
}

std::string MinimaxMovePredictor::predictMove(Board board, int DEPTH, float priority) {
    used.clear();
    std::cout<<"here depth "<<DEPTH<<'\n';
    auto start = clock();
    bool isWhite = board.getIsWhiteMove();
    std::vector<std::string> moves = getMoves(board);
    int ind = 0;
    float mx;
//    const float MOVE_PRIORITY = 0.005f;
    const float MOVE_PRIORITY = priority;
    if(isWhite){
        mx = -1e36;
        for(int i = 0; i < moves.size(); i++){
            Board nboard(board);
            std::string m = moves[i];
            nboard.move(m);
            float val = mini(mx, 1e36, nboard, DEPTH, -i * MOVE_PRIORITY);
//            val += (moves.size() - i) * MOVE_PRIORITY;
            std::cout<<m<<": "<<val<<'\n';
            if(i == 0 || val > mx){
                mx = val;
                ind = i;
            }
        }
    }
    else{
        mx = 1e36;
        for(int i = 0; i < moves.size(); i++){
            Board nboard(board);
            std::string m = moves[i];
            nboard.move(m);
            float val = maxi(-1e36, mx, nboard, DEPTH, i * MOVE_PRIORITY);
//            val -= (moves.size() - i) * MOVE_PRIORITY;
//            std::cout<<m<<": "<<val<<'\n';
            if(i == 0 || val < mx){
                mx = val;
                ind = i;
            }
        }
    }
    auto finish = clock();
    if(finish - start < 1.0f * CLOCKS_PER_SEC)
        return predictMove(board, DEPTH + 1, priority);
    return moves[ind];
}
