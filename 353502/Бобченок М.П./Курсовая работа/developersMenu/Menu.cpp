//
// Created by u on 27.02.24.
//

#include "Menu.h"

const int sz = 100, kolOfLetters = 10;
const int ERROR_TIMER = 100000;


void parse()
{
    std::ifstream fin(TRAIN);

    std::unordered_map<std::string, int> vocabulary;
    read(VOCABULARY, vocabulary);

    std::unordered_map<int, std::string> indToWord;
    read(VOCABULARY, indToWord);

    std::string word = "";
    while (!fin.eof())
    {
        std::string s;
        std::getline(fin, s);
        word += s + "\n";
    }

    fin.close();

    std::ofstream fout("../src/data/parsed.txt");

    int t = word.size() / 100;
    int cur = t;
    std::deque<std::string> curWords;
    for (int j = 0; j < word.size() - 1; j++)
    {
        if (j == cur)
        {
            std::cout << cur << " " << t << " " << cur / t << "%\n";
            cur += t;
        }
        std::string u = word.substr(j, 1);
        if (!vocabulary.contains(u))
            continue;
        curWords.push_back(u);
        if (curWords.size() < sz)
            continue;

        for (int i = 0; i < sz; i++)
        {
            if (sz - (int)curWords.size() <= i && vocabulary.contains(curWords[i - sz + (int)curWords.size()]))
                fout << vocabulary[curWords[i - sz + (int)curWords.size()]] << " ";
            else
                fout << 0 << " ";
        }

        fout << " " << vocabulary[word.substr(j + 1, 1)] << "\n";

        if (curWords.size() > sz)
            curWords.pop_front();
    }
    fout.close();
}

void poschitatVocabular()
{
    std::unordered_map<std::string, int> mp;
    std::ifstream fin(TRAIN);

    std::string word = "";

    int cur = 0;
    while (!fin.eof())
    {
        cur++;
        std::string s;
        fin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            if ((s.substr(i, 1) < "�" || s.substr(i, 1) > "�") && s.substr(i, 1) != "�")
            {
                if ((word.substr(0, 1) >= "�" && word.substr(0, 1) <= "�") || word.substr(0, 1) == "�" || word.substr(0, 1) == ".")
                    mp[word]++;
//                if (!word.empty() && word[0] != ' ' && !(word[0] >= 'a' && word[0] <= 'z') && !(word[0] >= 'A' && word[0] <= 'Z'))
//                    mp[word]++;
                word = "";
            }
            word += s.substr(i, 1);
            if ((s.substr(i, 1) < "�" || s.substr(i, 1) > "�") && s.substr(i, 1) != "�")
            {
                if ((word.substr(0, 1) >= "�" && word.substr(0, 1) <= "�") || word.substr(0, 1) == "�" || word.substr(0, 1) == ".")
                    mp[word]++;
//                if (!word.empty() && word[0] != ' ' && !(word[0] >= 'a' && word[0] <= 'z') && !(word[0] >= 'A' && word[0] <= 'Z'))
//                    mp[word]++;
                word = "";
            }
        }
        if ((word.substr(0, 1) >= "�" && word.substr(0, 1) <= "�") || word.substr(0, 1) == "�" || word.substr(0, 1) == ".")
            mp[word]++;
        word = "";
    }

    if (!word.empty() && word[0] != ' ')
        mp[word]++;

    std::ofstream fout(VOCABULARY);
    int q = 0;
    std::cout << mp.size() << "\n";
    for (auto &u : mp)
    {
        if (u.second > 0)
            fout << u.first << "\n", q++;
    }
}

void read(std::string s, std::unordered_map<std::string, int> &a)
{
    std::ifstream fin(s);
    a.clear();

    a[" "] = 0;
    a["\n"] = 1;
    for (int i = 2; !fin.eof(); i++)
    {
        std::string word;
        getline(fin, word);
        if (!word.empty())
        {
            a[word] = i;
        }
    }

    fin.close();
}

void read(std::string s, std::unordered_map<int, std::string> &a)
{
    std::ifstream fin(s);
    a.clear();

    a[0] = " ";
    a[1] = "\n";
    for (int i = 2; !fin.eof(); i++)
    {
        std::string word;
        fin >> word;
        a[i] = word;
    }

    fin.close();
}

void read(std::string s, std::string &a)
{
    std::ifstream fin(s);
    a.clear();

    std::getline(fin, a);

    fin.close();
}

