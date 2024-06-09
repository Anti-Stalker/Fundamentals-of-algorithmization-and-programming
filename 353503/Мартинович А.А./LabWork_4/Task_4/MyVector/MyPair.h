#ifndef MYPAIR_H
#define MYPAIR_H

template <typename T1, typename T2>
class Pair{
public:
    T1 first;
    T2 second;

    Pair(): first(T1()), second(T2()) {}
    Pair(T1 f, T2 s): first(f), second(s) {}
};


#endif // MYPAIR_H
