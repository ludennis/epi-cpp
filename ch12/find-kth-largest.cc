/*
 *  12.8
 *  Design an algorithm for computing the kth largest element in an array. Assume entries are
 *    distinct.
 */

#include <vector>

#include <gtest/gtest.h>

int GetKthLargest(std::vector<int> numbers, int k, int left, int right)
{
  // selects a pivot and finds it's kth order by counting how many elements is larger/smaller
  int mid = left + (right - left) / 2;
  int pivot = numbers[mid];

  std::vector<int> lessThan;
  std::vector<int> greaterThan;

  for (auto i{left}; i <= right; ++i)
  {
    if (numbers[i] < pivot)
      lessThan.emplace_back(numbers[i]);
    else if (numbers[i] > pivot)
      greaterThan.emplace_back(numbers[i]);
  }

  if (greaterThan.size() + 1 == k)
    return pivot;
  else if (k <= greaterThan.size())
    return GetKthLargest(greaterThan, k, 0, greaterThan.size() - 1);
  else
    return GetKthLargest(lessThan, k - (greaterThan.size() + 1), 0, lessThan.size() - 1);
}

int GetKthLargest(std::vector<int> &numbers, int k)
{
  if (k > numbers.size())
    return -1;

  return GetKthLargest(numbers, k, 0, numbers.size() - 1);
}

TEST(GetKthLargestTest, UnitTest)
{
  std::vector<int> v{3,2,1,5,4};

  EXPECT_EQ(5, GetKthLargest(v, 1));
  EXPECT_EQ(4, GetKthLargest(v, 2));
  EXPECT_EQ(3, GetKthLargest(v, 3));
  EXPECT_EQ(2, GetKthLargest(v, 4));
  EXPECT_EQ(1, GetKthLargest(v, 5));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
