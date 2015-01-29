#include <lexical_eval.hpp>
#include <gtest/gtest.h>

/** Compatible with unsigned 8-bit and above types */
#define TEST_UNSIGNED_BATCH(name, type) \
  TEST(name, hex) { \
    ASSERT_EQ(0x10, lexical_eval<type>("0x10")); \
  } \
  TEST(name, zero) { \
    ASSERT_EQ(0, lexical_eval<type>("0")); \
  } \
  TEST(name, positive_one) { \
    ASSERT_EQ(1, lexical_eval<type>("1")); \
  } \
  TEST(name, octal) { \
    ASSERT_EQ(077, lexical_eval<type>("077")); \
  }

/** Compatible with signed 8-bit and above types */
#define TEST_SIGNED_BATCH(name, type) \
  TEST_UNSIGNED_BATCH(name, type) \
  TEST(name, negative_one) { \
    ASSERT_EQ(-1, lexical_eval<type>("-1")); \
  }

TEST_UNSIGNED_BATCH(UnsignedLongTest, unsigned long)
TEST_UNSIGNED_BATCH(UnsignedLongLongTest, unsigned long long)
TEST_UNSIGNED_BATCH(UnsignedIntTest, unsigned int)
TEST_UNSIGNED_BATCH(UnsignedShortTest, unsigned short)
TEST_UNSIGNED_BATCH(UnsignedCharTest, unsigned char)

TEST_SIGNED_BATCH(LongLongTest, long long)
TEST_SIGNED_BATCH(LongTest, long)
TEST_SIGNED_BATCH(IntTest, int)
TEST_SIGNED_BATCH(ShortTest, short)
TEST_SIGNED_BATCH(CharTest, char)
