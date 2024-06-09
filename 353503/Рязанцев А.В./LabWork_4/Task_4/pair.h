#ifndef PAIR_H
#define PAIR_H

template <typename T, typename U>class Pair
{
public:
    Pair() : first(T()), second(U()){};

    Pair(T ValueA, U ValueB) : first(ValueA), second(ValueB){};

    Pair &operator=(const Pair &el){
        first = el.first;
        second = el.second;

        return *this;
    }

    ~Pair()= default;

    T first;
    U second;
};

#endif // PAIR_H
