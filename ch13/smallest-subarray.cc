/*
 *  13.7
 *  Write a program which takes an array of strings and a set of strings, and return
 *    the indices of the starting and ending index of a shortest subarray of the given
 *    array that "covers" the set, i.e., contains all strings in the set.
 */

#include <string>
#include <vector>

#include <gtest/gtest.h>

bool IsLetter(char c)
{
  return (c >= 65 && c <= 90) || (c >= 97 && c <=122);
}

std::string RemoveTrailingPunctuation(std::string &s)
{
  if (!IsLetter(s.back()))
    s.pop_back();

  return s;
}

std::vector<std::string> Vectorize(std::string s, const std::string &delimiter)
{
  std::vector<std::string> vectorized;
  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos)
  {
    token = s.substr(0, pos);
    vectorized.emplace_back(RemoveTrailingPunctuation(token));
    s.erase(0, pos + delimiter.length());
  }
  vectorized.emplace_back(RemoveTrailingPunctuation(s));

  return vectorized;
}

TEST(VectorizeTest, UnitTest)
{
  std::string delimiter = " ";
  std::vector<std::string> expected = {"I","the","professor","am","him"};
  EXPECT_EQ(expected, Vectorize("I, the professor, am him", delimiter));
  expected = {"Yes","I","FINALLY","did","it","Can","you"};
  EXPECT_EQ(expected, Vectorize("Yes! I FINALLY did it! Can you?", delimiter));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
