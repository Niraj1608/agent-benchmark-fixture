CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

all: test

lru.o: lru.cpp lru.h
	$(CXX) $(CXXFLAGS) -c lru.cpp -o lru.o

test: lru.o test_lru.cpp
	$(CXX) $(CXXFLAGS) lru.cpp test_lru.cpp -o test_lru
	./test_lru

clean:
	rm -f *.o test_lru
