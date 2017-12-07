CXX = clang++
GTEST_DIR = ../gtest-1.7.0/
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = Primes_test GcdLcm_test PermutationAndCombination_test Miscellaneous_test ModularArithmetic_test Fibonacci_test

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o 

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

Primes.o : Primes.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Primes.cpp

Primes_test.o : Primes.cpp Primes_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Primes_test.cpp

Primes_test : Primes.o Primes_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

GcdLcm.o : GcdLcm.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c GcdLcm.cpp

GcdLcm_test.o : GcdLcm_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c GcdLcm_test.cpp

GcdLcm_test : GcdLcm.o GcdLcm_test.o ModularArithmetic.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

PermutationAndCombination.o : PermutationAndCombination.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

PermutationAndCombination_test.o : PermutationAndCombination.cpp PermutationAndCombination_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c PermutationAndCombination_test.cpp

PermutationAndCombination_test : PermutationAndCombination.o PermutationAndCombination_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

ModularArithmetic.o : ModularArithmetic.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

ModularArithmetic_test.o : ModularArithmetic_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

ModularArithmetic_test : ModularArithmetic.o ModularArithmetic_test.o GcdLcm.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

Miscellaneous.o : Miscellaneous.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Miscellaneous_test.o : Miscellaneous.cpp Miscellaneous_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Miscellaneous_test.cpp

Miscellaneous_test : Miscellaneous.o Miscellaneous_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

Fibonacci.o : Fibonacci.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Fibonacci_test.o : Fibonacci.cpp Fibonacci_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Fibonacci_test.cpp

Fibonacci_test : Fibonacci.o Fibonacci_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

test : $(TESTS)
	./Primes_test && ./GcdLcm_test && ./PermutationAndCombination_test && ./ModularArithmetic_test && ./Miscellaneous_test && ./Fibonacci_test
