/*
 *  7.9
 *  Write a program which takes as input a valid Roman number string s and returns the
 *    integer it corresponds to.
 */

#include <iostream>
#include <string>

int RomanNumeral(std::string &s)
{
  int sum = 0;

  for (auto i{0}; i < s.size(); ++i)
  {
    if (s[i] == 'M')
    {
      sum += 1000;
    }
    else if (s[i] == 'D')
    {
      sum += 500;
    }
    else if (s[i] == 'C')
    {
      if (i + 1 < s.size() && s[i + 1] == 'D')
      {
        sum += 400;
        i++;
      }
      else if (i + 1 < s.size() && s[i + 1] == 'M')
      {
        sum += 900;
        i++;
      }
      else
        sum += 100;
    }
    else if (s[i] == 'L')
    {
      sum += 50;
    }
    else if (s[i] == 'X')
    {
      if (i + 1 < s.size() && s[i + 1] == 'L')
      {
        sum += 40;
        i++;
      }
      else if (i + 1 < s.size() && s[i + 1] == 'C')
      {
        sum += 90;
        i++;
      }
      else
        sum += 10;
    }
    else if (s[i] == 'V')
    {
      sum += 5;
    }
    else if (s[i] == 'I')
    {
      if (i + 1 < s.size() && s[i + 1] == 'V')
      {
        sum += 4;
        i++;
      }
      else if (i + 1 < s.size() && s[i + 1] == 'X')
      {
        sum += 9;
        i++;
      }
      else
        sum += 1;
    }
  }

  return sum;
}

int main(int argc, char **argv)
{
  std::string s = "MDXCVI";

  std::cout << RomanNumeral(s) << std::endl;

  return 0;
}
