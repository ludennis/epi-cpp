/*
 *  12.4
 *  Write a program which takes a nonnegative integer and returns the largest integer whose
 *    squares is less than or equal to the given integer. For example, if the input is 16, return
 *    4; if the input is 300, return 17, since 17^2 = 289 < 300 and 18^2 = 324 > 300.
 */

#include <gtest/gtest.h>

unsigned int GetLargestSquareRoot(unsigned int target, int left, int right)
{
  if (right - left == 1 || right - left == 0)
    return left;

  int mid = left + (right - left) / 2;

  if (mid * mid > target)
    return GetLargestSquareRoot(target, left, mid);
  else
    return GetLargestSquareRoot(target, mid, right);
}

unsigned int GetLargestSquareRoot(unsigned int target)
{
  return GetLargestSquareRoot(target, 0, target);
}

TEST(GetLargestSquareRootTest, UnitTest)
{
  EXPECT_EQ(6, GetLargestSquareRoot(42));
  EXPECT_EQ(7, GetLargestSquareRoot(49));
  EXPECT_EQ(7, GetLargestSquareRoot(50));
  EXPECT_EQ(17, GetLargestSquareRoot(300));
  EXPECT_EQ(4, GetLargestSquareRoot(16));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
