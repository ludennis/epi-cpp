/*
 *  7.4
 *  Write a program which takes as input an array of characters, and removes each 'b' and replaces
 *    each 'a' by two 'd's. Specifically, along with the array, you are provided an integer-valued
 *    size. Size denotes the number of entries of the array that the operation is to be applied to.
 */

#include <iostream>
#include <string>
#include <queue>

void RemoveAndReplace(std::string &s, int size)
{
  // first pass remove b
  std::queue<char> q;
  for (auto i{0}; i < s.size(); ++i)
  {
    if (s[i] == 'b')
      s[i] = ' ';
    else
      q.push(s[i]);
  }

  // second pass replace a with dd
  int index = 0;
  while (!q.empty())
  {
    if (q.front() == 'a')
    {
      s[index] = 'd';
      s[index + 1] = 'd';
      index += 2;
    }
    else if (q.front() != ' ')
      s[index++] = q.front();
    q.pop();
  }
}

int main(int argc, char **argv)
{
  std::string s = "aaaeee";

  RemoveAndReplace(s, 3);

  std::cout << s << std::endl;

  return 0;
}
