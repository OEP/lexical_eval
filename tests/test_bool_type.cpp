#include "util.hpp"

int main() {
  // false cases
  do_equal_test<bool>("false", false);
  do_equal_test<bool>("false   ", false);
  do_equal_test<bool>("    false", false);
  do_equal_test<bool>("    false   ", false);
  do_equal_test<bool>("0x0", false);
  do_equal_test<bool>("0x00", false);
  do_equal_test<bool>("00", false);
  do_equal_test<bool>("000", false);
  do_equal_test<bool>("0.0", false);
  do_equal_test<bool>("-0.0", false);
  do_equal_test<bool>("0.", false);
  do_equal_test<bool>(".0", false);
  do_equal_test<bool>("0e0", false);
  do_equal_test<bool>("0e100", false);

  // true cases
  do_equal_test<bool>("true", true);
  do_equal_test<bool>("true   ", true);
  do_equal_test<bool>("    true", true);
  do_equal_test<bool>("    true   ", true);
  do_equal_test<bool>("0x1", true);
  do_equal_test<bool>("0x01", true);
  do_equal_test<bool>("07", true);
  do_equal_test<bool>("0777", true);
  do_equal_test<bool>("0.0001", true);
  do_equal_test<bool>("-0.0001", true);
  do_equal_test<bool>("1.", true);
  do_equal_test<bool>(".0000001", true);
  do_equal_test<bool>("1e0", true);
  do_equal_test<bool>("1.67e100", true);
}