void refactor()
{
    std::ifstream fin(TRAIN);

    std :: string s;
    while (!fin.eof())
    {
        std::string r;
        std::getline(fin, r);
        s += r;
        s += "\n";
    }

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == ' ' && s[i  -1] == ' ')
            s.erase(i, 1);
    }

    std::ofstream fout(TRAIN);
    fout << s;
    return ;
    std::string word;

    int cur = 0;
    while (!fin.eof())
    {
        cur++;
        std::string s;
        fin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            if ((s.substr(i, 1) < "�" || s.substr(i, 1) > "�") && s.substr(i, 1) != "�")
            {
                if ((word.substr(0, 1) >= "�" && word.substr(0, 1) <= "�") || word.substr(0, 1) == "�" || word.substr(0, 1) == ".")
                    fout << word << "\n";
//                if (!word.empty() && word[0] != ' ' && !(word[0] >= 'a' && word[0] <= 'z') && !(word[0] >= 'A' && word[0] <= 'Z'))
//                    fout << word << "\bread";
                word = "";
            }
            word += s.substr(i, 1);
            if ((s.substr(i, 1) < "�" || s.substr(i, 1) > "�") && s.substr(i, 1) != "�")
            {
                if ((word.substr(0, 1) >= "�" && word.substr(0, 1) <= "�") || word.substr(0, 1) == "�" || word.substr(0, 1) == ".")
                    fout << word << "\n";
//                if (!word.empty() && word[0] != ' ' && !(word[0] >= 'a' && word[0] <= 'z') && !(word[0] >= 'A' && word[0] <= 'Z'))
//                    fout << word << "\bread";
                word = "";
            }
        }

        if ((word.substr(0, 1) >= "�" && word.substr(0, 1) <= "�") || word.substr(0, 1) == "�" || word.substr(0, 1) == ".")
            fout << word << "\n";
        word = "";
    }
}

void refactorStringToDeque(std::string s, std::deque<std::string> &a)
{
    std::unordered_map<std::string, int> vocabulary;
    read(VOCABULARY, vocabulary);

    std::string word = "";
    for (int i = 0; i < s.size(); i++)
    {
        if ((s.substr(i, 1) < "�" || s.substr(i, 1) > "�") && s.substr(i, 1) != "�")
        {
            if (!word.empty() && word[0] != ' '  && !(word[0] >= 'a' && word[0] <= 'z') && !(word[0] >= 'A' && word[0] <= 'Z'))
                a.push_back(word);
            word = "";
        }
        word += s.substr(i, 1);
        if ((s.substr(i, 1) < "�" || s.substr(i, 1) > "�") && s.substr(i, 1) != "�")
        {
            if (!word.empty() && word[0] != ' '  && !(word[0] >= 'a' && word[0] <= 'z') && !(word[0] >= 'A' && word[0] <= 'Z'))
                a.push_back(word);
            word = "";
        }
    }

    if (!word.empty() && word[0] != ' ')
        a.push_back(word);

    while (a.size() > sz)
        a.pop_front();
}

void otupit(Network &n)
{
    n.otupit();
}

void predict(Network &n, std::string adam, int num, int kol)
{
    std::mt19937_64 rnd(time(nullptr));
    std::unordered_map<std::string, int> vocabulary;
    read(VOCABULARY, vocabulary);

    std::unordered_map<int, std::string> indToWord;
    read(VOCABULARY, indToWord);

    std::ofstream fout(OUTPUT);
    fout << adam;

    std::deque<std::string> curWords;

    while (!adam.empty())
    {
        bool g = false;
        for (int i = (int)adam.size(); i > 0; i--)
        {
            if (vocabulary.contains(adam.substr(0, i)))
            {
                curWords.push_back(adam.substr(0, i));
                g = true;
                adam.erase(0, i);
                break;
            }
        }

        if (!g)
        {
            std::cout << "BAD!!!\n";
            break;
        }
    }


    while (curWords.size() > kol)
        curWords.pop_front();

    int t = 1000;
    std::vector<float> start(vocabulary.size() * sz, 0);
    while (t--)
    {
//        std::vector<float> start(vocabulary.size(), 0);
//        for (auto &s : curWords)
//            start[vocabulary[s]] = 1;

        for (int i = 0; i < sz; i++)
        {
            if (sz - curWords.size() <= i && vocabulary.contains(curWords[i - sz + curWords.size()]))
                start[i * vocabulary.size() + vocabulary[curWords[i - sz + curWords.size()]]] = 1;
        }

        int prediction = n.predict(start, num);
        std::string ans = indToWord[prediction];

        fout << ans;

        for (int i = 0; i < sz; i++)
        {
            if (sz - curWords.size() <= i && vocabulary.contains(curWords[i - sz + curWords.size()]))
                start[i * vocabulary.size() + vocabulary[curWords[i - sz + curWords.size()]]] = 0;
        }

        curWords.push_back(ans);
        while (curWords.size() > kol)
            curWords.pop_front();

        if (ans == " ")
        {
            auto r = float(rnd() % (int)100);
            if (r < 5)
                break;
        }
    }

    fout.close();
}

