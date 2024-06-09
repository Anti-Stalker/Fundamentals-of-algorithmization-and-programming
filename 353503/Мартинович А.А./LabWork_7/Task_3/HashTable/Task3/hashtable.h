#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "stack.h"
#include "memory"

template <typename T>
class HashTable
{

protected:

    struct Node {
        long _key;
        T _value;
        Node *_next;

        Node (long key, T value, Node* next) : _key(key), _value(value), _next(next) {}
    };

    const double RESIZE_FACTOR = 0.7;
    Node **_nodes;
    size_t _size;
    size_t _count;

    long long _hash_a;
    long long _hash_b;

    const long UNIHASH_P = 65519;


    size_t hash(long key) {
        return key % _size;
        //return ((_hash_a * key + _hash_b) % UNIHASH_P) % _size;
    }

    void init(size_t size) {
        _count = 0;
        _size = size;
        _nodes = new Node* [_size];
        for (int i = 0; i < _size; i ++) {
            _nodes[i] = nullptr;
        }
    }

    void resize() {
        HashTable temp_table(_size*2);
        for (int i = 0; i < _size; i++) {
            Node *temp = _nodes[i];
            while (temp != nullptr) {
                temp_table.insert(temp->_key, temp->_value);
                temp = temp->_next;
            }
        }

        clear();
        init(temp_table._size);

        for (int i = 0; i < _size; i++) {
            Node *temp = temp_table._nodes[i];
            while (temp != nullptr) {
                insert(temp->_key, temp->_value);
                temp = temp->_next;
            }
        }
        _count = temp_table._count;

    }

    void fronAnother(const HashTable &another) {

        _hash_a = another._hash_a;
        _hash_b = another._hash_b;
        _size = another._size;
        _nodes = new Node *[_size];
        _count = 0;


        for (int i = 0; i < _size; i++) {
            Node *temp = another._nodes[i];
            while (temp != nullptr) {
                insert(temp->_key, temp->_value);
            }
        }
    }

public:

    HashTable(size_t size) {
        _hash_a = (rand() % (UNIHASH_P - 1) + 1);
        _hash_b = rand() % UNIHASH_P;
        init(size);

    }

    HashTable(const HashTable &another) {
        fromAnother(another);
    }

    HashTable &operator=(const HashTable &another) {
        clear();
        delete[] _nodes;
        fronAnother(another);
        return *this;
    }

    HashTable(HashTable &&another) {
        _size = another.size;
        _hash_a = another._hash_a;
        _hash_b = another._hash_b;

        another.init(_size);
    }

    HashTable operator=(HashTable &&other) {
        if (&other != this) {
            fromAnother(other);
        }
    }

    void clear() {
        for (int i = 0; i < _size; i++) {
            Node *node = _nodes[i];
            while (node != nullptr) {
                Node *next = node->_next;
                delete node;
                node = next;
            }
            _nodes[i] = nullptr;
        }

        _count = 0;
    }

    ~HashTable() {
        clear();
        delete[] _nodes;
    }

    void insert(long key, const T &value) {
        if ((double)_count/_size > RESIZE_FACTOR) {
            resize();
        }

        size_t index = hash(key);

        // one element in cell
        if (_nodes[index] == nullptr) {
            _nodes[index] = new Node(key, value, nullptr);
            _count++;
            return;
        }
        if (_nodes[index]->_key == key) {
            _nodes[index]->_value = value;
            return;
        }

        // more than one element in cell
        Node *temp = _nodes[index];
        while (temp->_next != nullptr) {
            if (temp->_next->_key == key) {
                temp->_value = value;
                return;
            }
            temp = temp->_next;
        }
        temp->_next = new Node(key, value, nullptr);
         _count++;


    }

    bool contains(long key) {
        size_t index = hash(key);
        Node *temp = _nodes[index];
        while (temp != nullptr) {
            if (temp->_key == key) {
                return true;
            }
            temp = temp->_next;
        }
        return false;
    }

    T &get(long key) {
        size_t index = hash(key);
        Node *temp = _nodes[index];
        while (temp != nullptr) {
            if (temp->_key == key) {
                return temp->_value;
            }
            temp = temp->_next;
        }

        throw new std::invalid_argument("Key not found");
    }

    void remove(long key) {
        size_t index = hash(key);

        if (_nodes[index] && _nodes[index]->_key == key) {
            Node *temp_next = _nodes[index]->_next;
            delete _nodes[index];
            _nodes[index] = temp_next;
            return;
        }

        Node *temp = _nodes[index];
        while (temp != nullptr) {
            if (temp->_next && temp->_next->_key == key) {
                Node *temp_next = temp->_next->_next;
                delete temp->_next;
                temp->_next = temp_next;
                return;
            }
            temp = temp->_next;
        }
        _count--;
    }


};

#endif // HASHTABLE_H
