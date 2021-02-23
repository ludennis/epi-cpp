/*
 *  7.1
 *  Implement string/integer inter-conversion functions.
 */

#include <iostream>
#include <stack>
#include <string>

int Convert(std::string &s)
{
  bool negative = (s[0] == '-' ? true : false);

  int sum = 0;
  int a = 0;
  for (auto i{0}; i < s.size(); ++i)
  {
    sum *= 10;
    if (s[i] != '-')
    {
      a = int(s[i]) - 48;
      sum += a;
    }
  }

  return (negative ? sum * - 1 : sum);
}

std::string Convert(int x)
{
  std::stack<int> stack;

  bool negative = (x < 0 ? true : false);
  x = (negative ? x * - 1 : x);

  while (x > 0)
  {
    stack.push(x % 10);
    x /= 10;
  }

  std::string s;
  if (negative)
    s += "-";
  while (!stack.empty())
  {
    s += std::to_string(stack.top());
    stack.pop();
  }

  return s;
}

int main(int argc, char **argv)
{
  std::string s = "-123";

  auto integer = Convert(s);
  std::cout << integer << std::endl;

  int i = -456;
  auto str = Convert(i);
  std::cout << str << std::endl;

  return 0;
}
