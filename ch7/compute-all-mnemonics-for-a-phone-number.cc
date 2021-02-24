/*
 *  7.7
 *  Write a program which takes as input a phone number, specified as a string of digits, and
 *    returns all possible character sequences that correspond to the phone number. The cell phone
 *    keypad is specified by a mapping that takes a digit and returns the corresponding set of
 *    characters. The character sequences do not have to be legal words or phrases.
 */

#include <iostream>
#include <string>
#include <vector>

std::string GetCharacters(char c)
{
  if (c == '2')
    return "ABC";
  else if (c == '3')
    return "DEF";
  else if (c == '4')
    return "GHI";
  else if (c == '5')
    return "JKL";
  else if (c == '6')
    return "MNO";
  else if (c == '7')
    return "PQRS";
  else if (c == '8')
    return "TUV";
  else
    return "WXYZ";
}

void GetSequences(std::string &number, int index, std::string sequence,
  std::vector<std::string> &result)
{
  if (index >= number.size())
  {
    result.push_back(sequence);
    return;
  }

  for (auto &c : GetCharacters(number[index]))
  {
    GetSequences(number, index + 1, sequence + c, result);
  }
}

std::vector<std::string> GetSequences(std::string &number)
{
  std::vector<std::string> result;
  GetSequences(number, 0, "", result);

  return result;
}

int main(int argc, char **argv)
{
//  std::string number = "2276696";
  std::string number = "23";

  auto sequences = GetSequences(number);

  for (auto &s : sequences)
    std::cout << s << std::endl;

  return 0;
}
