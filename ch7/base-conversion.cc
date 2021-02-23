/*
 *  7.2
 *  Write a program that performs base conversion. The input is a string, an integer b1, and
 *    another integer b2. The string represents be an integer in base b1. The output should be
 *    the string representing the integer in base b2.
 */

#include <iostream>
#include <stack>
#include <string>

std::string ConvertBase(std::string &s, int b1, int b2)
{
  // TODO: take care of negatives

  int sum = 0;
  for (auto i{0}; i < s.size(); ++i)
  {
    sum *= b1;
    sum += s[i] - 48;
    std::cout << "sum = " << sum << std::endl;
  }

  std::stack<int> stack;

  while (sum > 0)
  {
    stack.push(sum % b2);
    sum /= b2;
  }

  std::string converted;
  while (!stack.empty())
  {
    if (stack.top() >= 10)
      converted.push_back(char(stack.top() + 55));
    else
      converted += std::to_string(stack.top());
    stack.pop();
  }

  return converted;
}

int main(int argc, char **argv)
{
  std::string s = "615";
  int b1 = 7;
  int b2 = 13;

  auto converted = ConvertBase(s, b1, b2);

  std::cout << "converted = " << converted << std::endl;

  return 0;
}
