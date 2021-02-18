#include <iostream>

int CountBits(unsigned int x)
{
  int numOfBits = 0;

  while (x > 0)
  {
    numOfBits += x & 1;
    x >>= 1;
  }

  return numOfBits;
}

int main(int argc, char **argv)
{
  unsigned int x = 8;

  std::cout << CountBits(x) << std::endl;

  return 0;
}
