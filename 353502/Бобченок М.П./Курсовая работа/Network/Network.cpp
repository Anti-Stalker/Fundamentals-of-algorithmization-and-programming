//
// Created by u on 23.02.24.
//

#include "Network.h"

void Network::initialize()
{
    a = std::vector<std::vector<float> > (layers.size());
    for (int i = 0; i < a.size(); ++i)
        a[i] = std::vector<float>(layers[i]);

    b = std::vector<std::vector<float> > (layers.size());
    for (int i = 1; i < b.size(); ++i)
        b[i] = std::vector<float> (layers[i]);

    weights = std::vector<std::vector<std::vector<float> > > (layers.size() - 1);
    for (int i = 0; i < weights.size(); ++i)
    {
        weights[i] = std::vector<std::vector<float> > (layers[i]);
        for (int j = 0; j < weights[i].size(); ++j)
            weights[i][j] = std::vector<float> (layers[i + 1]);
    }

    zero(a);
    zero(b);
    rand(weights);

    delta = std::vector<std::vector<float> > (layers.size());
    for (int i = 0; i < delta.size(); ++i)
        delta[i] = std::vector<float>(layers[i]);

    db = std::vector<std::vector<float> > (layers.size());
    for (int i = 1; i < db.size(); ++i)
        db[i] = std::vector<float> (layers[i]);

    dw = std::vector<std::vector<std::vector<float> > > (layers.size() - 1);
    for (int i = 0; i < dw.size(); ++i)
    {
        dw[i] = std::vector<std::vector<float> > (layers[i]);
        for (int j = 0; j < dw[i].size(); ++j)
            dw[i][j] = std::vector<float> (layers[i + 1]);
    }

    zero(delta);
    zero(db);
    zero(dw);

    dropout = std::vector<std::vector<int> > (layers.size());
    for (int i = 0; i < dropout.size(); ++i)
        dropout[i] = std::vector<int>(layers[i]);

    dropoutPercentOfZeros = std::vector<int> (layers.size(), 0);

    if (activateType.size() != layers.size())
        activateType = std::vector<int> (layers.size(), 0);
}

void Network::activate(float &x, int type)
{
    switch(type)
    {
        case 1:
            if (x < 0)
                x *= L_RELU_DOWN_COEF;
            else if (x > 1)
                x *= L_RELU_UP_COEF;
            break;

        case 2:
            x = (float)1 / (1 + expf(-x));
            break;

        case 3:
            break;

        default:
                return;
    }
}

void Network::activate(std::vector<float> &x, int type)
{
    switch(type)
    {
        case 1:
            for (auto &u : x)
            {
                if (u < 0)
                    u *= L_RELU_DOWN_COEF;
                else if (u > 1)
                    u *= L_RELU_UP_COEF;
            }
            break;

        case 2:
            for (auto &u : x)
                u = (float)1 / (1 + expf(-u));
            break;

        case 5:
            float mx;
            mx = x[0];

            for (auto &u : x)
                mx = std::max(mx, u);


            for (auto &u: x)
                u = expf(u - mx);

            float expSum;
            expSum = sum(x);

            for (auto &u: x)
                u /= expSum;
            break;

        default:
            return;
    }
}

void Network::activateDerivative(float &x, float &y, int type)
{
    switch(type)
    {
        case 1:
            if (y < 0)
                x *= L_RELU_DOWN_COEF;
            else if (y > 1)
                x *= L_RELU_UP_COEF;
            break;

        case 2:
            x *= y * (1 - y);
            break;

        case 3:
            break;

        default:
            return;
    }
}

void Network::activateDerivative(std::vector<float> &x, std::vector<float> &y, int type)
{
    switch(type)
    {
        case 1:
            for (int i = 0; i < x.size(); ++i)
            {
                if (y[i] < 0)
                    x[i] *= L_RELU_DOWN_COEF;
                else if (y[i] > 1)
                    x[i] *= L_RELU_UP_COEF;
            }
            break;

        case 2:
            for (int i = 0; i < x.size(); ++i)
                x[i] *= y[i] * (1 - y[i]);
            break;

        case 5:
            for (int j = 0; j < x.size(); ++j)
            {
                if (equal(x[j], 0))
                    continue;
                float tmp = x[j];
                for (int i = 0; i < x.size(); ++i)
                {
                    if (i == j)
                        x[i] = tmp * (1 - y[i]);
                    else
                        x[i] = tmp * -y[i];
                }
                break;
            }
            break;

        default:
            return;
    }
}

void Network::errorDerivative(std::vector<float> &x, std::vector<float> &y, int type)
{
    switch(type)
    {
        case 1:
            for (int i = 0; i < x.size(); ++i)
                x[i] = 2 * (x[i] - y[i]);
            break;

        case 2:
            for (int i = 0; i < x.size(); ++i)
                x[i] = (equal(y[i], 1) ? -1.0f : 0);
            break;

        default:
            break;
    }
}

