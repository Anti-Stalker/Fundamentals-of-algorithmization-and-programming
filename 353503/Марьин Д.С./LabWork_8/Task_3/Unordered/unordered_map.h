#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H


#include <forward_list>
#include <functional>
#include <stdexcept>
#include <utility>
#include <string>

template <typename KeyType, typename ValueType, typename Hash = std::hash<KeyType>>
class unordered_map
{
public:
    using PairType = std::pair<const KeyType, ValueType>;
    using ChainType = std::forward_list<PairType>;

    unordered_map(size_t bucket_count = 8, const Hash& hash = Hash())
        : buckets(bucket_count), hasher(hash), size(0) {}

    bool contains(const KeyType& key) const
    {
        size_t index = get_bucket_index(key);
        for (const auto& pair : buckets[index])
        {
            if (pair.first == key)
            {
                return true;
            }
        }
        return false;
    }

    ValueType& operator[](const KeyType& key)
    {
        size_t index = get_bucket_index(key);
        for (auto& pair : buckets[index])
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }
        if (size >= buckets.size())
        {
            rehash(buckets.size() * 2);
            index = get_bucket_index(key);
        }
        buckets[index].emplace_front(key, ValueType());
        ++size;
        return buckets[index].front().second;
    }

    const ValueType operator[](const KeyType& key) const
    {
        size_t index = get_bucket_index(key);
        for (const auto& pair : buckets[index])
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }
        return ValueType();
    }

    void insert(const KeyType& key, const ValueType& value)
    {
        size_t index = get_bucket_index(key);
        for (auto& pair : buckets[index])
        {
            if (pair.first == key)
            {
                pair.second = value;
                return;
            }
        }
        if (size >= buckets.size())
        {
            rehash(buckets.size() * 2);
            index = get_bucket_index(key);
        }
        buckets[index].emplace_front(key, value);
        ++size;
    }

    void erase(const KeyType& key)
    {
        size_t index = get_bucket_index(key);
        auto it = buckets[index].before_begin();
        for (auto next_it = buckets[index].begin(); next_it != buckets[index].end(); ++it, ++next_it)
        {
            if (next_it->first == key)
            {
                buckets[index].erase_after(it);
                --size;
                return;
            }
        }
    }

    void clear() {
        for (auto& bucket : buckets)
        {
            bucket.clear();
        }
        size = 0;
    }

    void rehash(size_t new_bucket_count)
    {
        std::vector<ChainType> new_buckets(new_bucket_count);
        for (const auto& bucket : buckets)
        {
            for (const auto& pair : bucket)
            {
                size_t index = pair_hasher(pair.first, new_bucket_count);
                new_buckets[index].emplace_front(pair);
            }
        }
        buckets = std::move(new_buckets);
    }

    std::string toString() const
    {
        std::string res;
        for (const auto& bucket : buckets)
        {
            for (const auto& pair : bucket)
            {
                res += std::to_string(pair.first) + " " + pair.second + "\n";
            }
        }
        return res;
    }

private:
    size_t get_bucket_index(const KeyType& key) const
    {
        return pair_hasher(key, buckets.size());
    }

    size_t pair_hasher(const KeyType& key, size_t bucket_count) const
    {
        return hasher(key) % bucket_count;
    }

    std::vector<ChainType> buckets;
    Hash hasher;
    size_t size;
};


#endif // UNORDERED_MAP_H
