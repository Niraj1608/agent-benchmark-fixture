#include "lru.h"
#include <cassert>
#include <iostream>
#include <string>

void test_basic_get_put() {
    LRUCache<int, int> cache(3);
    
    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);
    
    int value;
    assert(cache.get(1, value) == true);
    assert(value == 100);
    
    std::cout << "test_basic_get_put PASSED\n";
}

void test_eviction() {
    LRUCache<int, int> cache(3);
    
    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);
    cache.put(4, 400);  // Should evict key 1 (least recent)
    
    int value;
    assert(cache.get(1, value) == false);  // Key 1 should be evicted
    assert(cache.get(4, value) == true);
    assert(value == 400);
    assert(cache.get(2, value) == true);
    
    std::cout << "test_eviction PASSED\n";
}

void test_recency_on_get() {
    LRUCache<int, int> cache(3);
    
    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);
    
    // Access key 1, making it most recent
    int value;
    cache.get(1, value);
    
    // Now add key 4, should evict key 2 (not key 1)
    cache.put(4, 400);
    
    assert(cache.get(1, value) == true);  // Key 1 should still exist
    assert(cache.get(2, value) == false); // Key 2 should be evicted
    
    std::cout << "test_recency_on_get PASSED\n";
}

void test_update_existing() {
    LRUCache<int, int> cache(3);
    
    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(1, 150);  // Update key 1
    
    int value;
    cache.get(1, value);
    assert(value == 150);
    
    cache.put(3, 300);
    cache.put(4, 400);  // Should evict key 2 (not key 1)
    
    assert(cache.get(1, value) == true);
    assert(cache.get(2, value) == false);
    
    std::cout << "test_update_existing PASSED\n";
}

int main() {
    test_basic_get_put();
    test_eviction();
    test_recency_on_get();
    test_update_existing();
    
    std::cout << "\nAll tests PASSED!\n";
    return 0;
}