void Network::propagate()
{
    for (int i = 0; i < a.size() - 1; ++i)
    {
        if (i > 0 && dropoutUsage)
        {
            randTo(dropout[i], dropoutPercentOfZeros[i]);
            mult(a[i], dropout[i]);
            mult(a[i], 1.0f / (1.0f - (float)numOfZeros(dropout[i]) / (float)layers[i]));
        }

        mult(a[i], weights[i], a[i + 1]);
        sum(a[i + 1], b[i + 1]);
        activate(a[i + 1], activateType[i + 1]);
    }
}

void Network::backPropagation(std::vector<float> &y)
{
    zero(delta);
    delta[delta.size() - 1] = a[a.size() - 1];
    errorDerivative(delta[delta.size() - 1], y, errorDerivativeType);

    for (int i = (int)delta.size() - 1; i > 0; i--)
    {
        activateDerivative(delta[i], a[i], activateType[i]);

        if (i < delta.size() - 1 && dropoutUsage)
            mult(delta[i], dropout[i]);

        sum(db[i], delta[i]);

        mult(a[i - 1], delta[i], dw[i - 1]);
        if (i - 1 != 0)
            mult(delta[i], weights[i - 1], delta[i - 1], true);
    }
}

void Network::correct()
{
    minusMult(b, db, alpha / packetSize);
    minusMult(weights, dw, alpha / packetSize);

    zero(db);
    zero(dw);
}

void Network::setAlpha(float _alpha)
{
    this->alpha = _alpha;
}

void Network::setPacketSize(int _packetSize)
{
    this->packetSize = _packetSize;
}

void Network::setDropoutUsage(bool _dropoutUsage)
{
    this->dropoutUsage = _dropoutUsage;
}

void Network::setError(float _error)
{
    this->error = _error;
}

void Network::setLayers(std::vector<int> &_layers)
{
    layers = _layers;
    otupit();
}

void Network::setLayer(int layer, int size)
{
    layers[layer] = size;
    otupit();
}

void Network::setActivateType(std::vector<int> &_activateType)
{
    activateType = _activateType;
}

void Network::setActivateType(int layer, int _activateType)
{
    activateType[layer] = _activateType;
}

void Network::setDropoutPercentOfZeros(std::vector<int> &_dropoutPercentOfZeros)
{
    this->dropoutPercentOfZeros = _dropoutPercentOfZeros;
}

void Network::setDropoutPercentOfZeros(int layer, int percent)
{
    dropoutPercentOfZeros[layer] = percent;
}

void Network::fit(std::vector<float> &start)
{
    zero(a);
    a[0] = start;
}

void Network::printW()
{
    print(weights);
}

void Network::printA()
{
    print(a);
}

void Network::printB()
{
    print(b);
}

int Network::predict(std::vector<float> &start, int num)
{
    std::mt19937_64 rnd;
    rnd.seed(time(nullptr));

    fit(start);

    bool tmpDropoutUsage = dropoutUsage;
    dropoutUsage = false;
    propagate();
    dropoutUsage = tmpDropoutUsage;

    std::vector<std::pair<float, int> > v;
    for (int i = 0; i < a[a.size() - 1].size(); ++i)
        v.emplace_back(a[a.size() - 1][i], i);
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());

    float sum = 0;
    for (int i = 0; i < std::min((int)v.size(), num); ++i)
    {
        sum += v[i].first;
    }

    sum *= 100000;
    auto r = float(rnd() % (int)sum);
    r /= 100000;

    int mx = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].first < r)
            r -= v[i].first;
        else
        {
            mx = v[i].second;
            break;
        }
    }

    return mx;
}

float Network::train(std::vector<float> &start, std::vector<float> &y)
{
//    int st = clock();
//    std::cout << "fit - " << clock() - st << "\n";
//    st = clock();
//    std::cout << "prop - " << clock() - st << "\n";
//    st = clock();
//    std::cout << "back - " << clock() - st << "\n";
//    st = clock();
//    std::cout << "corr - " << clock() - st << "\n\n";
//    st = clock();
    fit(start);
    propagate();
    backPropagation(y);

    t++;
    t %= packetSize;
    if (!t)
    {
        correct();
    }

    float err = 0;
    for (int i = 0; i < y.size(); ++i)
        err += fabs(a[a.size() - 1][i] - y[i]);

    error += err;
    return error;
}

float Network::get(int num)
{
    if (num >= a[a.size() - 1].size())
    {
        std::cout << num << " " << a[a.size() - 1].size() << " NUM > SIZE : Network.cpp/get(int)\n";
        return 0;
    }
    return a[a.size() - 1][num];
}

