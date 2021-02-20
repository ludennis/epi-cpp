/*
 *  6.6
 *  Write a program that takes an array denoting the daily stock price, and returns the
 *    maximum profit that could be made by buying and then selling one share of that stock.
 *
 *  Example:
 *    Input = [310,315,275,295,260,270,290,230,255,250]
 *    Output = 30 (buy at 260 and sell at 290)
 */

#include <iostream>
#include <limits>
#include <vector>

int maxProfit(std::vector<int> &prices)
{
  int currentMin = prices[0];

  int max = std::numeric_limits<int>::min();

  for (auto i{1}; i < prices.size(); ++i)
  {
    if (prices[i] - currentMin > max)
      max = prices[i] - currentMin;

    if (prices[i] < currentMin)
      currentMin = prices[i];
  }

  return max;
}

int main(int argc, char **argv)
{
  std::vector<int> prices{310,315,275,295,260,270,290,230,255,290};

  std::cout << maxProfit(prices) << std::endl;

  return 0;
}
