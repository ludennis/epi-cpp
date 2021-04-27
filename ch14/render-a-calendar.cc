/*
 *  14.4
 *  Write a program that takes a set of events, and determines the maximum number of events
 *    that take place concurrently.
 */

#include <algorithm>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

int MaxConcurrentEvents(std::vector<std::pair<int,int>> &events)
{
  // a vector represent how many events are in each time. Starting from 0.5 - 23.5
  // each with 1.0 increment
  std::vector<unsigned int> times(24);

  int maxConcurrent = 0;

  for (auto &event : events)
  {
    for (auto i{0}; i < 24; ++i)
    {
      if ((double)event.first < i + 0.5 && i + 0.5 < (double)event.second)
        times[i]++;
    }
  }

  return *max_element(times.begin(), times.end());
}

TEST(MaxConcurrentEventsTest, UnitTest)
{
  std::vector<std::pair<int,int>> events{
    std::make_pair<int,int>(1,5),
    std::make_pair<int,int>(6,10),
    std::make_pair<int,int>(11,13),
    std::make_pair<int,int>(14,15),
    std::make_pair<int,int>(2,7),
    std::make_pair<int,int>(8,9),
    std::make_pair<int,int>(12,15),
    std::make_pair<int,int>(4,5),
    std::make_pair<int,int>(9,17),
  };

  EXPECT_EQ(3, MaxConcurrentEvents(events));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

