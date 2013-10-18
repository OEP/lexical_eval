#include "util.hpp"

int main() {
  do_integral_batch("0xFF", 0xFF);
  do_integral_batch("-1", -1);
  do_integral_batch("1", 1);
  do_integral_batch("0", 0);
  do_integral_batch("0777", 0777);
}
