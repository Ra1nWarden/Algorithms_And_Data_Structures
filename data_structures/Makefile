CXX = clang++
GTEST_DIR = ../gtest-1.7.0/
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = UnionFindSet_test BigInteger_test

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

UnionFindSet_test.o : UnionFindSet.cpp UnionFindSet_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c UnionFindSet_test.cpp

UnionFindSet_test : UnionFindSet.o UnionFindSet_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@ 

BigInteger.o : BigInteger.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c BigInteger.cpp

BigInteger_test.o : BigInteger_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c BigInteger_test.cpp

BigInteger_test : BigInteger.o BigInteger_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

test : $(TESTS)
	./UnionFindSet_test && ./BigInteger_test
