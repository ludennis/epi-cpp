/*
 *  11.5
 *  Design an algorithm for computing the running median of a sequence.
 */

#include <queue>
#include <vector>

#include <gtest/gtest.h>

std::vector<double> GetRunningMedians(const std::vector<int> &numbers)
{
  std::priority_queue<int, std::vector<int>, std::less<int>> leftMaxHeap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> rightMinHeap;

  int size = 0;

  std::vector<double> medians;

  for (auto &number : numbers)
  {
    if (size == 0)
    {
      medians.emplace_back(number);
    }
    else
    {
      // if size is even
      if (size % 2 == 0)
      {
        if (leftMaxHeap.top() <= number && number <= rightMinHeap.top())
        {
          medians.emplace_back(number);
        }
        else if (number < leftMaxHeap.top())
        {
          medians.emplace_back(leftMaxHeap.top());
          leftMaxHeap.pop();
          leftMaxHeap.emplace(number);
        }
        else
        {
          medians.emplace_back(rightMinHeap.top());
          rightMinHeap.pop();
          rightMinHeap.emplace(number);
        }
      }
      // if size is odd
      else
      {
        if (number == medians.back())
        {
          leftMaxHeap.emplace(medians.back());
          rightMinHeap.emplace(medians.back());
          medians.emplace_back(medians.back());
        }
        else if (number > medians.back())
        {
          rightMinHeap.emplace(number);
          leftMaxHeap.emplace(medians.back());
          medians.emplace_back(leftMaxHeap.top() +
            (double(rightMinHeap.top()) - double(leftMaxHeap.top())) / 2);
        }
        else
        {
          leftMaxHeap.emplace(number);
          rightMinHeap.emplace(medians.back());
          medians.emplace_back(leftMaxHeap.top() +
            (double(rightMinHeap.top()) - double(leftMaxHeap.top())) / 2);
        }
      }
    }

    size++;
  }

  return medians;
}

TEST(GetRunningMediansTest, UnitTest)
{
  std::vector<int> numbers{1,0,3,5,2,0,1};
  std::vector<double> expected{1,0.5,1,2,2,1.5,1};

  EXPECT_EQ(expected, GetRunningMedians(numbers));

  numbers = {5,9,1,0,3,3,2,2,0,1};
  expected = {5,7,5,3,3,3,3,2.5,2,2};

  EXPECT_EQ(expected, GetRunningMedians(numbers));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
