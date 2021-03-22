/*
 *  12.10
 *  Given an array of n integers, each between 0 and n - 1, inclusive. Exactly one element
 *    appears twice, implying that exactly one number between 0 and n - 1 is missing from the
 *    array. How would you compute the duplicate and missing numbers.
 */

#include <iostream>

#include <utility>
#include <vector>

#include <gtest/gtest.h>

int GetLeastSignificantBit(int x)
{
  return x & -x;
}

std::pair<int,int> FindMissingAndDuplicate(std::vector<int> v)
{
  int n = v.size();

  int regularXOR = 0;
  int vectorXOR = 0;
  for (auto i{0}; i < n; ++i)
  {
    regularXOR ^= i;
    vectorXOR ^= v[i];
  }

  int differingBits = regularXOR ^ vectorXOR;
  int differingLSD = GetLeastSignificantBit(differingBits);

  int missingOrDuplicate = 0;
  for (int i{0}; i < n; ++i)
  {
    if (i & differingLSD > 0)
    {
      missingOrDuplicate ^= i;
    }
    if (v[i] & differingLSD > 0)
    {
      missingOrDuplicate ^= v[i];
    }
  }

  // check if missingOrDuplicate is missing or duplicate
  bool found = false;
  int duplicate;
  int missing;
  for (auto i{0}; i < n; ++i)
  {
    if (v[i] == missingOrDuplicate)
      found = true;
  }

  if (found)
  {
    duplicate = missingOrDuplicate;
    missing = differingBits ^ duplicate;
  }
  else
  {
    missing = missingOrDuplicate;
    duplicate = differingBits ^ missing;
  }

  return std::make_pair(missing, duplicate);
}

TEST(FindMissingAndDuplicateTest, UnitTest)
{
  EXPECT_EQ(std::make_pair(4,3), FindMissingAndDuplicate(std::vector<int>{5,3,0,3,1,2}));
  EXPECT_EQ(std::make_pair(4,5), FindMissingAndDuplicate(std::vector<int>{1,2,0,3,5,5}));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
