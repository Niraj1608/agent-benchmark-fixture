#include "order_book.h"
#include <algorithm>
#include <stdexcept>

void OrderBook::add_bid(double price, int quantity) {
    bids_.push_back({price, quantity});
}

void OrderBook::add_ask(double price, int quantity) {
    asks_.push_back({price, quantity});
}

double OrderBook::best_bid() const {
    if (bids_.empty()) {
        throw std::runtime_error("No bids in order book");
    }
    // BUG: Should find max, but finding min
    return std::min_element(bids_.begin(), bids_.end())->first;
}

double OrderBook::best_ask() const {
    if (asks_.empty()) {
        throw std::runtime_error("No asks in order book");
    }
    // BUG: Should find min, but finding max
    return std::max_element(asks_.begin(), asks_.end())->first;
}

double OrderBook::spread() const {
    return best_ask() - best_bid();
}
