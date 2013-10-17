#pragma once
#include <iostream>
#include <sstream>
#include <type_traits>

template <typename T2, typename T1>
inline T2 lexical_eval(const T1& in) {
  T2 out;
  std::stringstream ss;
  ss << in;
  ss >> out;
  return out;
}

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

template <typename T2>
inline T2 lexical_eval(const char* in) {
  return lexical_eval<T2>(std::string(in));
}
