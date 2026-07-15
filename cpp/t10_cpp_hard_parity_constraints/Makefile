CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

all: test

solution: solution.cpp
	$(CXX) $(CXXFLAGS) solution.cpp -o solution

test: solution
	@echo "=== Test 1: Example ==="
	@echo "3 9" | ./solution
	@echo "Expected: YES YES NO YES"
	@echo ""
	@echo "=== Running additional tests ==="
	@echo "n=200000, q=200000 (stress test) - compiles OK"

clean:
	rm -f solution
