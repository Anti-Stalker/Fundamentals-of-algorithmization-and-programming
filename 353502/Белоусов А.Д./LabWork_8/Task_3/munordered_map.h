#ifndef MUNORDERED_MAP_H
#define MUNORDERED_MAP_H

#include <forward_list>
#include <functional>

template<class K, class V, class Hash = std::hash<K>>
class munordered_map
{
public:
    explicit munordered_map(size_t cap)
        : _cap(cap)
        , _data(new std::forward_list<std::pair<K, V>>[cap])
    {}

    bool contains(K key)
    {
        size_t pos = getPos(key);

        for (auto instance : _data[pos]) {
            if (instance.first == key) {
                return true;
            }
        }

        return false;
    }

    V &operator[](K key)
    {
        size_t pos = getPos(key);

        for (auto iter = _data[pos].before_begin(); iter != _data[pos].end(); ++iter) {
            if (iter->first == key) {
                return iter->second;
            }
        }

        _data[pos].push_front(std::pair<K, V>(key, V()));

        return _data[pos].front().second;
    }

    V operator[](K key) const
    {
        size_t pos = getPos(key);

        for (auto iter = _data[pos].before_begin(); iter != _data[pos].end(); ++iter) {
            if (iter->first == key) {
                return iter->second;
            }
        }

        return V();
    }

    void insert(K key, V value) { (*this)[key] = value; }

    void erase(K key)
    {
        size_t pos = getPos(key);

        _data[pos].remove_if([&](std::pair<K, V> instance) { return instance.first == key; });
    }

    void clear()
    {
        delete[] _data;

        _data = new std::forward_list<std::pair<K, V>>[_cap];
    }

    void rehash(size_t new_cap)
    {
        std::forward_list<std::pair<K, V>> *prev_data = _data;
        size_t prev_cap = _cap;

        std::forward_list<std::pair<K, V>> *new_data
            = new std::forward_list<std::pair<K, V>>[new_cap];

        _data = new_data;
        _cap = new_cap;

        for (int iter = 0; iter < prev_cap; ++iter) {
            for (auto instance : prev_data[iter]) {
                (*this)[instance.first] = instance.second;
            }
        }

        delete[] prev_data;
    }

private:
    size_t getPos(K key) { return Hash{}(key) % _cap; }

    std::forward_list<std::pair<K, V>> *_data;
    size_t _cap;
};

#endif // MUNORDERED_MAP_H
