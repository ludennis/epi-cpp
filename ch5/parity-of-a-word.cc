/*
 *  5.1
 *
 *  Parity = 1 if the number of 1s in the word is odd
 */

#include <iostream>

bool ParityOfWord(long long unsigned int x)
{
  bool parity = false;

  while (x > 0)
  {
    parity = !parity;
    x = x & (x - 1);
  }

  return parity;
}

int main(int argc, char **argv)
{
  long long unsigned int x = 10;

  std::cout << ParityOfWord(x) << std::endl;

  return 0;
}
