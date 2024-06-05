//
// Created by u on 22.02.24.
//

#include "matrixMath.h"

std::mt19937 rnd;

bool equal(float x, float y)
{
    const float minimal = 1e-9;
    return std::fabs(x - y) < minimal;
}

bool consistsOfZeros(std::vector<float> &a, int numOfZeros)
{
    if (equal(a[0], 0))
        return true;
    else
        return false;
    //TODO Кастыль, переделать
    bool g = true;
    int sz = std::min((int)a.size(), numOfZeros);
    for (int i = 0; i < sz; i++)
        if (!equal(a[i], 0))
        {
            g = false;
            break;
        }

    return g;
}

void create(int n, std::vector<float> &a)
{
    a = std::vector<float> (n, 0);
}

void create(int n, int m, std::vector<std::vector<float> > &a)
{
    a = std::vector<std::vector<float> > (n, std::vector<float> (m, 0));
}

void zero(std::vector<float> &a)
{
    for (auto &u : a)
        u = 0;
}

void zero(std::vector<std::vector<float> > &a)
{
    for (auto &u : a)
        for (auto &o : u)
            o = 0;
}

void zero(std::vector<std::vector<std::vector<float> > > &a)
{
    for (auto &u : a)
        for (auto &o : u)
        {
            if (consistsOfZeros(o))
                continue;

            for (auto &p : o)
                p = 0;
        }
}

void fastZero(std::vector<std::vector<std::vector<float> > > &a, std::vector<std::vector<float> > &b, std::vector<std::vector<float> > &c)
{
    for (int i = 0; i < a.size(); ++i)
    {
        std::vector<int> notZero;

        for (int j = 0; j < c[i + 1].size(); ++j)
            if (!equal(c[i + 1][j], 0))
                notZero.push_back(j);

        for (int j = 0; j < a[i].size(); ++j)
        {
            if (equal(b[i][j], 0))
                continue;

            for (auto &k : notZero)
                a[i][j][k] = 0;
        }
    }
}

void zeroFrom(int n, std::vector<std::vector<float> > &a)
{
    for (int i = n; i < a.size(); ++i)
        for (auto &o : a[i])
            o = 0;
}

void randTo(std::vector<int> &a, int percentOfZeros)
{
    for (auto &u : a)
    {
        int randNumber = rnd() % 100;
        u = (randNumber < percentOfZeros ? 0 : 1);
    }
}

void rand(std::vector<float> &a, int type)
{
    rnd.seed(time(nullptr));
    for (auto &u : a)
    {
        auto randomValue = rnd() + 1;
        u = (float)(rnd() % (randomValue + 1)) / (float)randomValue;

        if (rnd() % 2)
            u *= -1;
    }
}

void rand(std::vector<std::vector<float> > &a, int type)
{
    rnd.seed(time(nullptr));
    for (auto &u : a)
        for (auto &o : u)
        {
            auto randomValue = rnd() + 1;
            o = (float)(rnd() % (randomValue + 1)) / (float)randomValue;

            if (rnd() % 2)
                o *= -1;
        }
}

void rand(std::vector<std::vector<std::vector<float> > > &a, int type)
{
    rnd.seed(time(nullptr));
    for (auto &u : a)
        for (auto &o : u)
            for (auto &p : o)
            {
                auto randomValue = rnd() + 1;
                p = (float)(rnd() % (randomValue + 1)) / (float)randomValue;

                if (rnd() % 2)
                    p *= -1;

                p /= 10;
            }
}

int numOfZeros(std::vector<int> &a)
{
    int res = 0;
    for (auto u : a)
        if (u == 0)
            res++;
    return res;
}

std::pair<int, int> shape(std::vector<std::vector<float> > &a)
{
    if (a.empty())
    {
        std::cout << "Empty\n";
        return {0, 0};
    }
    return {a.size(), a[0].size()};
}

int shape(std::vector<float> &a)
{
    return a.size();
}

void print(std::vector<int> &a)
{
    for (int i = 0; i < 20; ++i) std::cout << "-"; std::cout << "\n";
    for (auto &u : a)
        std::cout << u << " ";
    std::cout << "\n\n";
}

void print(std::vector<float> &a)
{
    for (int i = 0; i < 20; ++i) std::cout << "-"; std::cout << "\n";
    for (auto &u : a)
        std::cout << u << " ";
    std::cout << "\n\n";
}

