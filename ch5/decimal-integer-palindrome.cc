/*
 *  5.9
 *  Given an integer, determine if that integer's representation as a decimal string is a
 *    palindrome.
 */

#include <math.h>

#include <iostream>

bool IsPalindrome(int x)
{
  int msd; // Most Significant Digit
  int lsd; // Least Significant Digit

  while (x > 0)
  {
    std::cout << "x = " << x << std::endl;
    msd = x / pow(10, (floor(log10(x))));
    lsd = x % 10;

    std::cout << "msd = " << msd << ", lsd = " << lsd << std::endl;

    if (msd != lsd)
      return false;

    x = x - msd * pow(10, (floor(log10(x)))); // remove msd
    x = x / 10; // remove lsd
    std::cout << "updated x = " << x << std::endl;
  }

  return true;
}

int main(int argc, char **argv)
{
  int x = 21477412;

  std::cout << IsPalindrome(x) << std::endl;

  return 0;
}
