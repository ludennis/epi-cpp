/*
 *  6.2
 *  Write a program which takes as input an array of digits encoding a decimal number D and
 *    updates the array to represent the number D + 1. For example, if the input is <1,2,9>
 *    then you should update the array to <1,3,0>. Your algorithm should work even if it is
 *    implemented in a language that has finite-precision arithmetic.
 */

#include <iostream>
#include <vector>

bool increment(std::vector<int> &v, int index)
{
  if (index < 0)
    return false;

  if (v[index] == 9)
  {
    v[index] = 0;
    if (index == 0)
      v.insert(v.begin(), 1);
    return true;
  }
  else
  {
    v[index]++;
    return false;
  }
}

void increment(std::vector<int> &v)
{
  int i = v.size() - 1;
  while (increment(v, i))
  {
    i--;
  }
}

int main(int argc, char **argv)
{
  std::vector<int> v{9,9,9};

  for (auto &x : v)
    std::cout << x << ",";
  std::cout << std::endl;

  increment(v);

  for (auto &x : v)
    std::cout << x << ",";
  std::cout << std::endl;

  return 0;
}
