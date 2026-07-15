CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

all: test

order_book.o: order_book.cpp order_book.h
	$(CXX) $(CXXFLAGS) -c order_book.cpp -o order_book.o

test: order_book.o test_order_book.cpp
	$(CXX) $(CXXFLAGS) order_book.cpp test_order_book.cpp -o test_order_book
	./test_order_book

clean:
	rm -f *.o test_order_book
