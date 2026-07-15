#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include <vector>
#include <string>
#include <utility>

class OrderBook {
public:
    OrderBook() = default;
    
    // Add a bid (buy order)
    void add_bid(double price, int quantity);
    
    // Add an ask (sell order)
    void add_ask(double price, int quantity);
    
    // Get the best bid (highest price)
    double best_bid() const;
    
    // Get the best ask (lowest price)
    double best_ask() const;
    
    // Get spread (ask - bid)
    double spread() const;
    
    // Check if empty
    bool empty() const { return bids_.empty() && asks_.empty(); }

private:
    std::vector<std::pair<double, int>> bids_;  // (price, quantity)
    std::vector<std::pair<double, int>> asks_; // (price, quantity)
};

#endif // ORDER_BOOK_H
