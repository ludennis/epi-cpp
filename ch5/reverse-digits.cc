/*
 *  Write a program which takes an integer and returns the integer corresponding to the digits
 *    of the input written in reverse order. For example, the reverse of 42 is 24, and the reverse
 *    of -314 is -413
 */

#include <iostream>

int reverse(int x)
{
  bool negative = (x < 0 ? true : false);
  x = (negative ? -x : x);

  int result = 0;
  while (x > 0)
  {
    result *= 10;
    result += x % 10;
    x /= 10;
  }

  return (negative ? -result : result);
}

int main(int argc, char **argv)
{
  std::cout << reverse(-12345) << std::endl;

  return 0;
}
