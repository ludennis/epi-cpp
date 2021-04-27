/*
 *  14.1
 *  Write a program which takes as input two sorted arrays, and returns a new array
 *    containing elements that are present in both of the input arrays. The input arrays may
 *    have duplicate entries, but the returned array should be free of duplicates. For example,
 *    the input is [2,3,3,5,5,6,7,7,8,12] and [5,5,6,8,8,9,10,10], your output should be
 *    [5,6,8]
 */

#include <vector>

#include <gtest/gtest.h>

void SeekNextInt(std::vector<int>::const_iterator &itr)
{
  int current = *itr;

  while (*itr == current)
    itr++;
}

std::vector<int> GetIntersection(const std::vector<int> &v1, const std::vector<int> &v2)
{
  std::vector<int> intersection;

  auto v1_itr = v1.begin();
  auto v2_itr = v2.begin();

  while (v1_itr != v1.end() && v2_itr != v2.end())
  {
    if (*v1_itr == *v2_itr)
    {
      intersection.emplace_back(*v1_itr);
      SeekNextInt(v1_itr);
      SeekNextInt(v2_itr);
    }
    else if (*v1_itr < *v2_itr)
      SeekNextInt(v1_itr);
    else
      SeekNextInt(v2_itr);
  }

  return intersection;
}

TEST(GetIntersectionTest, UnitTest)
{
  std::vector<int> v1{2,3,3,5,5,6,7,7,8,12};
  std::vector<int> v2{5,5,6,8,8,9,10,10};
  std::vector<int> result{5,6,8};
  EXPECT_EQ(result, GetIntersection(v1, v2));

  v1 = {1,2,3,4,5,6,7,8,9};
  v2 = {2,3,4,5,6,9};
  result = {2,3,4,5,6,9};
  EXPECT_EQ(result, GetIntersection(v1, v2));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
