#include <lexical_eval.hpp>
#include <gtest/gtest.h>

/* float tests */

TEST(FloatTest, one_is_equal) {
  ASSERT_FLOAT_EQ(1, lexical_eval<float>("1"));
}

TEST(FloatTest, sci_positive) {
  ASSERT_FLOAT_EQ(1e1, lexical_eval<float>("1e1"));
}

TEST(FloatTest, sci_negative) {
  ASSERT_FLOAT_EQ(1e-1, lexical_eval<float>("1e-1"));
}

TEST(FloatTest, decimal_positive) {
  ASSERT_FLOAT_EQ(1.2, lexical_eval<float>("1.2"));
}

TEST(FloatTest, decimal_negative) {
  ASSERT_FLOAT_EQ(-1.2, lexical_eval<float>("-1.2"));
}

TEST(FloatTest, small_decimal_positive) {
  ASSERT_FLOAT_EQ(0.0000001, lexical_eval<float>("0.0000001"));
}

TEST(FloatTest, small_decimal_negative) {
  ASSERT_FLOAT_EQ(-0.0000001, lexical_eval<float>("-0.0000001"));
}

/* double tests */

TEST(DoubleTest, one_is_equal) {
  ASSERT_DOUBLE_EQ(1, lexical_eval<double>("1"));
}

TEST(DoubleTest, sci_positive) {
  ASSERT_DOUBLE_EQ(1e1, lexical_eval<double>("1e1"));
}

TEST(DoubleTest, sci_negative) {
  ASSERT_DOUBLE_EQ(1e-1, lexical_eval<double>("1e-1"));
}

TEST(DoubleTest, decimal_positive) {
  ASSERT_DOUBLE_EQ(1.2, lexical_eval<double>("1.2"));
}

TEST(DoubleTest, decimal_negative) {
  ASSERT_DOUBLE_EQ(-1.2, lexical_eval<double>("-1.2"));
}

TEST(DoubleTest, small_decimal_positive) {
  ASSERT_DOUBLE_EQ(0.0000001, lexical_eval<double>("0.0000001"));
}

TEST(DoubleTest, small_decimal_negative) {
  ASSERT_DOUBLE_EQ(-0.0000001, lexical_eval<double>("-0.0000001"));
}

/* long double tests */

TEST(LongDoubleTest, one_is_equal) {
  ASSERT_DOUBLE_EQ(1, lexical_eval<long double>("1"));
}

TEST(LongDoubleTest, sci_positive) {
  ASSERT_DOUBLE_EQ(1e1, lexical_eval<long double>("1e1"));
}

TEST(LongDoubleTest, sci_negative) {
  ASSERT_DOUBLE_EQ(1e-1, lexical_eval<long double>("1e-1"));
}

TEST(LongDoubleTest, decimal_positive) {
  ASSERT_DOUBLE_EQ(1.2, lexical_eval<long double>("1.2"));
}

TEST(LongDoubleTest, decimal_negative) {
  ASSERT_DOUBLE_EQ(-1.2, lexical_eval<long double>("-1.2"));
}

TEST(LongDoubleTest, small_decimal_positive) {
  ASSERT_DOUBLE_EQ(0.0000001, lexical_eval<long double>("0.0000001"));
}

TEST(LongDoubleTest, small_decimal_negative) {
  ASSERT_DOUBLE_EQ(-0.0000001, lexical_eval<long double>("-0.0000001"));
}
