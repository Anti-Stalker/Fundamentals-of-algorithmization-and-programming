#ifndef DEQUE_H
#define DEQUE_H

#include <vector>
#include <stdexcept>

template<typename T>
class Deque {
private:
    static const size_t BLOCK_SIZE = 8;
    std::vector<T*> blocks;
    size_t beginIndex;
    size_t endIndex;
    size_t dequeSize;

    void allocateBlock() {
        blocks.push_back(new T[BLOCK_SIZE]);
    }

    void deallocateBlocks() {
        for (auto block : blocks) {
            delete[] block;
        }
        blocks.clear();
    }

    std::pair<size_t, size_t> getBlockAndIndex(size_t index) const {
        size_t blockIndex = index / BLOCK_SIZE;
        size_t elementIndex = index % BLOCK_SIZE;
        return { blockIndex, elementIndex };
    }

public:
    Deque() : beginIndex(0), endIndex(0), dequeSize(0) {
        allocateBlock();
    }

    ~Deque() {
        deallocateBlocks();
    }

    void push_back(const T& value) {
        if (endIndex % BLOCK_SIZE == 0 && endIndex != 0) {
            allocateBlock();
        }
        auto [blockIndex, elementIndex] = getBlockAndIndex(endIndex);
        blocks[blockIndex][elementIndex] = value;
        ++endIndex;
        ++dequeSize;
    }

    void push_front(const T& value) {
        if (beginIndex == 0) {
            allocateBlock();
            beginIndex = BLOCK_SIZE;
            endIndex += BLOCK_SIZE;
        }
        --beginIndex;
        auto [blockIndex, elementIndex] = getBlockAndIndex(beginIndex);
        blocks[blockIndex][elementIndex] = value;
        ++dequeSize;
    }

    void pop_back() {
        if (empty()) throw std::out_of_range("Deque is empty");
        --endIndex;
        --dequeSize;
        if (endIndex % BLOCK_SIZE == 0 && endIndex != 0) {
            delete[] blocks.back();
            blocks.pop_back();
        }
    }

    void pop_front() {
        if (empty()) throw std::out_of_range("Deque is empty");
        ++beginIndex;
        --dequeSize;
        if (beginIndex % BLOCK_SIZE == 0 && beginIndex != 0) {
            delete[] blocks.front();
            blocks.erase(blocks.begin());
            beginIndex -= BLOCK_SIZE;
            endIndex -= BLOCK_SIZE;
        }
    }

    void clear() {
        deallocateBlocks();
        allocateBlock();
        beginIndex = 0;
        endIndex = 0;
        dequeSize = 0;
    }

    size_t size() const {
        return dequeSize;
    }

    bool empty() const {
        return dequeSize == 0;
    }

    T& operator[](size_t index) {
        if (index >= dequeSize) throw std::out_of_range("Index out of range");
        auto [blockIndex, elementIndex] = getBlockAndIndex(beginIndex + index);
        return blocks[blockIndex][elementIndex];
    }

    const T& operator[](size_t index) const {
        if (index >= dequeSize) throw std::out_of_range("Index out of range");
        auto [blockIndex, elementIndex] = getBlockAndIndex(beginIndex + index);
        return blocks[blockIndex][elementIndex];
    }
};

#endif // DEQUE_H
