/*
 *  Write a program which takes as input a very long sequence of numbers and prints the numbers
 *    in sorted order. Each number is at most k away from its correctly sorted position. (Such an
 *    array is sometimes referred to as being k-sorted.) For example, no number in the sequence
 *    (3,-1,2,6,4,5,8) is no more than 2 away from its final sorted position.
 */

#include <queue>
#include <vector>

#include <gtest/gtest.h>

std::vector<int> SortKSortedArray(const std::vector<int> &v, int k)
{
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  std::vector<int> result;
  for (auto &x : v)
  {
    minHeap.emplace(x);
    if (minHeap.size() > k)
    {
      result.emplace_back(minHeap.top());
      minHeap.pop();
    }
  }

  while (!minHeap.empty())
  {
    result.emplace_back(minHeap.top());
    minHeap.pop();
  }

  return result;
}

TEST(SortKSortedArrayTest, UnitTest)
{
  std::vector<int> v{3,-1,2,6,4,5,8};
  std::vector<int> expected{-1,2,3,4,5,6,8};

  EXPECT_EQ(expected, SortKSortedArray(v, 2));
  EXPECT_EQ(expected, SortKSortedArray(v, 3));

  v = std::vector<int>{4,2,8,-1,5,6,3};
  EXPECT_NE(expected, SortKSortedArray(v, 1));
  EXPECT_NE(expected, SortKSortedArray(v, 2));
  EXPECT_NE(expected, SortKSortedArray(v, 3));
  EXPECT_EQ(expected, SortKSortedArray(v, 4));
  EXPECT_EQ(expected, SortKSortedArray(v, 5));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
