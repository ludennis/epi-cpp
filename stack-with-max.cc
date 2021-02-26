/*
 *  9.1
 *  Design a stack that includes a max operation, in addition to push and pop. The max method
 *    should return the maximum value stored in the stack.
 */

#include <iostream>
#include <stack>

template <typename T>
class MaxStack : public std::stack<T>
{
public:
  MaxStack<T>(){};

  void emplace(T t)
  {
    std::stack<T>::emplace(t);
    if (maxes.empty() || t > maxes.top())
      maxes.emplace(t);
    else
      maxes.emplace(maxes.top());
  }

  void pop()
  {
    std::stack<T>::pop();
    maxes.pop();
  }

  T max()
  {
    return maxes.top();
  }

private:
  std::stack<T> maxes;
};

int main(int argc, char **argv)
{
  MaxStack<int> maxStack;

  maxStack.emplace(1);
  maxStack.emplace(1);
  maxStack.emplace(3);
  std::cout << "max = " << maxStack.max() << std::endl;

  while (!maxStack.empty())
  {
    std::cout << "max = " << maxStack.max() << std::endl;
    maxStack.pop();
  }

  return 0;
}
