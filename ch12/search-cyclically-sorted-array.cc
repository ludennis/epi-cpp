/*
 *  12.3
 *  Design an O(log n) algorithm for finding the position of the smallest element in a cyclically
 *    sorted array. Assume all elements are distinct.
 */

#include <iostream>
#include <vector>

#include <gtest/gtest.h>

int GetSmallestElementPosition(const std::vector<int> &numbers, int left, int right)
{
  if (right - left == 1)
    if (numbers[left] < numbers[right])
      return -1;
    else if (numbers[left] > numbers[right])
      return right;

  int mid = left + (right - left) / 2;

  if (mid >= 1 && numbers[mid] < numbers[mid - 1])
    return mid;

  if (numbers[mid] < numbers[right])
    return GetSmallestElementPosition(numbers, left, mid - 1);
  else
    return GetSmallestElementPosition(numbers, mid, right);
}

int GetSmallestElementPosition(const std::vector<int> &numbers)
{
  if (numbers[0] < numbers.back())
    return 0;

  return GetSmallestElementPosition(numbers, 0, numbers.size() - 1);
}

TEST(GetSmallestElementPositionTest, UnitTest)
{
  std::vector<int> v{631,103,203,220,234,279,368,378,478,550};
  EXPECT_EQ(1, GetSmallestElementPosition(v));

  v = std::vector<int>{103,203,220,234,279,368,378,478,550,631};
  EXPECT_EQ(0, GetSmallestElementPosition(v));

  v = std::vector<int>{368,378,478,550,631,103,203,220,234,279};
  EXPECT_EQ(5, GetSmallestElementPosition(v));

  v = std::vector<int>{203,220,234,279,368,378,478,550,631,103};
  EXPECT_EQ(9, GetSmallestElementPosition(v));

  v = std::vector<int>{220,234,279,368,378,478,550,631,103,203};
  EXPECT_EQ(8, GetSmallestElementPosition(v));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
