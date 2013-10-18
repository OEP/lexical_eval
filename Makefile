CXXFLAGS = -std=c++11 -Iinclude/ -Wall -Wextra
TEST_DIR = tests
TEST_CPPS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_BINS = $(TEST_CPPS:.cpp=)

all: $(TEST_BINS)

clean:
	rm -rf $(TEST_BINS)

runtests: $(TEST_BINS)
	for x in $(TEST_BINS); do $$x; done
