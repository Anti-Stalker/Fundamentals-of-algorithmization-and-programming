#ifndef LAB4TASK4_PAIR_H
#define LAB4TASK4_PAIR_H

namespace my {
    template<typename T1, typename T2>
    struct Pair {
        T1 first;
        T2 second;

        template<typename T3, typename T4>
        bool operator==(Pair<T3, T4> &other) {
            return (first == other.first) && (second == other.second);
        }

        template<typename T3, typename T4>
        bool operator!=(Pair<T3, T4> &other) {
            return (first != other.first) || (second != other.second);
        }

        template<typename T3, typename T4>
        Pair<T1, T2> &operator=(Pair<T3, T4> &other) {
            return !(other == *this);
        }

        Pair() {}

        Pair(T1 first, T2 second) {
            this->first = first;
            this->second = second;
        }

        Pair(const Pair &other) {
            first = other.first;
            second = other.second;
        }

        Pair &operator=(const Pair &other) {
            Pair<T1, T2> tmp;
            tmp.first = other.first;
            tmp.second = other.second;
            return tmp;
        }


    };
} // namespace my

#endif //LAB4TASK4_PAIR_H
