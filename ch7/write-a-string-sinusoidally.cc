/*
 *  7.11
 *  Write a program which takes as input a string s and returns the snakestring of s.
 */

#include <iostream>
#include <string>

std::string SnakeStringify(std::string &s)
{
  std::string result(s.size(), ' ');

  bool up = true;
  int top = 0;
  int mid = s.size() / 4;
  int bot = s.size() * 3 / 4;

  for (auto i{0}; i < s.size(); ++i)
  {
    if (i % 2 == 1)
    {
      if (up)
      {
        result[top++] = s[i];
        up = false;
      }
      else
      {
        result[bot++] = s[i];
        up = true;
      }
    }
    else
    {
      result[mid++] = s[i];
    }
  }

  return result;
}

int main(int argc, char **argv)
{
  std::string s = "Hello World!";

  std::cout << SnakeStringify(s) << std::endl;

  return 0;
}
