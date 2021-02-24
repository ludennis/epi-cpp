/*
 *  7.8
 *  Write a program that takes as input an integer n and returns the nth integer in the
 *    look-and-say sequence. Return the result as a string.
 */

#include <iostream>
#include <string>

std::string LookAndSay(std::string &s)
{
  int count = 1;
  char current = s[0];
  std::string result;

  for (auto i{1}; i < s.size(); ++i)
  {
    if (current == s[i])
      count++;
    else
    {
      result += std::to_string(count);
      result += current;
      current = s[i];
      count = 1;
    }
  }

  result += std::to_string(count);
  result += current;

  return result;
}

std::string LookAndSay(int n)
{
  std::string s = "1";

  if (n <= 1)
    return s;

  for (auto i{1}; i < n; ++i)
    s = LookAndSay(s);

  return s;
}

int main(int argc, char **argv)
{
  std::cout << LookAndSay(6) << std::endl;

  return 0;
}
