/*
 *  Write a program that takes a 64-bit word and returns the 64-bit word consiting of the bits
 *    of the input word in reverse order. For example, if the input is alternating 1s and 0s.
 *  For example, (1010 ... 10), the output should be alternating 0s and 1s, i.e., (0101 ... 01).
 */

#include <iostream>
#include <limits>
#include <unordered_map>

void printBits(long long int x)
{
//  bool negative = (x < 0 ? true : false);
//  x = (negative ? -x : x);
  int bit;

  for (auto i{0}; i < 64; ++i)
  {
    bit = x & 1;
    std::cout << bit;
    x >>= 1;
  }
  std::cout << std::endl;
}

void printBits(short x)
{
  int bit;
  for (auto i{0}; i < 16; ++i)
  {
    bit = x & 1;
    std::cout << bit;
    x >>= 1;
  }
  std::cout << std::endl;
}

long long int reverseBits(long long int x)
{
  std::unordered_map<short,short> reverseCache;

  for (short i = std::numeric_limits<short>::min(); i < std::numeric_limits<short>::max(); ++i)
  {
    reverseCache[i] = ~i;
  }

  long long int result = 0;
  short a;

  for (auto i{0}; i < 4; ++i)
  {
    a = x & 0xFFFF;
    result |= (static_cast<long long int>(reverseCache[a]) << (16 * i));
    x >>= 16;
  }

  return result;
}

int main(int argc, char **argv)
{
  long long int x = -1;

  printBits(x);

  printBits(reverseBits(x));

  return 0;
}
