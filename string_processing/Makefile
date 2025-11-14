CXX = clang++
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++14

# Include GoogleTest configuration
include ../Makefile.gtest

TESTS = Miscellaneous_test SuffixArray_test Trie_test KMP_test AhoCorasickAutomata_test

all : $(TESTS)

clean :
	rm -f $(TESTS) *.o

SuffixArray.o : SuffixArray.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c SuffixArray.cpp

SuffixArray_test.o : SuffixArray_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c SuffixArray_test.cpp

SuffixArray_test : SuffixArray.o SuffixArray_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

Miscellaneous.o : Miscellaneous.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Miscellaneous.cpp

Miscellaneous_test.o : Miscellaneous_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Miscellaneous_test.cpp

Miscellaneous_test : Miscellaneous.o Miscellaneous_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

Trie.o : Trie.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Trie.cpp

Trie_test.o : Trie_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Trie_test.cpp

Trie_test : Trie.o Trie_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

KMP.o : KMP.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c KMP.cpp

KMP_test.o : KMP_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c KMP_test.cpp

KMP_test : KMP.o KMP_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

AhoCorasickAutomata.o : AhoCorasickAutomata.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c AhoCorasickAutomata.cpp

AhoCorasickAutomata_test.o : AhoCorasickAutomata_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c AhoCorasickAutomata_test.cpp

AhoCorasickAutomata_test : AhoCorasickAutomata.o AhoCorasickAutomata_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

test : $(TESTS)
	./Miscellaneous_test && ./SuffixArray_test && ./Trie_test && ./KMP_test && ./AhoCorasickAutomata_test
