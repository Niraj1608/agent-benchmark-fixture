#include "lru.h"
#include <string>

template<typename K, typename V>
bool LRUCache<K, V>::get(const K& key, V& value) {
    auto it = cache_.find(key);
    if (it == cache_.end()) {
        return false;
    }
    value = it->second.first;
    // BUG: Should call touch(key) here to mark as recently used!
    return true;
}

template<typename K, typename V>
void LRUCache<K, V>::put(const K& key, const V& value) {
    auto it = cache_.find(key);
    if (it != cache_.end()) {
        // Update existing
        it->second.first = value;
        touch(key);
    } else {
        // Insert new
        if (cache_.size() >= capacity_) {
            evict_lru();
        }
        recency_.push_front(key);
        cache_[key] = {value, recency_.begin()};
    }
}

template<typename K, typename V>
void LRUCache<K, V>::touch(const K& key) {
    recency_.erase(cache_[key].second);
    recency_.push_front(key);
    cache_[key].second = recency_.begin();
}

template<typename K, typename V>
void LRUCache<K, V>::evict_lru() {
    K lru_key = recency_.back();
    recency_.pop_back();
    cache_.erase(lru_key);
}

// Explicit template instantiation
template class LRUCache<int, int>;
template class LRUCache<std::string, std::string>;
