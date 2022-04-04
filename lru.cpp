#include <iostream>
#include <list>
#include <unordered_map>

static const int SIZE = 10;

template <typename K>
class LRUCache {
public:

    LRUCache() {
        cache = std::list<K>{SIZE};
        table = std::unordered_map<K, int>();
    };

    ~LRUCache()=default;

    bool full() const {
        return cache.size() == SIZE;
    }

    void insert(const K val) {
        if (cache.full()) {
            auto tmp = cache.back(); cache.pop_back();
            table.erase(tmp);
        }
        cache.push_front(val);
        table[val]++;
    }

    K get() {
        if (!cache.empt()) {
            auto res = cache.front(); cache.pop_front();
            return res;
        }
        return nullptr;
    }

protected:
    std::list<K> cache;
    std::unordered_map<K, int> table;
};

