CXX = clang++
GTEST_DIR = ../gtest-1.7.0/
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = UnionFindSet_test BigInteger_test BinaryIndexTree_test RMQ_test SegmentTree_test Rational_test MonotonicQueue_test HashTable_test HashHeap_test ExpressionTree_test Treap_test SplayTree_test

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

UnionFindSet.o : UnionFindSet.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

UnionFindSet_test.o : UnionFindSet_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

UnionFindSet_test : UnionFindSet.o UnionFindSet_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@ 

BigInteger.o : BigInteger.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

BigInteger_test.o : BigInteger_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

BigInteger_test : BigInteger.o BigInteger_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

BinaryIndexTree.o : BinaryIndexTree.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

BinaryIndexTree_test.o : BinaryIndexTree_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

BinaryIndexTree_test : BinaryIndexTree.o BinaryIndexTree_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

RMQ.o :	RMQ.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

RMQ_test.o : RMQ_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

RMQ_test : RMQ.o RMQ_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

SegmentTree.o :	SegmentTree.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

SegmentTree_test.o : SegmentTree_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

SegmentTree_test : SegmentTree.o SegmentTree_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

MonotonicQueue.o :	MonotonicQueue.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

MonotonicQueue_test.o : MonotonicQueue_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

MonotonicQueue_test : MonotonicQueue.o MonotonicQueue_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

Rational.o : Rational.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Rational_test.o : Rational_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Rational_test : Rational.o Rational_test.o ../math/GcdLcm.o ../math/ModularArithmetic.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

HashTable.o : HashTable.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

HashTable_test.o : HashTable_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

HashTable_test : HashTable.o HashTable_test.o ../math/GcdLcm.o ../math/ModularArithmetic.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

HashHeap.o : HashHeap.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

HashHeap_test.o : HashHeap_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

HashHeap_test : HashHeap.o HashHeap_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

ExpressionTree.o : ExpressionTree.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

ExpressionTree_test.o : ExpressionTree_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

ExpressionTree_test : ExpressionTree.o ExpressionTree_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

Treap.o : Treap.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Treap_test.o : Treap_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Treap_test : Treap_test.o Treap.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

SplayTree.o : SplayTree.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

SplayTree_test.o : SplayTree_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

SplayTree_test : SplayTree_test.o SplayTree.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

test : $(TESTS)
	./UnionFindSet_test && ./BigInteger_test && ./BinaryIndexTree_test && ./RMQ_test && ./SegmentTree_test && ./Rational_test && ./MonotonicQueue_test && ./HashTable_test && ./HashHeap_test && ./ExpressionTree_test && ./Treap_test && ./SplayTree_test
