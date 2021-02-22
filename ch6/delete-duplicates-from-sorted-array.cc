/*
 *  6.5
 *  Write a program which takes as input a sorted array and updates it so that all duplicates
 *    have been removed and the remaining elements have been shifted left to fill the emptied
 *    indices. Return the number of valid elements. Many languages have library functions for
 *    performing this operation - you cannot use these functions.
 */

#include <iostream>
#include <vector>

int DeleteDuplicates(std::vector<int> &v)
{
  int numDuplicates = 0;
  int numUnique = 1;
  int current = v[0];
  std::vector<int> unique(v.size(), 0);
  unique[0] = current;

  for (auto i{1}; i < v.size(); ++i)
  {
    if (current == v[i])
    {
      numDuplicates++;
    }
    else
    {
      current = v[i];
      v[numUnique] = current;
      numUnique++;
    }
  }

  return numUnique;
}

int main(int argc, char **argv)
{
  std::vector<int> v{2,3,5,5,7,11,11,11,13};

  std::cout << DeleteDuplicates(v) << std::endl;

  for (auto i{0}; i < v.size(); ++i)
    std::cout << v[i] << ",";
  std::cout << std::endl;

  return 0;
}
