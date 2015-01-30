GTEST_DIR ?= gtest
override CXXFLAGS += -g -std=c++0x -I$(GTEST_DIR)/include/ -Iinclude/ -Wall -Wextra
override LDFLAGS += -L$(BUILD)/gtest
override LDLIBS += -lgtest_main -lgtest -pthread

BUILD = build
TEST_DIR = tests
TEST_CPPS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TEST_CPPS:.cpp=.o)
TEST_BIN = lexical_eval_test

all: $(TEST_BIN)

clean:
	rm -rf $(TEST_BIN) $(TEST_OBJS) $(BUILD)

debug:
	echo $(GTEST_DIR)

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_OBJS): $(BUILD)/gtest

$(TEST_BIN): $(TEST_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(BUILD)/gtest: $(GTEST_DIR)
	mkdir -p $@
	cd $@ && cmake $(abspath $<)
	cd $@ && make

$(GTEST_DIR):
	@echo "Google Test not found at $(GTEST_DIR)."
	@echo "Set GTEST_DIR to the path to the Google Test source."
	@exit 1