void testAuto(Network &n)
{
    float error = 0;
    std::mt19937 rnd;
    rnd.seed(time(nullptr));
    std::ifstream fin("../src/data/test.txt");

    std::string s;
    fin >> s;

    int numOfTests;
    fin >> numOfTests;
    for (int num = 0; num < numOfTests; num++)
    {
        int ans;
        fin >> ans;

        std::vector<float> start;
        for (int i = 0; i < 28; i++)
        {
            for (int j = 0; j < 28; j++)
            {
                float x;
                fin >> x;
                start.push_back(x);
            }
        }

        float an = n.predict(start, 10);

        if (ans != an)
            error++;
    }

    std::cout << error / (float)numOfTests;
}

void train(Network &n)
{
    std::mt19937 rnd;
    rnd.seed(time(nullptr));

    std::ifstream trainf;
    trainf.open(TRAIN);
    std::string train;
    while (!trainf.eof())
    {
        std::string tmp;
        std::getline(trainf, tmp);
        train += tmp + "\n";
    }

    std::cout << train.size() << "\n";

    std::unordered_map<std::string, int> vocabulary;
    read(VOCABULARY, vocabulary);

    std::unordered_map<int, std::string> indToWord;
    read(VOCABULARY, indToWord);

    std::cout << vocabulary.size() << "\n";

    std::deque<std::string> curWords;

    std::cout << "\nVvodi kolichestvo testov: ";

    int t;
    std::cin >> t;
    int errorPeriod = 0;
    float guessPercent = 0;
    auto startClock = clock();

    std::vector<float> start(vocabulary.size() * sz, 0);

    while (true)
    {
        curWords.clear();
        long long pos = rnd() % train.size();
        if (train.size() - pos < 100)
            pos -= 1000;

        while (train[pos] != ' ')
            pos++;
        pos++;

        std::string word = train.substr(pos, 150);

        word += "\n";

        while (!word.empty())
        {
            bool g = false;

            int st = clock();

            for (int len = std::min(2, (int)word.size()); len > 0; len--)
            {
                if (vocabulary.contains(word.substr(0, len)))
                {
                    std::string token = word.substr(0, len);

                    for (int i = 0; i < sz; i++)
                    {
                        if (sz - (int)curWords.size() <= i && vocabulary.contains(curWords[i - sz + (int)curWords.size()]))
                            start[i * vocabulary.size() + vocabulary[curWords[i - sz + (int)curWords.size()]]] = 1;
                    }

                    std::vector<float> y(vocabulary.size(), 0);

                    y[vocabulary[token]] = 1;

                    float error = n.train(start, y);

                    int m = 0;
                    for (int i = 0; i < vocabulary.size(); i++)
                        if (n.get(i) > n.get(m))
                            m = i;

                    if (vocabulary[token] == m)
                        guessPercent++;

                    t--;
                    errorPeriod++;
                    errorPeriod %= ERROR_TIMER;
                    if (errorPeriod == 0)
                    {
                        std::vector<float> prediction;
                        for (int i = 0; i < n.getOutputSize(); i++)
                            prediction.push_back(n.get(i));

                        std::cout << "\n\n\nREMAIN - " << t << "\n";
                        std::cout << "TRAIN_ERROR - | " << error / ERROR_TIMER << " |\n";
                        std::cout << "GUESS_PERCENT - | " << guessPercent / ERROR_TIMER << " |\n";
                        std::cout << "TIME - " << (clock() - startClock) / CLOCKS_PER_SEC << "\n\n";

                        for (auto &u : curWords)
                            std::cout << u;
                        std::cout << "\n";

                        std::cout << token << "\n";
                        n.setError(0);
                        for (int i = 0; i < 10; i++) std::cout << "-"; std::cout << "\n";
                        for (int i = 0; i < n.getOutputSize(); i++)
                            if (y[i] == 1)
                                std::cout << y[i] << " " << prediction[i] << "\n";

                        std::cout << indToWord[m] << " " << n.get(m) << "\n";

                        for (int i = 0; i < 10; i++) std::cout << "-"; std::cout << "\n";

                        guessPercent = 0;

                        //n.save("narost");
                    }

                    for (int i = 0; i < sz; i++)
                    {
                        if (sz - (int)curWords.size() <= i && vocabulary.contains(curWords[i - sz + (int)curWords.size()]))
                            start[i * vocabulary.size() + vocabulary[curWords[i - sz + (int)curWords.size()]]] = 0;
                    }

                    curWords.push_back(token);
                    while (curWords.size() > kolOfLetters)
                        curWords.pop_front();

                    g = true;
                    word.erase(0, len);

                    break;
                }
            }

            if (!g)
            {
                word.erase(0, 1);
            }

            if (t <= 0)
                break;
        }

        if (t <= 0)
            break;
    }
}

