#include "order_book.h"
#include <cassert>
#include <iostream>
#include <string>

void test_single_bid_ask() {
    OrderBook ob;
    ob.add_bid(100.0, 10);
    ob.add_ask(101.0, 5);
    
    assert(ob.best_bid() == 100.0);
    assert(ob.best_ask() == 101.0);
    assert(ob.spread() == 1.0);
    
    std::cout << "test_single_bid_ask PASSED\n";
}

void test_multiple_bids() {
    OrderBook ob;
    ob.add_bid(100.0, 10);
    ob.add_bid(105.0, 5);
    ob.add_bid(102.0, 8);
    
    // Best bid should be highest price
    assert(ob.best_bid() == 105.0);
    
    std::cout << "test_multiple_bids PASSED\n";
}

void test_multiple_asks() {
    OrderBook ob;
    ob.add_ask(101.0, 5);
    ob.add_ask(100.0, 10);
    ob.add_ask(103.0, 3);
    
    // Best ask should be lowest price
    assert(ob.best_ask() == 100.0);
    
    std::cout << "test_multiple_asks PASSED\n";
}

void test_spread_calculation() {
    OrderBook ob;
    ob.add_bid(99.0, 10);
    ob.add_bid(100.0, 15);
    ob.add_bid(101.0, 20);
    ob.add_ask(102.0, 10);
    ob.add_ask(103.0, 5);
    ob.add_ask(104.0, 8);
    
    // Spread = best_ask - best_bid = 102 - 101 = 1
    assert(ob.best_bid() == 101.0);
    assert(ob.best_ask() == 102.0);
    assert(ob.spread() == 1.0);
    
    std::cout << "test_spread_calculation PASSED\n";
}

void test_empty_order_book() {
    OrderBook ob;
    
    try {
        ob.best_bid();
        assert(false && "Should have thrown");
    } catch (const std::runtime_error&) {
        // Expected
    }
    
    try {
        ob.best_ask();
        assert(false && "Should have thrown");
    } catch (const std::runtime_error&) {
        // Expected
    }
    
    assert(ob.empty());
    
    std::cout << "test_empty_order_book PASSED\n";
}

int main() {
    test_single_bid_ask();
    test_multiple_bids();
    test_multiple_asks();
    test_spread_calculation();
    test_empty_order_book();
    
    std::cout << "\nAll tests PASSED!\n";
    return 0;
}
