/*
 *  Write a program which takes as input an array and finds the distance between a
 *    closest pair of equal entries. For example, if s = ["All", "work", "and", "no",
 *    "play", "makes", "for", "no", "work", "no", "fun", "and", "no", "results"], then
 *    the second and third occurrences of "no" is the closest pair
 */

#include <string>
#include <unordered_map>
#include <vector>

#include <gtest/gtest.h>

int GetDistance(const int a, const int b)
{
  return std::abs(a - b);
}

int GetDistance(const std::pair<int,int> &p)
{
  return std::abs(p.second - p.first);
}

std::unordered_map<std::string, std::pair<int,int>>
GetRepeatedClosestPairs(const std::vector<std::string> &words)
{
  std::unordered_map<std::string,std::pair<int,int> > wordToClosestPair;

  for (auto i{0}; i < words.size(); ++i)
  {
    if (wordToClosestPair.find(words[i]) == wordToClosestPair.end())
    {
      wordToClosestPair[words[i]] = std::make_pair(i, -1);
    }
    else
    {
      if (wordToClosestPair[words[i]].second == -1)
        wordToClosestPair[words[i]].second = i;
      else
      {
        if (GetDistance(i, wordToClosestPair[words[i]].second) < 
            GetDistance(wordToClosestPair[words[i]]))
        {
          wordToClosestPair[words[i]].first = wordToClosestPair[words[i]].second;
          wordToClosestPair[words[i]].second = i;
        }
      }
    }
  }

  return wordToClosestPair;
}

TEST(GetRepeatedClosestPairTest, UnitTest)
{
  std::vector<std::string> words{"all", "work", "and", "no", "play", "makes", "for", "no",
    "work", "no", "fun", "and", "no", "results"};
  auto closestPairs = GetRepeatedClosestPairs(words);

  EXPECT_EQ(2, GetDistance(closestPairs["no"]));
  EXPECT_EQ(7, GetDistance(closestPairs["work"]));
  EXPECT_EQ(9, GetDistance(closestPairs["and"]));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