void setAlpha(Network &n)
{
    std::cout << "Alpha day: ";
    float alpha;
    std::cin >> alpha;

    n.setAlpha(alpha);
}

void setPacketSize(Network &n)
{
    std::cout << "packetSize day: ";
    int packetSize;
    std::cin >> packetSize;

    n.setPacketSize(packetSize);
}

void setLayers(Network &n)
{
    std::cout << "Skolko sloev?(-1 na vihod) ";
    int num;
    std::cin >> num;
    if (num == -1)
        return;

    std::vector<int> layers(num);
    std::cout <<"Vvody, ne jdi\n";
    for (int i = 0; i < num; i++)
        std::cin >> layers[i];

    n.setLayers(layers);
}

void setLayer(Network &n)
{
    std::cout << "NomerSloya(-1 vihod) ";
    int num, size;
    std::cin >> num;
    std::cout << "Razmer: ";
    std::cin >> size;
    n.setLayer(num, size);
}

void setActivation(Network &n)
{
    std::cout << "Kakoy sloy? ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= n.getSize())
        return;

    std::cout << "Vvedite activatiu\n";
    std::cout << "0 - Nothing\n"
                 "1 - Leaky ReLU\n"
                 "2 - Sigmoida\n"
                 "5 - Softmax\n";

    int type;
    std::cin >> type;
    n.setActivateType(num, type);
}

void setActivations(Network &n)
{
    std::cout << "Vvedite " << n.getSize() << " activatiy\n";
    std::cout << "0 - Nothing\n"
                 "1 - Leaky ReLU\n"
                 "2 - Sigmoida\n"
                 "5 - Softmax\n";

    std::vector<int> activatios(n.getSize());
    for (int i = 0; i < n.getSize(); i++)
        std::cin >> activatios[i];

    n.setActivateType(activatios);
}

void outputWeights(Network &n)
{
    n.printW();
}

void outputA(Network &n)
{
    n.printA();
}

void setDropoutUsage(Network &n)
{
    std::cout << "Ispolzovat ili net? (1/0): ";
    bool dropoutUsage;
    std::cin >> dropoutUsage;
    n.setDropoutUsage(dropoutUsage);
}

void setDropoutPercentOfZeros(Network &n)
{
    std::cout << "Vvedite " << n.getSize() << " dropoutov(Ne znau kak nazvat)\n";
    std::vector<int> percent(n.getSize());
    for (int i = 0; i < n.getSize(); i++)
        std::cin >> percent[i];

    n.setDropoutPercentOfZeros(percent);
}

void setDropoutPercentOfZerosOnLayer(Network &n)
{
    std::cout << "Kakoy sloy? ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= n.getSize())
        return;

    std::cout << "Vvedite procent\n";

    int percent;
    std::cin >> percent;
    n.setDropoutPercentOfZeros(num, percent);
}

void makeLayerConvolutional(Network &n)
{
    std::cout << "Kakoy sloy? ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= n.getSize())
        return;

    std::cout << "Vvedite skolko i vo skolko: ";

    int kolFrom, kolTo;
    std::cin >> kolFrom >> kolTo;

}

void fastSave(Network &n)
{
    n.save();
}

void save(Network &n)
{
    std::cout << "Vvedi nazvanie fayla: ";
    std::string s;
    std::cin >> s;

    n.save(s);
}

void load(Network &n)
{
    std::cout << "Otcuda? (fastSave or else): \n";
    std::string s;
    std::cin >> s;

    n.load(s);
}