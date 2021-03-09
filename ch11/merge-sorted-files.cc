/*
 *  11.1
 *  Write a program that takes as input a set of sorted sequences and computes the union of these
 *    sequences as a sorted sequence. For example, if the input is (3,5,7), (0,6), and (0,6,28),
 *    then the output is (0,0,3,5,6,6,7,28)
 */

#include <iostream>
#include <queue>
#include <vector>

#include <gtest/gtest.h>

template <typename T>
struct IteratorWithEnd
{
  IteratorWithEnd<T>(const std::vector<T> &v)
  : end(v.cend())
  , itr(v.cbegin())
  {}

  bool operator > (const IteratorWithEnd& thatIterator)
  {
    return *itr > *thatIterator.itr;
  }

  typename std::vector<T>::const_iterator end;
  typename std::vector<T>::const_iterator itr;
};


std::vector<int> MergeSortedFiles(std::vector<std::vector<int>> &files)
{
  std::priority_queue<IteratorWithEnd<int>, std::vector<IteratorWithEnd<int>>,
    std::greater<>> minHeap;
  std::vector<int> result;

  for (auto i{0}; i < files.size(); ++i)
  {
    auto iterator = IteratorWithEnd<int>(files[i]);
    minHeap.emplace(iterator);
  }

  while (!minHeap.empty())
  {
    result.emplace_back(*minHeap.top().itr);
    if (minHeap.top().itr != minHeap.top().end)
    {
      auto iterator = minHeap.top();
      minHeap.pop();
      std::advance(iterator.itr, 1);
      if (iterator.itr != iterator.end)
        minHeap.emplace(iterator);
    }
    else
      minHeap.pop();
  }

  return result;
}

TEST(MergeSortedFilesTest, UnitTest)
{
  std::vector<std::vector<int>> files
  {{3,5,7},
   {0,6},
   {0,6,28}};

  auto merged = MergeSortedFiles(files);
  auto expected = std::vector<int>{0,0,3,5,6,6,7,28};

  EXPECT_EQ(expected, merged);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
