PROJECT = testCheck
EXAMPLE = Example

LIBPROJECT = $(PROJECT).a
TESTPROJECT = test-$(PROJECT)

CXX = g++
A = ar
AFLAGS = rsv

CCXFLAGS = -I. -std=c++17 -Wall -g -fPIC
LDXXFLAGS = $(CCXFLAGS) -L. -l:$(LIBPROJECT)
LDGTESTFLAGS = $(LDXXFLAGS) -lgtest -lgtest_main -lpthread

SRCS = Autobot.cpp \
       Desepticon.cpp \
       Engine.cpp \
       Jettroid.cpp \
       Transformer.cpp \
       TransformerModel.cpp

EXAMPLE_SRCS = Example.cpp

TEST_SRCS = AutobotTest.cpp \
            DesepticonTest.cpp \
            JettroidTest.cpp \
            TransformerTest.cpp

DEPS = $(wildcard *.h)

OBJ = $(SRCS:.cpp=.o)
EXAMPLE_OBJ = $(EXAMPLE_SRCS:.cpp=.o)
TEST_OBJ = $(TEST_SRCS:.cpp=.o)

.PHONY: default

default: all

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CCXFLAGS)

$(LIBPROJECT): $(OBJ)
	$(A) $(AFLAGS) $@ $^

$(PROJECT): $(EXAMPLE_OBJ) $(LIBPROJECT)
	$(CXX) -o $@ $(EXAMPLE_OBJ) $(LDXXFLAGS)

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
