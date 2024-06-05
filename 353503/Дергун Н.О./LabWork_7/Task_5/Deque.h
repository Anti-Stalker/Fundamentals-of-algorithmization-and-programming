#ifndef DEQUE_H
#define DEQUE_H

#include <QVector>
#include <algorithm>

const uint8_t BLOCK_SIZE = 16;
const uint8_t INIT_BLOCK_AMNT = 4;

template <class T>
class Deque {
private:
    //fields
    QVector<T*> _blocks;
    size_t _headBlock;
    size_t _tailBlock;
    uint8_t _headIndex;
    uint8_t _tailIndex;
    size_t _size;

    //resize
    void resize() {
        QVector<T*> newArrs(_blocks.size() * 2 + 1, nullptr);
        size_t newBlockIdx = 0;

        // Copy elements to new blocks
        for (size_t i = 0; i < _size; ++i) {
            size_t absInd = (_headIndex + i) % (_blocks.size() * BLOCK_SIZE);
            size_t blInd = (absInd / BLOCK_SIZE + _headBlock) % _blocks.size();
            size_t elInd = absInd % BLOCK_SIZE;

            if (newArrs[newBlockIdx] == nullptr) {
                newArrs[newBlockIdx] = new T[BLOCK_SIZE];
            }
            newArrs[newBlockIdx][i % BLOCK_SIZE] = _blocks[blInd][elInd];

            if ((i + 1) % BLOCK_SIZE == 0) {
                ++newBlockIdx;
            }
        }

        // Initialize remaining new blocks
        for (size_t i = newBlockIdx + 1; i < newArrs.size(); ++i) {
            if (newArrs[i] == nullptr) {
                newArrs[i] = new T[BLOCK_SIZE];
            }
        }

        _headBlock = 0;
        _tailBlock = newBlockIdx;
        _headIndex = 0;
        _tailIndex = _size % BLOCK_SIZE;
        _blocks = std::move(newArrs);
    }

    //for iterators
    T* getNextBlock(T* block) {
        auto it = std::find(_blocks.begin(), _blocks.end(), block);
        if (it == _blocks.end()) {
            return nullptr;
        }
        size_t pos = std::distance(_blocks.begin(), it);
        if (pos == _blocks.size() - 1) {
            return _blocks.front();
        }
        return _blocks[++pos];
    }

    T* getPrevBlock(T* block) {
        auto it = std::find(_blocks.begin(), _blocks.end(), block);
        if (it == _blocks.end()) {
            return nullptr;
        }
        size_t pos = std::distance(_blocks.begin(), it);
        if (pos == 0) {
            return _blocks.back();
        }
        return _blocks[--pos];
    }

    //init
    template <class TT>
    void initFirst(TT&& value) {
        clear();
        _blocks[_tailBlock][_tailIndex] = std::forward<TT>(value);
        ++_size;
    }

public:
    // constrs/destr
    Deque() : _headIndex(BLOCK_SIZE / 2),
        _tailIndex(BLOCK_SIZE / 2),
        _size(0), _headBlock(0), _tailBlock(0)
    {
        _blocks = QVector<T*>(INIT_BLOCK_AMNT, nullptr);
        for (size_t i = 0; i < _blocks.size(); ++i) {
            _blocks[i] = new T[BLOCK_SIZE];
        }
    }

    ~Deque() {
        for (T* block : _blocks) {
            delete[] block;
        }
    }

    //clear
    void clear() {
        for (T* block : _blocks) {
            delete[] block;
        }
        _blocks.clear();

        _headIndex = BLOCK_SIZE / 2;
        _tailIndex = BLOCK_SIZE / 2;
        _size = 0;
        _headBlock = 0;
        _tailBlock = 0;
        _blocks = QVector<T*>(INIT_BLOCK_AMNT, nullptr);
        for (size_t i = 0; i < _blocks.size(); ++i) {
            _blocks[i] = new T[BLOCK_SIZE];
        }
    }

    //push/pop front/back
    template<class TT>
    void push_back(TT&& value) {
        if (_size == 0) {
            initFirst(std::forward<TT>(value));
            return;
        }

        if (_tailIndex == BLOCK_SIZE - 1) {
            if ((_tailBlock + 1) % _blocks.size() == _headBlock) {
                resize();
            }
            _tailBlock = (_tailBlock + 1) % _blocks.size();
            _tailIndex = 0;
        } else {
            ++_tailIndex;
        }
        _blocks[_tailBlock][_tailIndex] = std::forward<TT>(value);
        ++_size;
    }

    template<class TT>
    void push_front(TT&& value) {
        if (_size == 0) {
            initFirst(std::forward<TT>(value));
            return;
        }

        if (_headIndex == 0) {
            if ((_headBlock == 0 ? _blocks.size() - 1 : _headBlock - 1) == _tailBlock) {
                resize();
            }
            _headBlock = (_headBlock == 0) ? _blocks.size() - 1 : _headBlock - 1;
            _headIndex = BLOCK_SIZE - 1;
        } else {
            --_headIndex;
        }
        _blocks[_headBlock][_headIndex] = std::forward<TT>(value);
        ++_size;
    }

    void pop_back() {
        if (_size == 0) {
            return;
        }

        if (_tailIndex == 0) {
            if (_tailBlock == 0) {
                _tailBlock = _blocks.size() - 1;
            } else {
                --_tailBlock;
            }
            _tailIndex = BLOCK_SIZE - 1;
        } else {
            --_tailIndex;
        }
        --_size;
    }

    void pop_front() {
        if (_size == 0) {
            return;
        }

        if (_headIndex == BLOCK_SIZE - 1) {
            _headBlock = (_headBlock + 1) % _blocks.size();
            _headIndex = 0;
        } else {
            ++_headIndex;
        }
        --_size;
    }

    // front/back access
    T& operator[](size_t index) {
        size_t absInd = (_headIndex + index) % (_blocks.size() * BLOCK_SIZE);
        size_t blInd = (absInd / BLOCK_SIZE + _headBlock) % _blocks.size();
        size_t elInd = absInd % BLOCK_SIZE;
        return _blocks[blInd][elInd];
    }

    T& front() {
        return _blocks[_headBlock][_headIndex];
    }

    T& back() {
        return _blocks[_tailBlock][_tailIndex];
    }

    const T& front() const {
        return _blocks[_headBlock][_headIndex];
    }

    const T& back() const {
        return _blocks[_tailBlock][_tailIndex];
    }

    //iterators
    class Iterator {
    private:
        Deque* _deque;
        T* _block;
        uint8_t _elementIndex;

    public:
        Iterator(Deque* deque, T* block, int elementIndex)
            : _deque(deque), _block(block), _elementIndex(elementIndex) {}

        T& operator*() {
            return _block[_elementIndex];
        }

        Iterator& operator++() {
            if (_elementIndex == BLOCK_SIZE - 1) {
                _block = _deque->getNextBlock(_block);
                _elementIndex = 0;
            } else {
                _elementIndex++;
            }
            return *this;
        }

        const Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        Iterator& operator--() {
            if (_elementIndex == 0) {
                _block = _deque->getPrevBlock(_block);
                _elementIndex = BLOCK_SIZE - 1;
            } else {
                _elementIndex--;
            }
            return *this;
        }

        const Iterator operator--(int) {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const {
            return _block == other._block && _elementIndex == other._elementIndex;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    Iterator begin() {
        return Iterator(this, _blocks[_headBlock], _headIndex);
    }

    Iterator end() {
        return ++Iterator(this, _blocks[_tailBlock], _tailIndex);
    }

    //info
    size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }
};

#endif // DEQUE_H
