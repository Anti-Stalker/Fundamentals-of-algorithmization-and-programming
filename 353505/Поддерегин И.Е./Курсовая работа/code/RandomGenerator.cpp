#include <RandomGenerator.h>

bool Get()
{
    auto rnd = std::random_device{};
    auto gen = std::mt19937_64{rnd()};
    auto dis = std::uniform_int_distribution<int>{0, 1};
    return dis(gen);
    /*QTime dt(QTime::currentTime());
    return dt.msec()*5%2;*/
}
