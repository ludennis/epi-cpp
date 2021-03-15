/*
 *  12.1
 *  Write a method that takes a sorted array and a key and returns the index of the first occurrence
 *    of that key in the array. For example, when applied to the array
 *    [-14,-10,2,108,108,243,285,285,285,401], your algorithm should return 3 if the given key is
 *    108; if it is 285, your algorithm should return 6.
 */

#include <iostream>
#include <optional>
#include <vector>

#include <gtest/gtest.h>

int SeekFirstOccurrence(const std::vector<int> &sorted, int target, int left, int right)
{
  int mid = left + (right - left) / 2;

  if (mid == 0 && sorted[mid] == target)
    return 0;
  if (mid > 0 && sorted[mid] == target && sorted[mid - 1] != target)
    return mid;

  if (sorted[mid] == target)
    return SeekFirstOccurrence(sorted, target, left, mid - 1);
  else
    return SeekFirstOccurrence(sorted, target, mid + 1, right);
}

int SeekFirstOccurrence(const std::vector<int> &sorted, int target, int targetIndex)
{
  return SeekFirstOccurrence(sorted, target, 0, targetIndex);
}

std::optional<int> BinarySearch(
  const std::vector<int> &sorted, int target, int left, int right)
{
  if (right < left || (left == right && sorted[left] != target))
    return {};

  int mid = left + (right - left) / 2;

  if (sorted[mid] == target)
    return std::optional<int>{mid};
  else if (target < sorted[mid])
    return BinarySearch(sorted, target, left, mid - 1);
  else
    return BinarySearch(sorted, target, mid + 1, right);
}

std::optional<int> BinarySearch(const std::vector<int> &sorted, int target)
{
  return BinarySearch(sorted, target, 0, sorted.size() - 1);
}

std::optional<int> FirstOccurrence(std::vector<int> &sorted, int k)
{
  auto found = BinarySearch(sorted, k, 0, sorted.size() - 1);

  if (found)
    return SeekFirstOccurrence(sorted, k, 0, *found);
  else
    return std::nullopt;
}

TEST(BinarySearchTest, UnitTest)
{
  std::vector<int> v{-14,-10,2,108,108,243,285,285,285,401};

  EXPECT_EQ(4, *BinarySearch(v, 108));
  EXPECT_EQ(5, *BinarySearch(v, 243));
  EXPECT_EQ(7, *BinarySearch(v, 285));
  EXPECT_EQ(9, *BinarySearch(v, 401));
  EXPECT_EQ(std::nullopt, BinarySearch(v, 1));
}

TEST(SeekFirstOccurrenceTest, UnitTest)
{
  std::vector<int> v{1,1,1,1,1,1,1};

  EXPECT_EQ(0, SeekFirstOccurrence(v, 1, 4));
  EXPECT_EQ(0, SeekFirstOccurrence(v, 1, 3));

  v = std::vector<int>{1,1,2,2,2,2,2,2};
  EXPECT_EQ(2, SeekFirstOccurrence(v, 2, 5));
  EXPECT_EQ(2, SeekFirstOccurrence(v, 2, 7));

  v = std::vector<int>{1,2,3,4,5,6,7,8};
  EXPECT_EQ(7, SeekFirstOccurrence(v, 8, 7));
}

TEST(FirstOccurrenceTest, UnitTest)
{
  std::vector<int> v{-14,-10,2,108,108,243,285,285,285,401};

  EXPECT_EQ(0, *FirstOccurrence(v, -14));
  EXPECT_EQ(1, *FirstOccurrence(v, -10));
  EXPECT_EQ(2, *FirstOccurrence(v, 2));
  EXPECT_EQ(3, *FirstOccurrence(v, 108));
  EXPECT_EQ(5, *FirstOccurrence(v, 243));
  EXPECT_EQ(6, *FirstOccurrence(v, 285));
  EXPECT_EQ(9, *FirstOccurrence(v, 401));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
