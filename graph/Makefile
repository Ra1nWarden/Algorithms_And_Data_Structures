CXX = clang++
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++14

# Include GoogleTest configuration
include ../Makefile.gtest

TESTS = Utility_test MST_test ShortestPath_test MaximumFlow_test

all : $(TESTS)

clean :
	rm -f $(TESTS) *.o

Utility.o : Utility.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Utility.cpp

Utility_test.o : Utility.cpp Utility_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Utility_test.cpp

Utility_test : Utility.o Utility_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

MST.o : MST.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c MST.cpp

MST_test.o : MST.cpp MST_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c MST_test.cpp

MST_test : MST.o MST_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

ShortestPath.o : ShortestPath.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c ShortestPath.cpp

ShortestPath_test.o : ShortestPath.cpp ShortestPath_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c ShortestPath_test.cpp

ShortestPath_test : ShortestPath.o ShortestPath_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

MaximumFlow.o : MaximumFlow.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c MaximumFlow.cpp

MaximumFlow_test.o : MaximumFlow.cpp MaximumFlow_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c MaximumFlow_test.cpp

MaximumFlow_test : MaximumFlow.o MaximumFlow_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

test : $(TESTS)
	./Utility_test && ./MST_test && ./ShortestPath_test && ./MaximumFlow_test
