#ifndef LRU_H
#define LRU_H

#include <unordered_map>
#include <list>
#include <utility>
#include <string>

template<typename K, typename V>
class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}

    // Get value by key, returns true if found
    bool get(const K& key, V& value);

    // Put key-value pair
    void put(const K& key, const V& value);

    // Get size
    int size() const { return static_cast<int>(cache_.size()); }

private:
    int capacity_;
    std::unordered_map<K, std::pair<V, typename std::list<K>::iterator>> cache_;
    std::list<K> recency_;  // Most recent at front

    void evict_lru();
    void touch(const K& key);
};

#endif // LRU_H
