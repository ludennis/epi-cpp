/*
 *  11.7
 *  How would you implement a stack API using a heap?
 */

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

struct PairLessComparator
{
  bool operator() (const std::pair<int,int> &lhs, const std::pair<int,int> &rhs)
  {
    return lhs.first < rhs.first;
  }
};

/* storing (timestamp, value) */
class HeapBasedStack
{
public:
  HeapBasedStack(){}
  void Push(int x)
  {
    int timestamp = maxHeap.size();

    maxHeap.emplace(std::make_pair(timestamp, x));
  }

  void Pop()
  {
    maxHeap.pop();
  }

  int Top()
  {
    return maxHeap.top().second;
  }

private:
  std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>,
    PairLessComparator> maxHeap;
};

TEST(HeapBasedStackTest, UnitTest)
{
  HeapBasedStack s;

  s.Push(1);
  s.Push(4);
  s.Push(0);
  s.Push(5);
  s.Push(2);

  EXPECT_EQ(2, s.Top());
  s.Pop();

  EXPECT_EQ(5, s.Top());
  s.Pop();

  EXPECT_EQ(0, s.Top());
  s.Pop();

  EXPECT_EQ(4, s.Top());
  s.Pop();

  EXPECT_EQ(1, s.Top());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
