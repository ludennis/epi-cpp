#include <stdio.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

void WriteRandomIntegersToFile(const std::string &filename, unsigned int max,
  std::set<unsigned int> missing)
{
  std::ofstream file(filename, std::ofstream::out | std::ofstream::binary);
  file.open(filename);

  std::vector<unsigned int> numbers(max);

  for (auto i{0}; i < max; ++i)
    numbers[i] = i;

  std::random_shuffle(numbers.begin(), numbers.end());

  for (auto &number : numbers)
    if (missing.find(number) == missing.end())
      file << number << std::endl;

  file.close();
}

int main(int argc, char **argv)
{
  WriteRandomIntegersToFile("addressses.txt", std::numeric_limits<int>::max(),
    std::set<unsigned int>{1,10,100,1000,10000,3232235521});

  return 0;
}
