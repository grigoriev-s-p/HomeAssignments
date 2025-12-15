PROJECT = assignment3
MAIN = main

LIBPROJECT = $(PROJECT).a
TESTPROJECT = test-$(PROJECT)

CXX = g++
A = ar
AFLAGS = rsv

CCXFLAGS = -I. -std=c++17 -Wall -Werror -Wpedantic -g -fPIC
LDXXFLAGS = $(CCXFLAGS) -L. -l:$(LIBPROJECT)
LDGTESTFLAGS = $(LDXXFLAGS) -lgtest -lgtest_main -lpthread

SRCS = Autobot.cpp \
       Desepticon.cpp \
       Engine.cpp \
       Jettroid.cpp \
       Transformer.cpp \
       TransformerModel.cpp

MAIN_SRCS = main.cpp

TEST_SRCS = AutobotTest.cpp \
            DesepticonTest.cpp \
            JettroidTest.cpp \
            TransformerTest.cpp

DEPS = $(wildcard *.h)

OBJ = $(SRCS:.cpp=.o)
MAIN_OBJ = $(MAIN_SRCS:.cpp=.o)
TEST_OBJ = $(TEST_SRCS:.cpp=.o)

.PHONY: default

default: all

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CCXFLAGS)

$(LIBPROJECT): $(OBJ)
	$(A) $(AFLAGS) $@ $^

$(PROJECT): $(MAIN_OBJ) $(LIBPROJECT)
	$(CXX) -o $@ $(MAIN_OBJ) $(LDXXFLAGS)

$(TESTPROJECT): $(LIBPROJECT) $(TEST_OBJ)
	$(CXX) -o $@ $(TEST_OBJ) $(LDGTESTFLAGS)

test_check: $(TESTPROJECT)
	./$(TESTPROJECT)

test: $(PROJECT)
	./$(PROJECT)

all: $(PROJECT)

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(PROJECT)
	rm -f $(LIBPROJECT)
	rm -f $(TESTPROJECT)