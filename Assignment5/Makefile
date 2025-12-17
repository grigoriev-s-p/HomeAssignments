PROJECT = assignment5
LIBPROJECT = $(PROJECT).a
TESTPROJECT = test-$(PROJECT)

CXX = g++
A = ar
AFLAGS = rsv

CCXFLAGS = -I. -std=c++17 -Wall -Werror -Wpedantic -g -fPIC
LDGTESTFLAGS = -lgtest -lgtest_main -lpthread

SRCS = Rational.cpp
TEST_SRCS = Tests.cpp
DEPS = $(wildcard *.h)

OBJ = $(SRCS:.cpp=.o)
TEST_OBJ = $(TEST_SRCS:.cpp=.o)

SOURCES = $(SRCS)
HEADERS = $(wildcard *.h)

.PHONY: default
default: all

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CCXFLAGS)

$(LIBPROJECT): $(OBJ)
	$(A) $(AFLAGS) $@ $^

$(TESTPROJECT): $(LIBPROJECT) $(TEST_OBJ)
	$(CXX) -o $@ $(TEST_OBJ) $(LIBPROJECT) $(LDGTESTFLAGS)

.PHONY: format
format:
	astyle -A1 -s4 $(SOURCES) $(HEADERS)
	rm -f *.orig

test_check: format $(TESTPROJECT)
	./$(TESTPROJECT)

all: format $(TESTPROJECT)

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(LIBPROJECT)
	rm -f $(TESTPROJECT)


