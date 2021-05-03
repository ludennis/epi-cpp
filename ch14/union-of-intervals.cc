/*
 *  14.6
 *  Design an algorithm that takes as input a set of intervals, and outputs their union
 *    expressed as a set of disjoint intervals
 */

#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

struct Endpoint
{
  int val;
  bool included;
  bool end;

  Endpoint(int val, bool included, bool end)
  : val(val)
  , included(included)
  , end(end)
  {}

  bool operator<(const Endpoint& that)
  {
    if (val == that.val)
      if (end == 0 && that.end == 0)
        return included > that.included;
      else if (end == 1 && that.end == 1)
        return included < that.included;
      else
        return end < that.end;
    else
      return val < that.val;
  }

  friend std::ostream& operator<<(std::ostream &out, const Endpoint& p)
  {
    out << "(" << p.val << "," << p.included << "," << p.end << ")";
    return out;
  }
};

bool operator==(const Endpoint& a, const Endpoint& b)
{
  return a.val == b.val && a.included == b.included && a.end == b.end;
}

struct Interval
{
  int start;
  int end;
  bool startIncluded;
  bool endIncluded;

  Interval(int start, int end, bool startIncluded, bool endIncluded)
  : start(start)
  , end(end)
  , startIncluded(startIncluded)
  , endIncluded(endIncluded)
  {}

  friend std::ostream& operator<<(std::ostream &out, const Interval& i)
  {
    out << "(" << i.start << "," << i.end << "," << i.startIncluded << "," << i.endIncluded << ")";
    return out;
  }
};

bool operator==(const Interval& a, const Interval& b)
{
  return a.start == b.start && a.end == b.end &&
    a.startIncluded == b.startIncluded && a.endIncluded == b.endIncluded;
}

std::vector<Endpoint> IntervalsToEndpoints(std::vector<Interval>& intervals)
{
  std::vector<Endpoint> endpoints;
  for (auto &interval : intervals)
  {
    endpoints.emplace_back(Endpoint{interval.start, interval.startIncluded, 0});
    endpoints.emplace_back(Endpoint{interval.end, interval.endIncluded, 1});
  }

  return endpoints;
}

std::ostream& operator<<(std::ostream &out, const std::vector<Endpoint> &endpoints)
{
  for (auto &endpoint : endpoints)
    out << endpoint << ",";
  out << std::endl;
  return out;
}

std::vector<Interval> UnionizeIntervals(std::vector<Interval>& intervals)
{
  // dissemble interval into endpoints
  auto endpoints = IntervalsToEndpoints(intervals);

  // sort each endpoints
  std::sort(endpoints.begin(), endpoints.end());

  // group them
  int openBrackets = 0;
  int start;
  bool startIncluded;
  std::vector<Interval> result;
  for (auto &endpoint : endpoints)
  {
    if (openBrackets == 0)
    {
      start = endpoint.val;
      startIncluded = endpoint.included;
    }

    if (endpoint.end == 0)
      openBrackets++;
    else
      openBrackets--;

    if (openBrackets == 0)
    {
      result.emplace_back(Interval{start,endpoint.val,startIncluded,endpoint.included});
    }
  }

  return result;
}

TEST(EndpointTest, UnitTest)
{
  Endpoint e1(0,0,0);
  Endpoint e2(1,1,0);
  Endpoint e3(1,0,1);
  Endpoint e4(2,1,1);

  std::vector<Endpoint> endpoints;

  endpoints.emplace_back(e4);
  endpoints.emplace_back(e3);
  endpoints.emplace_back(e1);
  endpoints.emplace_back(e2);

  std::sort(endpoints.begin(), endpoints.end());
  std::vector<Endpoint> result{e1,e2,e3,e4};
  EXPECT_EQ(result, endpoints);
}

TEST(UnionizeIntervalsTest, UnitTest)
{
  std::vector<Interval> intervals{
    Interval{2,4,1,1},
    Interval{8,11,1,0},
    Interval{13,15,0,0},
    Interval{16,17,0,0},
    Interval{1,1,1,1},
    Interval{3,4,1,0},
    Interval{7,8,1,0},
    Interval{12,16,0,1},
    Interval{0,3,0,0},
    Interval{5,7,1,0},
    Interval{9,11,0,1},
    Interval{12,14,1,1}
  };

  std::vector<Interval> result{
    Interval{0,4,0,1},
    Interval{5,11,1,1},
    Interval{12,17,1,0}
  };

  EXPECT_EQ(result, UnionizeIntervals(intervals));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
