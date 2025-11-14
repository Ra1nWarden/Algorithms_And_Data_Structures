CXX = clang++
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++14

# Include GoogleTest configuration
include ../Makefile.gtest

TESTS = Knapsack_test

all : $(TESTS)

clean :
	rm -f $(TESTS) *.o

Knapsack.o : Knapsack.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Knapsack_test.o : Knapsack.cpp Knapsack_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Knapsack_test.cpp

Knapsack_test : Knapsack.o Knapsack_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

test : $(TESTS)
	./Knapsack_test
