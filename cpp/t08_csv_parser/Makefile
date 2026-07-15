CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

all: test

csv_parser.o: csv_parser.cpp csv_parser.h
	$(CXX) $(CXXFLAGS) -c csv_parser.cpp -o csv_parser.o

test: csv_parser.o test_csv_parser.cpp
	$(CXX) $(CXXFLAGS) csv_parser.cpp test_csv_parser.cpp -o test_csv_parser
	./test_csv_parser

clean:
	rm -f *.o test_csv_parser
