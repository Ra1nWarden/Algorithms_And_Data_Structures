CXX = clang++
GTEST_DIR = ../gtest-1.7.0/
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = Point_test Line_test Triangle_test Sphere_test Polygon_test Circle_test

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

Point.o : Point.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Point_test.o : Point_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Point_test.cpp

Point_test : Point.o Point_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

Line.o : Line.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Line_test.o : Line_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Line_test.cpp

Line_test : Point.o Line.o Line_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

Triangle.o : Triangle.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Triangle_test.o : Triangle_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Triangle_test.cpp

Triangle_test : Point.o Line.o Triangle.o Circle.o Triangle_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

Circle.o : Circle.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Circle_test.o : Circle_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Circle_test.cpp

Circle_test : Point.o Line.o Circle.o Circle_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

Sphere.o : Sphere.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Sphere_test.o : Sphere_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Sphere_test.cpp

Sphere_test : Point.o Line.o Sphere.o Sphere_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

Polygon.o : Polygon.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

Polygon_test.o : Polygon_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Polygon_test.cpp

Polygon_test : Point.o Line.o Polygon.o Polygon_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

test : $(TESTS)
	./Point_test && ./Line_test && ./Triangle_test && ./Sphere_test && ./Polygon_test && ./Circle_test
