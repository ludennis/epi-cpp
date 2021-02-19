/*
 *  Write a program that takes a double x and an integer y and returns x^y. You can ignore overflow
 *    and underflow.
 */

#include <iostream>
#include <unordered_map>

double power(double x, int y)
{
  if (y < 0)
  {
    y = -y;
    x = 1 / x;
  }

  std::unordered_map<int,double> powerCache;
  powerCache.insert({0, 1.0});
  powerCache.insert({1, x});
  powerCache.insert({2, x * x});

  int p, k;
  int bitsMoved;
  double sum = 1.0;
  while (y > 0)
  {
    // get lowest bit
    p = y & ~(y - 1);

    if (powerCache.find(p) != powerCache.end())
      sum *= powerCache[p];
    else
    {
      // divide the power by 2 and try to find in cache
      k = p;
      bitsMoved = 0;
      while (powerCache.find(k) == powerCache.end())
      {
        k >>= 1;
        bitsMoved++;
      }

      // get to the cache
      while (bitsMoved > 0)
      {
        powerCache[k * 2] = powerCache[k] * powerCache[k];
        k <<= 1;
        bitsMoved--;
      }

      sum *= powerCache[p];
    }

    y = y & (y - 1);
    std::cout << "sum = " << sum << std::endl;
  }

  return sum;
}

int main(int argc, char **argv)
{
  std::cout << power(3.0, -3) << std::endl;

  return 0;
}
