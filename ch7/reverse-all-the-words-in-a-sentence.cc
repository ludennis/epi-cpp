/*
 *  7.6
 *  Implement a function for reversing the words in a string s
 */

#include <iostream>
#include <string>

void Swap(std::string &s, int i, int j)
{
  s[j] += s[i];
  s[i] = s[j] - s[i];
  s[j] = s[j] - s[i];
}
void Reverse(std::string &s, int left, int right)
{
  while (left < right)
  {
    Swap(s, left, right);
    left++;
    right--;
  }
}

void CorrectWords(std::string &s)
{
  int left = 0;
  int right = 0;

  for (auto i{0}; i < s.size(); ++i)
  {
    if (s[i] == ' ')
    {
      Reverse(s, left, right - 1);
      left = i + 1;
      right = i + 1;
    }
    else if (i == s.size() - 1)
    {
      Reverse(s, left, right);
    }
    else
    {
      right++;
    }
  }
}

void ReverseStrings(std::string &s)
{
  Reverse(s, 0, s.size() - 1);

  std::cout << s << std::endl;

  CorrectWords(s);
}

int main(int argc, char **argv)
{
//  std::string s = "Alice likes Bob";
  std::string s = "I am a banana";

  ReverseStrings(s);

  std::cout << s << std::endl;

  return 0;
}
