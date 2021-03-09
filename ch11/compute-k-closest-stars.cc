/*
 *  11.4
 *  Given a file storing ~10^12 stars with their cooridnates in (x, y, z). Assuming the Earth is at
 *    (0,0,0) and with the coordinates of the stars being the distances away from Earth (in light
 *    years), how would you compute the k stars which are closest to the Earth?
 */

#include <cmath>

#include <queue>
#include <set>
#include <tuple>
#include <vector>

#include <gtest/gtest.h>

class DistanceLesserComparator
{
public:
  DistanceLesserComparator(){}

  bool operator() (const std::tuple<int,int,int> &lhs, const std::tuple<int,int,int> &rhs)
  {
    return GetDistance(lhs) < GetDistance(rhs);
  }

private:
  double GetDistance(const std::tuple<int,int,int> &point)
  {
    return sqrt(std::get<0>(point) * std::get<0>(point) +
                std::get<1>(point) * std::get<1>(point) +
                std::get<2>(point) * std::get<2>(point));
  }
};

std::set<std::tuple<int,int,int>> KClosestStars(
  const std::vector<std::vector<int>> &stars, int k)
{
  // need max heap, to pop the max one if the size max heap exceeded k
  std::priority_queue<std::tuple<int,int,int>, std::vector<std::tuple<int,int,int>>,
    DistanceLesserComparator> closestStars;

  for (auto &star : stars)
  {
    auto s = std::make_tuple(star[0], star[1], star[2]);
    closestStars.emplace(s);
    if (closestStars.size() > k)
      closestStars.pop();
  }

  std::set<std::tuple<int,int,int>> result;
  while (!closestStars.empty())
  {
    result.emplace(closestStars.top());
    closestStars.pop();
  }

  return result;
}

TEST(KClosestStarsTest, UnitTest)
{
  std::vector<std::vector<int>> stars
  {{1,2,3},
   {122,34,21},
   {400,400,400},
   {10,10,10},
   {-5,-1,-2}};

  std::set<std::tuple<int,int,int>> expected
  {std::make_tuple(1,2,3)};

  EXPECT_EQ(expected, KClosestStars(stars, 1));

  expected.emplace(std::make_tuple(-5,-1,-2));
  EXPECT_EQ(expected, KClosestStars(stars, 2));

  expected.emplace(std::make_tuple(10,10,10));
  EXPECT_EQ(expected, KClosestStars(stars, 3));

  stars.emplace_back(std::vector<int>{1,1,1});
  expected = {std::make_tuple(1,1,1), std::make_tuple(1,2,3)};
  EXPECT_EQ(expected, KClosestStars(stars, 2));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
