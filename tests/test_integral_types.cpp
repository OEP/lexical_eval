#include <lexical_eval.hpp>
#include "util.hpp"

int main() {
  assert_equal(lexical_eval<unsigned long>("0xFF"), static_cast<unsigned long>(0xFF));
  assert_equal(lexical_eval<unsigned int>("0xFF"), static_cast<unsigned int>(0xFF));
  assert_equal(lexical_eval<unsigned char>("0xFF"), static_cast<unsigned char>(0xFF));
  assert_equal(lexical_eval<long>("0xFF"), static_cast<long>(0xFF));
  assert_equal(lexical_eval<int>("0xFF"), static_cast<int>(0xFF));
  assert_equal(lexical_eval<char>("0xFF"), static_cast<char>(0xFF));
}
