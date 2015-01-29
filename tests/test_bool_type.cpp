#include <lexical_eval.hpp>
#include <gtest/gtest.h>

// False cases
TEST(BoolTest, false_plain) {
  ASSERT_FALSE(lexical_eval<bool>("false"));
}

TEST(BoolTest, false_rspace) {
  ASSERT_FALSE(lexical_eval<bool>("false   "));
}

TEST(BoolTest, false_lspace) {
  ASSERT_FALSE(lexical_eval<bool>("    false"));
}

TEST(BoolTest, false_lrspace) {
  ASSERT_FALSE(lexical_eval<bool>("    false   "));
}

TEST(BoolTest, hex_zero) {
  ASSERT_FALSE(lexical_eval<bool>("0x0"));
}

TEST(BoolTest, hex_zero2) {
  ASSERT_FALSE(lexical_eval<bool>("0x00"));
}

TEST(BoolTest, octal_zero) {
  ASSERT_FALSE(lexical_eval<bool>("00"));
}

TEST(BoolTest, octal_zero2) {
  ASSERT_FALSE(lexical_eval<bool>("000"));
}

TEST(BoolTest, float_zero) {
  ASSERT_FALSE(lexical_eval<bool>("0.0"));
}

TEST(BoolTest, float_zero2) {
  ASSERT_FALSE(lexical_eval<bool>("-0.0"));
}

TEST(BoolTest, float_zero3) {
  ASSERT_FALSE(lexical_eval<bool>("0."));
}

TEST(BoolTest, float_zero4) {
  ASSERT_FALSE(lexical_eval<bool>(".0"));
}

TEST(BoolTest, sci_zero) {
  ASSERT_FALSE(lexical_eval<bool>("0e0"));
}

TEST(BoolTest, sci_zero2) {
  ASSERT_FALSE(lexical_eval<bool>("0e100"));
}

// True cases //

TEST(BoolTest, true_plain) {
  ASSERT_TRUE(lexical_eval<bool>("true"));
}

TEST(BoolTest, true_rspace) {
  ASSERT_TRUE(lexical_eval<bool>("true   "));
}

TEST(BoolTest, true_lspace) {
  ASSERT_TRUE(lexical_eval<bool>("    true"));
}

TEST(BoolTest, true_lrspace) {
  ASSERT_TRUE(lexical_eval<bool>("    true   "));
}

TEST(BoolTest, hex1) {
  ASSERT_TRUE(lexical_eval<bool>("0x1"));
}

TEST(BoolTest, hex2) {
  ASSERT_TRUE(lexical_eval<bool>("0x01"));
}

TEST(BoolTest, octal1) {
  ASSERT_TRUE(lexical_eval<bool>("07"));
}

TEST(BoolTest, octal2) {
  ASSERT_TRUE(lexical_eval<bool>("0777"));
}

TEST(BoolTest, float1) {
  ASSERT_TRUE(lexical_eval<bool>("0.0001"));
}

TEST(BoolTest, float2) {
  ASSERT_TRUE(lexical_eval<bool>("-0.0001"));
}

TEST(BoolTest, float3) {
  ASSERT_TRUE(lexical_eval<bool>("1."));
}

TEST(BoolTest, float4) {
  ASSERT_TRUE(lexical_eval<bool>(".0000001"));
}

TEST(BoolTest, sci1) {
  ASSERT_TRUE(lexical_eval<bool>("1e0"));
}

TEST(BoolTest, sci2) {
  ASSERT_TRUE(lexical_eval<bool>("1.67e100"));
}
