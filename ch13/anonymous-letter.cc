/*
 *  13.2
 *  Write a program which takes text for an anonymous letter and text for a magazine and
 *    determines if it is possible to write the anonymous letter using the magazine. The
 *    anonymous letter can be written using the magazine if for each character in the
 *    anonymous letter, the number of times it appears in the anonymous letter is no more
 *    than the number of times it appears in the magazine.
 */

#include <unordered_map>

#include <gtest/gtest.h>

bool AnonymousLetterWritable(std::string letter, std::string magazine)
{
  std::unordered_map<char, int> letterCounts;

  // get usable characters from magazine
  for (auto &character : magazine)
  {
    letterCounts[character] += 1;
  }

  // consume each character
  for (auto &character : letter)
  {
    letterCounts[character] -= 1;
    if (letterCounts[character] < 0)
      return false;
  }

  return true;
}

TEST(AnonymousLetterWritableTest, UnitTest)
{
  EXPECT_EQ(true, AnonymousLetterWritable("abcde", "aabbccddee"));
  EXPECT_EQ(false, AnonymousLetterWritable("abcde", "abcd"));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
