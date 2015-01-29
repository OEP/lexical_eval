CXXFLAGS = -g -std=c++0x -Iinclude/ -Llib/ -Wall -Wextra
LDLIBS = -lgtest_main -lgtest -pthread

GTEST_HOME = /usr/src/gtest

TEST_DIR = tests
TEST_CPPS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TEST_CPPS:.cpp=.o)
TEST_BIN = lexical_eval_test

all: $(TEST_BIN)

clean:
	rm -rf $(TEST_BIN) $(TEST_OBJS) gtest
 
test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_OBJS)

gtest:
	mkdir -p lib
	cp -a $(GTEST_HOME) gtest
	cd gtest && cmake CMakeLists.txt && make
	cp gtest/*.a lib/
