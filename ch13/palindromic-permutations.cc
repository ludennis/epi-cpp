/*
 *  13.1 Test for palindromic permutations
 *  Write a program to test whether the letters forming a string can be permuted to form
 *    a palindrome. For example, "edified" can be permuted to form "deified".
 */

#include <iostream>
#include <string>
#include <unordered_map>

#include <gtest/gtest.h>

bool HasPalindromePermutation(const std::string &word)
{
  // basically just count each letter with a map
  std::unordered_map<char, int> letterToCount;

  for (auto &c : word)
  {
    if (letterToCount.find(c) == letterToCount.end())
      letterToCount[c] = 1;
    else
      letterToCount[c] += 1;
  }

  auto numberOfOdd = 0;
  for (auto &letterAndCount : letterToCount)
  {
    if (letterAndCount.second % 2 != 0)
      numberOfOdd++;
  }

  return numberOfOdd <= 1;
}

TEST(HasPalindromePermutationTest, UnitTest)
{
  EXPECT_EQ(true, HasPalindromePermutation("edified"));
  EXPECT_EQ(true, HasPalindromePermutation("abcabc"));
  EXPECT_EQ(false, HasPalindromePermutation("ab"));
  EXPECT_EQ(true, HasPalindromePermutation("a"));
  EXPECT_EQ(true, HasPalindromePermutation("aa"));
  EXPECT_EQ(false, HasPalindromePermutation("aaaaaaaaaaaaaaaabbbefgbaspokz"));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
