/*
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2013 Paul Kilgo
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of
 *  this software and associated documentation files (the "Software"), to deal in
 *  the Software without restriction, including without limitation the rights to
 *  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 *  the Software, and to permit persons to whom the Software is furnished to do so,
 *  subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 *  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 *  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 *  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 *  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */ 

#pragma once
#include <iostream>
#include <sstream>
#include <type_traits>

template <typename T2>
inline T2 lexical_eval(const std::string& in) {
  T2 out;
  std::stringstream ss;
  if(std::is_integral<T2>::value) {
    if((in.find("0x") == 0 || in.find("0X") == 0) && in.size() >= 3) {
      ss << std::hex;
    }
    else if(in[0] == '0' && in.size() >= 2) {
      ss << std::oct;
    }
    ss << in;
    ss >> out;
    return out;
  }
  else if(std::is_floating_point<T2>::value) {
    ss << std::scientific << in;
    ss >> out;
    return out;
  }
  ss << in;
  ss >> out;
  return out;
}

template <>
inline bool lexical_eval(const std::string& in) {
  const std::string tok = lexical_eval<std::string>(in);
  if(tok == "true") return true;
  else if(tok == "false") return false;
  const int i = lexical_eval<int>(in);
  const float f = lexical_eval<float>(in);
  return i != 0 || f != 0.0f;
}

template <>
inline char lexical_eval(const std::string& in) {
  return static_cast<char>(lexical_eval<int>(in));
}

template <>
inline unsigned char lexical_eval(const std::string& in) {
  return static_cast<unsigned char>(lexical_eval<unsigned int>(in));
}

template <typename T2>
inline T2 lexical_eval(const char* in) {
  return lexical_eval<T2>(std::string(in));
}