void print(std::vector<std::vector<float> > &a)
{
    for (int i = 0; i < 20; ++i) std::cout << "-"; std::cout << "\n";
    for (auto &u : a)
    {
        for (auto &o : u)
            std::cout << o << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

void print(std::vector<std::vector<std::vector<float> > > &a)
{
    for (int i = 0; i < 20; ++i) std::cout << "-"; std::cout << "\n";
    for (auto &u : a)
    {
        for (auto &o : u)
        {
            for (auto &p : o)
                std::cout << p << " ";
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void print(int a)
{
    std::cout << a << "\n\n";
}

void print(std::pair<int, int> a)
{
    std::cout << a.first << " " << a.second << "\n\n";
}

void mult(std::vector<float> &a, float x)
{
    for (auto &u : a)
        u *= x;
}

void mult(std::vector<std::vector<float> > &a, float x)
{
    for (auto &u : a)
    {
        for (auto &o : u)
            o *= x;
    }
}

void mult(std::vector<std::vector<std::vector<float> > > &a, float x)
{
    for (auto &u : a)
        for (auto &o : u)
        {
            for (auto &p : o)
                p *= x;
        }
}

void mult(std::vector<float> &a, std::vector<float> &b)
{
    if (a.size() != b.size())
    {
        std::cout << "Разные размеры массивов: mult(vector, vector)\n";
        return;
    }

    for (int i = 0; i < a.size(); ++i)
        a[i] *= b[i];
}

void mult(std::vector<float> &a, std::vector<int> &b)
{
    if (a.size() != b.size())
    {
        std::cout << "Разные размеры массивов: mult(vector, vector)\n";
        return;
    }

    for (int i = 0; i < a.size(); ++i)
    {
        a[i] *= (float)b[i];
    }
}

void mult(std::vector<float> &a, std::vector<float> &b, std::vector<float> &c)
{
    if (a.size() != b.size())
    {
        std::cout << "mult vec, vec, vec\n";
        return;
    }

    for (int i = 0; i < c.size(); ++i)
        c[i] += a[i] * b[i];
}

void mult(std::vector<float> &a, std::vector<float> &b, std::vector<std::vector<float> > &c, bool ZERO)
{
    if (c.size() == a.size() && c[0].size() == b.size())
    {
        if (ZERO)
            zero(c);
    }
    else
        c = std::vector<std::vector<float> > (a.size(), std::vector<float> (b.size(), 0));

    for (int i = 0; i < a.size(); ++i)
    {
        if (equal(a[i], 0))
            continue;
        for (int j = 0; j < b.size(); ++j)
            c[i][j] += a[i] * b[j];
    }
}

void mult(std::vector<float> &a, std::vector<std::vector<float> > &b, std::vector<float> &c, bool T)
{
    if (T)
    {
        if (b.empty() || a.size() != b[0].size())
        {
            std::cout << "Разные размеры массивов: mult(vector, vector<vector>, vector, true)\n";
            return;
        }

        if (c.size() == b.size())
            zero(c);
        else
            c = std::vector<float> (b.size(), 0);

        for (int i = 0; i < b.size(); ++i)
            for (int j = 0; j < a.size(); ++j)
                c[i] += a[j] * b[i][j];

        return;
    }

    if (a.size() != b.size())
    {
        std::cout << "Разные размеры массивов: mult(vector, vector<vector>, vector)\n";
        return;
    }

    if (c.size() == b[0].size())
        zero(c);
    else
        c = std::vector<float> (b[0].size(), 0);

    for (int i = 0; i < a.size(); ++i)
    {
        if (equal(a[i], 0))
            continue;
        for (int j = 0; j < b[0].size(); ++j)
            c[j] += a[i] * b[i][j];
    }
}

void mult(std::vector<std::vector<float> > &a, std::vector<std::vector<float> > &b, std::vector<std::vector<float> > &c)
{
    if (a.empty() || a[0].size() != b.size())
    {
        std::cout << "Разные размеры массивов: mult(vector<vector>, vector<vector>, vector<vector>)\n";
        return;
    }

    if (c.size() == a.size() && c[0].size() == b[0].size())
        zero(c);
    else
        c = std::vector<std::vector<float> > (a.size(), std::vector<float> (b[0].size(), 0));

    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a[0].size(); ++j)
            for (int k = 0; k < b[0].size(); ++k)
                c[i][k] += a[i][j] * b[j][k];

}

float sum(std::vector<float> &a)
{
    float res = 0;
    for (auto &u : a)
        res += u;
    return res;
}

void sum(std::vector<float> &a, float &b)
{
    for (float &u : a)
        u += b;
}


void sum(std::vector<float> &a, std::vector<float> &b)
{
    if (a.size() != b.size())
    {
        std::cout << "Разные размеры массивов: sum(vector, vector)\n";
        return;
    }

    for (int i = 0; i < a.size(); ++i)
        a[i] += b[i];
}

void minus(std::vector<std::vector<float> > &a, std::vector<std::vector<float> > &b)
{
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
            a[i][j] -= b[i][j];
    }
}

void minus(std::vector<std::vector<std::vector<float> > > &a, std::vector<std::vector<std::vector<float> > > &b)
{
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a[i].size(); ++j)
        {
            for (int k = 0; k < a[i][j].size(); ++k)
                a[i][j][k] -= b[i][j][k];
        }
}

void minusMult(std::vector<std::vector<float> > &a, std::vector<std::vector<float> > &b, float x)
{
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a[i].size(); ++j)
            a[i][j] -= b[i][j] * x;
}

void minusMult(std::vector<std::vector<std::vector<float> > > &a, std::vector<std::vector<std::vector<float> > > &b, float x)
{
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a[i].size(); ++j)
        {
            if (consistsOfZeros(b[i][j]))
                continue;

            for (int k = 0; k < a[i][j].size(); ++k)
                a[i][j][k] -= b[i][j][k] * x;
        }
}

void fastMinusMult(std::vector<std::vector<std::vector<float> > > &a, std::vector<std::vector<std::vector<float> > > &b, float x, std::vector<std::vector<float> > &c, std::vector<std::vector<float> > &d)
{
    for (int i = 0; i < a.size(); ++i)
    {
        std::vector<int> notZero;

        for (int j = 0; j < d[i + 1].size(); ++j)
            if (!equal(d[i + 1][j], 0))
                notZero.push_back(j);

        for (int j = 0; j < a[i].size(); ++j)
        {
            if (equal(c[i][j], 0))
                continue;

            for (auto & k : notZero)
                a[i][j][k] -= b[i][j][k] * x;
        }
    }
}