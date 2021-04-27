/*
 *  14.2
 *  Write a program which takes as input two sorted arrays of integers, and updates the first
 *    to the combined entries of the two arrays in sorted order. Assume the first array has
 *    enough empty entries at its end to hold the result.
 */

#include <iostream>
#include <vector>

#include <gtest/gtest.h>

int SeekEndInt(const std::vector<int> &v)
{
  for (auto i{0}; i < v.size(); ++i)
    if (v[i] == 0)
      return i - 1;
  return 0;
}

void Merge(std::vector<int> &v1, std::vector<int> &v2)
{
  int i = SeekEndInt(v1);
  int j = v2.size() - 1;
  int end = v1.size() - 1;

  while (i >= 0 && j >= 0)
  {
    if (j < 0 || v1[i - 1] > v2[j] || v1[i] >= v2[j])
    {
      v1[end] = v1[i];
      i--;
      end--;
    }
    else if (i < 0 || v2[j - 1] > v1[i] || v1[i] < v2[j])
    {
      v1[end] = v2[j];
      j--;
      end--;
    }
  }

  while (i >= 0)
    v1[end--] = v1[i--];
  while (j >= 0)
    v1[end--] = v2[j--];

  int shift = end + 1;
  for (auto i{shift}; i < v1.size(); ++i)
  {
    v1[i - shift] = v1[i];
    v1[i] = 0;
  }
}

TEST(MergeTest, UnitTest)
{
  std::vector<int> v1(8);
  v1[0] = 5;
  v1[1] = 13;
  v1[2] = 17;
  std::vector<int> v2{3,7,11,19};
  std::vector<int> result{3,5,7,11,13,17,19,0};
  Merge(v1, v2);
  EXPECT_EQ(result, v1);

  v1 = {100,0,0,0,0,0,0,0,0,0};
  v2 = {1,2,3,4,500};
  result = {1,2,3,4,100,500,0,0,0,0};
  Merge(v1, v2);
  EXPECT_EQ(result, v1);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
