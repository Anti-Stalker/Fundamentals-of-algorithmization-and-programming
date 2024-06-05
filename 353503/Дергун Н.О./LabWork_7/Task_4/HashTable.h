#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QString>
#include <QSet>
#include <QVector>
#include <cmath>
#include <utility>

const float MAX_OCCUPANCY = 0.75f;
const uint8_t INIT_CAPACITY = 31;

template <class T>
class StrHashTable {
public:
    struct ArrElement {
        T value;
        QString key;
        bool bIsFree = true;
    };

private:
    size_t _capacity = INIT_CAPACITY;
    size_t _size = 0;
    bool _bCanResize = false;
    ArrElement* _data = nullptr;
    QSet<size_t> _collisions;
    QVector<QPair<size_t, QString>> _collisionTable;

    size_t hash(const QString& key) const {
        size_t hash_value = 0;
        for (auto c : key) {
            hash_value += c.unicode();
        }
        return hash_value % _capacity;
    }

    bool doResize() const {
        return static_cast<float>(_size) / _capacity > MAX_OCCUPANCY;
    }

    void resize() {
        size_t twoPow = std::log(_capacity) / std::log(2) + 1;
        _capacity = std::pow(2, ++twoPow) - 1;
        ArrElement* formerArr = _data;
        _data = new ArrElement[_capacity];
        _size = 0;
        _collisionTable.clear();
        _collisions.clear();
        for (size_t i = 0; i < _capacity; ++i) {
            _data[i].bIsFree = true;
        }
        for (size_t i = 0; i < _capacity; ++i) {
            if (!formerArr[i].bIsFree) {
                add(std::move(formerArr[i].key), std::move(formerArr[i].value));
            }
        }
        delete[] formerArr;
    }

    template<class AE>
    void add(AE&& kv) {
        emplace(kv.key, std::forward<T>(kv.value));
    }

public:
    explicit StrHashTable(size_t capacity = INIT_CAPACITY) : _capacity(capacity) {
        _data = new ArrElement[_capacity];
    }

    ~StrHashTable() {
        delete[] _data;
    }

    StrHashTable(const StrHashTable& other) :
        _capacity(other._capacity),
        _size(other._size),
        _bCanResize(other._bCanResize)
    {
        _data = new ArrElement[_capacity];
        for (size_t i = 0; i < _capacity; ++i) {
            _data[i] = other._data[i];
        }
    }

    StrHashTable& operator=(const StrHashTable& other) {
        if (this == &other) {
            return *this;
        }
        delete[] _data;
        _capacity = other._capacity;
        _size = other._size;
        _bCanResize = other._bCanResize;
        _data = new ArrElement[_capacity];
        for (size_t i = 0; i < _capacity; ++i) {
            _data[i] = other._data[i];
        }
        return *this;
    }

    StrHashTable(StrHashTable&& other) noexcept :
        _capacity(other._capacity), _size(other._size),
        _bCanResize(other._bCanResize), _data(other._data)
    {
        other._data = nullptr;
        other._size = 0;
        other._capacity = 0;
    }

    StrHashTable& operator=(StrHashTable&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete[] _data;
        _capacity = other._capacity;
        _size = other._size;
        _bCanResize = other._bCanResize;
        _data = other._data;
        other._data = nullptr;
        other._size = 0;
        other._capacity = 0;
        return *this;
    }



    template <class TT>
    void add(const QString& key, TT&& value) {
        emplace(key, std::forward<TT>(value));
    }

    template <class ... Args>
    void emplace(const QString& key, Args&& ... args) {
        if (_bCanResize && doResize()) {
            resize();
        }

        size_t index = hash(key);
        if (!_data[index].bIsFree && _data[index].key != key) { // looking for a free spot
            if (!_collisions.contains(hash(key))) {
                _collisions.insert(hash(key));
                _collisionTable.emplaceBack(hash(key), key);
                _collisionTable.emplaceBack(hash(_data[index].key), _data[index].key);
            }

            do {
                index = (index + 1) % _capacity;
            } while (!_data[index].bIsFree && _data[index].key != key && index != hash(key));
            if (index == hash(key)) {
                return;
            }
        }

        _data[index] = {T(std::forward<Args>(args)...), key, false};
        ++_size;
    }



    T* get(const QString& key) {
        size_t index = hash(key);
        if (_data[index].key != key) { // looking for the key
            do {
                index = (index + 1) % _capacity;
            } while (_data[index].key != key && index != hash(key));
            if (index == hash(key)) {
                return nullptr;
            }
        }
        return &_data[index].value;
    }

    const T* get(const QString& key) const {
        size_t index = hash(key);
        if (_data[index].key != key) { // looking for the key
            do {
                index = (index + 1) % _capacity;
            } while (_data[index].key != key && index != hash(key));
            if (index == hash(key)) {
                return nullptr;
            }
        }
        return &_data[index].value;
    }



    void erase(const QString& key) {
        size_t index = hash(key);
        if (_data[index].key != key) { // looking for the key
            do {
                index = (index + 1) % _capacity;
            } while (_data[index].key != key && index != hash(key));
            if (index == hash(key)) {
                return;
            }
        }
        _data[index].bIsFree = true;
        --_size;
    }

    void clear() {
        delete[] _data;
        _data = new ArrElement[_capacity];
        _size = 0;
    }



    const QVector<QPair<size_t, QString>>& collisions() {
        return _collisionTable;
    }

    size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }



    bool CanResize() const {
        return _bCanResize;
    }

    void setCanResize(bool newBCanResize) {
        _bCanResize = newBCanResize;
    }


};

#endif // HASHTABLE_H
