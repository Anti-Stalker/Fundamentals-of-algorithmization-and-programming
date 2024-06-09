#ifndef UNORDEREDMAP_H
#define UNORDEREDMAP_H
#include <cstddef>
#include <cstdint>
#include <stdexcept>

template <typename T>
class UnorderedMap
{
public:
    UnorderedMap(size_t size) {
        init(size);
    }

    UnorderedMap(const UnorderedMap& another) {
        fromAnother(another);
    }

    UnorderedMap &operator=(const UnorderedMap& another) {
        clear();
        delete [] _values;
        delete [] _keys;

        fromAnother(another);
        return *this;
    }

    UnorderedMap (UnorderedMap &&another) {
        _size = another._size;
        _collisions = another._collisions;
        _values = another._values;
        _keys = another._keys;

        another.init();
    }

    ~UnorderedMap() {
        clear();
        delete [] (size_t *)_values;
        delete []  _keys;
    }

    void insert (long key, T value) {
        size_t index = hash(key);
        size_t lim = _size;
        while(_keys[index].taken) {
            if (_keys[index].key == key) {
                break;
            }

            _collisions++;

            lim--;
            if (lim <= 0) {
                return;
            }

            index++;
            if (index >= _size) {
                index %= _size;
            }
        }

        _keys[index].key = key;
        _keys[index].taken = true;
        new (_values+index) T(value);
    }

    bool contains(long key) {
        size_t index = hash(key);
        size_t lim = _size;
        while(_keys[index].taken) {
            if (_keys[index].key == key) {
                return true;
            }

            lim--;
            if (lim <= 0) {
                return false;
            }

            index++;
            if (index >= _size) {
                index %= _size;
            }
        }
    }

    T& get(long key) {
        size_t index = hash(key);
        size_t lim = _size;
        while(_keys[index].taken) {
            if (_keys[index].key == key) {
                return _values[index];
            }

            lim--;
            if (lim <= 0) {
                break;
            }

            index++;
            if (index >= _size) {
                index %= _size;
            }
        }

        throw std::runtime_error("invalid key");
    }

    void clear () {
        for (int i = 0; i < _size; i++) {
            if (_keys[i].taken) {
                _keys[i].taken = false;
                _values[i].~T();
            }
        }
    }

    size_t getCollisionCount(bool reset = false) {
       int ret = _collisions;
       if(reset) _collisions = 0;
       return ret;
     }

    void remove(long key) {
        size_t index = hash(key);
        size_t lim = _size;
        while(_keys[index].taken) {
            if (_keys[index].key == key) {
                break;
            }

            lim--;
            if (lim <= 0) {
                return;
            }

            index++;
            if (index >= _size) {
                index %= _size;
            }
        }

        _keys[index].taken = false;
        _values[index].~T();
    }

protected:

    struct Key {
        long key;
        bool taken;
    };

    size_t _size;
    size_t _collisions;
    Key *_keys;
    T *_values;

    void init(size_t size) {
        _size = size;
        _collisions = 0;
        _keys = new Key[_size];
        for (int i = 0; i < _size; i++) {
            _keys[i].taken = false;
        }

        _values = (T*) new int8_t[_size * sizeof(T)];
    }

    void fromAnother(const UnorderedMap& another) {
        _size = another._size;
        _collisions = another._collisions;

        _keys = new Key[_size];
        _values = (T*) new int8_t[_size * sizeof(T)];

        for (int i = 0; i < _size; i++) {
            if (another._keys[i].taken) {
                _keys[i].key = another._keys[i].key;
                _keys[i].taken = true;
                new (_values + i) T(another._values[i]);
            }
            else {
                _keys[i].taken = false;
            }
        }

    }

    size_t hash(long key) {
        return key % _size;
    }



};

#endif // UNORDEREDMAP_H
