#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <lexical_eval.hpp>

class assertion_error : public std::runtime_error {
public:
  assertion_error(const std::string& s): std::runtime_error(s) {}
};

inline void
throw_exception(const char *file, int line, const std::string& msg) {
  throw assertion_error(std::string(file) + ":" + std::to_string(line) + ": " + msg);
}

template <typename T1>
inline void assert_equal(const T1& actual, const T1& expected) {
  if(actual != expected) {
    throw assertion_error(std::to_string(actual) + " is not equal to " + std::to_string(expected));
  }
}

template <typename T1>
inline void assert_close(const T1& actual, const T1& expected, const T1& delta) {
  if(std::abs(actual-expected) > std::abs(delta)) {
    throw assertion_error(std::to_string(actual) + " is not within " + std::to_string(expected)
      + " +/- " + std::to_string(delta)
    );
  }
}

template <typename T3, typename T1, typename T2>
inline void do_equal_test(const T1& input, const T2& expected) {
  assert_equal(lexical_eval<T3>(input), static_cast<T3>(expected));
}

template <typename T3, typename T1, typename T2>
inline void do_close_test(const T1& input, const T2& expected, const T3& delta) {
  assert_close(lexical_eval<T3>(input), static_cast<T3>(expected), delta);
}

template <typename T1, typename T2>
inline void do_integral_batch(const T1& input, const T2& expected) {
  do_equal_test<unsigned long>(input, expected);
  do_equal_test<unsigned long long>(input, expected);
  do_equal_test<unsigned int>(input, expected);
  do_equal_test<unsigned short>(input, expected);
  do_equal_test<unsigned char>(input, expected);
  do_equal_test<long long>(input, expected);
  do_equal_test<int>(input, expected);
  do_equal_test<short>(input, expected);
  do_equal_test<char>(input, expected);
}

template <typename T1, typename T2>
inline void do_real_batch(const T1& input, const T2& expected, const T2 delta = static_cast<T2>(1e-6)) {
  do_close_test<long double>(input, expected, delta);
  do_close_test<double>(input, expected, delta);
  do_close_test<float>(input, expected, delta);
}
