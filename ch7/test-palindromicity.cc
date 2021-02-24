/*
 *  7.5
 *  Implement a function which takes as input a string s and returns true if s is a palindromic
 *    string.
 */

#include <iostream>
#include <string>

bool SameLetter(char c1, char c2)
{
  if (c1 == c2 || c1 + 32 == c2 || c1 - 32 == c2)
    return true;
  else
    return false;
}

bool IsLetter(char c)
{
  return (65 <= c && c <= 90) || (97 <= c && c <= 122);
}

int SeekLetter(std::string &s, int i, bool toTheRight)
{
  while (!IsLetter(s[i]))
  {
    i = (toTheRight ? i + 1 : i - 1);
    if (i == 0 || i == s.size() - 1)
      break;
  }

  return i;
}

bool IsPalindromic(std::string &s)
{
  int left = 0;
  int right = s.size() - 1;

  while (left < right)
  {
    if (!IsLetter(s[left]))
    {
      left = SeekLetter(s, left, true);
    }
    if (!IsLetter(s[right]))
    {
      right = SeekLetter(s, right, false);
    }

    if (!SameLetter(s[left], s[right]))
      return false;

    left++;
    right--;
  }

  return true;
}

int main(int argc, char **argv)
{
  std::string s = "A man, a plan, a canal, Panama.";
//  std::string s = "Ray ab Rayar";

  std::cout << IsPalindromic(s) << std::endl;

  return 0;
}
