#pragma once
#include <iostream>
#include <stdexcept>

class assertion_error : public std::runtime_error {
public:
  assertion_error(const std::string& s): std::runtime_error(s) {}
};

inline void
throw_exception(const char *file, int line, const std::string& msg) {
  throw assertion_error(std::string(file) + ":" + std::to_string(line) + ": " + msg);
}

template <typename T1>
inline void assert_equal(const char *file, int line, const T1& actual, const T1& expected) {
  if(actual != expected) {
    throw_exception(file, line, std::to_string(actual) + " is not equal to " + std::to_string(expected));
  }
}

#define assert_equal(actual, expected) assert_equal(__FILE__, __LINE__, actual, expected)
