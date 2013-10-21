lexical_eval
============

Handy C++11 function similar to `lexical_cast` with some added support for
scientific notation, octal, and hexadecimal. The main focus of lexical_eval
is correctly casting std::string objects into C++ fundamental types (like
bool, int, char) according to rules normally honored by the C++ scanner.

Some examples:

* `lexical_eval<int>("3")` = 3
* `lexical_eval<int>("0xFF")` = 255
* `lexical_eval<int>("0777")` = 511

Usage
=====

Copy `include/lexical_eval.hpp` into your include path and just include where
you'd like to use it.

    #include <iostream>
    #include <string>
    #include <lexical_eval.hpp>

    int main() {
      std::string s;
      std::cout << "Enter a number: ";
      std::cin >> s;
      std::cout << "As integer: " << lexical_eval<int>(s) << std::endl;
      std::cout << "As floating point: " << lexical_eval<float>(s) << std::endl;
    }

Notes
=====

* `lexical_eval` assumes you probably would like the numeric data over the
  character data, so calls to it with `std::string` as the source and `char`
  as the target follow this rule, which is not usual for stream semantics.
  There are better ways to extract character data from strings; this is not
  one of them.
* Currently `lexical_eval` is not very safe, as no exceptions are thrown for
  bad inputs, so use judiciously.
