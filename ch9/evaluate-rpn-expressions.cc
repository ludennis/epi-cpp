/*
 *  9.2
 *  Write a program that takes an arithmetical expression in RPN and returns the number that
 *    the expression evaluates to.
 */

#include <iostream>
#include <stack>
#include <string>

bool IsOperator(std::string &s)
{
  return s == "+" || s == "-" || s == "x" || s == "/";
}

void Evaluate(std::stack<int> &stack, std::string &op)
{
  auto op2 = stack.top();
  stack.pop();
  auto op1 = stack.top();
  stack.pop();

  if (op == "+")
    stack.push(op1 + op2);
  else if (op == "-")
    stack.push(op1 - op2);
  else if (op == "/")
    stack.push(op1 / op2);
  else if (op == "x")
    stack.push(op1 * op2);
}

int EvaluateRPN(std::string &rpn)
{
  std::stack<int> stack;

  std::string token;

  std::string delimiter = ",";
  size_t pos = 0;

  while ((pos = rpn.find(delimiter)) != std::string::npos)
  {
    token = rpn.substr(0, pos);

    if (IsOperator(token))
    {
      Evaluate(stack, token);
    }
    else
    {
      stack.push(std::stoi(token));
    }

    rpn.erase(0, pos + delimiter.length());
  }

  Evaluate(stack, rpn);

  return stack.top();
}

int main(int argc, char **argv)
{
//  std::string rpn = "3,4,+,2,x,1,+";
  std::string rpn = "1,1,+,-2,x";

  std::cout << EvaluateRPN(rpn) << std::endl;

  return 0;
}
