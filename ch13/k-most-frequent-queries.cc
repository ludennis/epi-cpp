/*
 *  13.5
 *  Given an array of strings, compute the k strings that appear most frequently in the array
 */

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include <gtest/gtest.h>

using tStringToIntPair = std::pair<std::string, int>;

std::vector<std::string> KMostFrequentStrings(const std::vector<std::string> &words, int k)
{
  auto lesser =
    [](const tStringToIntPair p1, const tStringToIntPair p2)
    { return p1.second > p2.second; };

  std::priority_queue<tStringToIntPair,
                      std::vector<tStringToIntPair>,
                      decltype(lesser)> minHeap(lesser);

  std::unordered_map<std::string, int> wordToCount;
  for (auto &word : words)
  {
    if (wordToCount.find(word) == wordToCount.end())
      wordToCount[word] = 1;
    else
      wordToCount[word] += 1;
  }

  for (auto &p : wordToCount)
  {
    auto word = p.first;
    minHeap.push(std::make_pair(word, wordToCount[word]));
    if (minHeap.size() > k)
      minHeap.pop();
  }

  std::vector<std::string> result;
  while (!minHeap.empty())
  {
    result.push_back(minHeap.top().first);
    minHeap.pop();
  }

  return result;
}

TEST(KMostFrequentStringsTest, UnitTest)
{
  std::vector<std::string> expectedResult{"I"};
  std::vector<std::string> words{"I","I","I","I","AB","AB","AB","C","C","Z","W","Q"};

  EXPECT_EQ(expectedResult, KMostFrequentStrings(words, 1));

  expectedResult = {"AB","I"};
  EXPECT_EQ(expectedResult, KMostFrequentStrings(words, 2));

  expectedResult = {"C","AB","I"};
  EXPECT_EQ(expectedResult, KMostFrequentStrings(words, 3));

  words = {"I","Q","I","I","Q","AB","AB","AB","Q","I","C","C","Q","Z","W","Q","Q"};

  expectedResult = {"Q"};
  EXPECT_EQ(expectedResult, KMostFrequentStrings(words, 1));
  expectedResult = {"I","Q"};
  EXPECT_EQ(expectedResult, KMostFrequentStrings(words, 2));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