int Network::getDropoutUsage()
{
    return this->dropoutUsage;
}

int Network::getSize()
{
    return a.size();
}

int Network::getStartSize()
{
    return a[0].size();
}

int Network::getOutputSize()
{
    return a[a.size() - 1].size();
}

void Network::save(const std::string& s)
{
    std::string file = "../src/data/saves/" + s + ".txt";
    std::ofstream fout(file);
    fout << "alpha " << alpha << "\n";

    fout << "packetSize " << packetSize << "\n";

    fout << "errorDerivativeType " << errorDerivativeType << "\n";

    fout << "dropoutUsage " << dropoutUsage << "\n";

    fout << "layers ";
    fout << layers.size() << "\n";
    for (auto &u : layers)
        fout << u << " ";
    fout << "\n";

    fout << "activateType ";
    fout << activateType.size() << "\n";
    for (auto &u : activateType)
        fout << u << " ";
    fout << "\n";

    fout << "dropoutPercentOfZeros ";
    fout << dropoutPercentOfZeros.size() << "\n";
    for (auto &u : dropoutPercentOfZeros)
        fout << u << " ";
    fout << "\n";

    fout << std::setprecision(30) << std::fixed;
    fout << "b \n";
    for (auto &u : b)
    {
        for (auto &o : u)
            fout << o << " ";
        fout << "\n";
    }

    fout << "weights \n";
    for (auto &u : weights)
    {
        for (auto &o : u)
        {
            for (auto &p : o)
                fout << p << " ";
            fout << "\n";
        }
        fout << "\n";
    }

    fout.close();
}

void Network::load(std::string s)
{
    std::string file = "../src/data/saves/" + s + ".txt";
    std::ifstream fin(file);

    if (!fin.is_open())
    {
        std::cout << "\nFile \"" << file << "\" does not exist\n";
        return;
    }


    std::string inputType;
    while (fin >> inputType)
    {
        if (inputType == "alpha")
        {
            float _alpha;
            fin >> _alpha;
            alpha = _alpha;
        }
        else if (inputType == "packetSize")
        {
            int _packetSize;
            fin >> _packetSize;
            packetSize = _packetSize;
        }
        else if (inputType == "errorDerivativeType")
        {
            int _errorDerivativeType;
            fin >> _errorDerivativeType;
            errorDerivativeType = _errorDerivativeType;
        }
        else if (inputType == "dropoutUsage")
        {
            bool _dropoutUsage;
            fin >> _dropoutUsage;
            dropoutUsage = _dropoutUsage;
        }
        else if (inputType == "layers")
        {
            int n;
            fin >> n;
            layers.resize(n);
            for (int i = 0; i < n; ++i)
                fin >> layers[i];

            initialize();
        }
        else if (inputType == "activateType")
        {
            int n;
            fin >> n;
            activateType.resize(n);
            for (int i = 0; i < n; ++i)
                fin >> activateType[i];
        }
        else if (inputType == "dropoutPercentOfZeros")
        {
            int n;
            fin >> n;
            dropoutPercentOfZeros.resize(n);
            for (int i = 0; i < n; ++i)
                fin >> dropoutPercentOfZeros[i];
        }
        else if (inputType == "b")
        {
            for (auto &u : b)
                for (auto &o : u)
                    fin >> o;
        }
        else if (inputType == "weights")
        {
            for (auto &u : weights)
                for (auto &o : u)
                    for (auto &p : o)
                        fin >> p;
        }
    }
}

void Network::otupit()
{
    initialize();
}

Network::Network(std::string s)
{
    std::string file = "../src/data/saves/" + s + ".txt";
    std::ifstream fin(file);

    std::string inputType;
    while (fin >> inputType)
    {
        if (inputType == "alpha")
        {
            float _alpha;
            fin >> _alpha;
            alpha = _alpha;
        }
        else if (inputType == "packetSize")
        {
            int _packetSize;
            fin >> _packetSize;
            packetSize = _packetSize;
        }
        else if (inputType == "dropoutUsage")
        {
            bool _dropoutUsage;
            fin >> _dropoutUsage;
            dropoutUsage = _dropoutUsage;
        }
        else if (inputType == "layers")
        {
            int n;
            fin >> n;
            layers.resize(n);
            for (int i = 0; i < n; ++i)
                fin >> layers[i];

            initialize();
        }
        else if (inputType == "activateType")
        {
            int n;
            fin >> n;
            activateType.resize(n);
            for (int i = 0; i < n; ++i)
                fin >> activateType[i];
        }
        else if (inputType == "b")
        {
            for (auto &u : b)
                for (auto &o : u)
                    fin >> o;
        }
        else if (inputType == "weights")
        {
            for (auto &u : weights)
                for (auto &o : u)
                    for (auto &p : o)
                        fin >> p;
        }
    }
}
