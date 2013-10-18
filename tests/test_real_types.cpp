#include "util.hpp"

int main() {
  do_real_batch("1", 1);
  do_real_batch("1e1", 1e1);
  do_real_batch("1e-1", 1e-1);
  do_real_batch("1.2", 1.2);
  do_real_batch("0.0000001", 0.0000001);
  do_real_batch("-0.0000001", -0.0000001);
}
