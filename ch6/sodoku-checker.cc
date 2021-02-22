/*
 *  6.16
 *  Check whether a 9x9 2D array representing a partialy completed sodoku is valid.
 *  Specifically, check that no row, column, or 3x3 2D subarray contains duplicates. A 0-value in
 *    the 2D array indicates that entry is blank; every other entry is in [1,9]
 */

#include <array>
#include <iostream>
#include <vector>

bool HasRowDuplicates(std::vector<std::vector<int>> &m, int row)
{
  std::array<bool, 10> a;
  a.fill(false);

  for (auto i{0}; i < 9; ++i)
  {
    if (a[m[row][i]] == 0)
      continue;
    if (a[m[row][i]] == true)
      return true;
    else
      a[m[row][i]] = true;
  }

  return false;
}

bool HasColDuplicates(std::vector<std::vector<int>> &m, int col)
{
  std::array<bool, 10> a;
  a.fill(false);

  for (auto i{0}; i < 9; ++i)
  {
   if (a[m[i][col]] == 0)
      continue;
   if (a[m[i][col]] == true)
      return true;
    else
      a[m[i][col]] = true;
  }

  return false;
}

bool HasBlockDuplicates(std::vector<std::vector<int>> &m, int block)
{
  // block order = top row left to top right, then second row left to right
  std::array<bool, 10> a;
  a.fill(false);

  for (auto i{0}; i < 9; ++i)
  {
    if (a[m[i/3][i%3]] == 0)
      continue;
    if (a[m[i/3][i%3]] == true)
      return true;
    else
      a[m[i/3][i%3]] = true;
  }

  return false;
}

bool IsSodokuValid(std::vector<std::vector<int>> &m)
{
  for (auto i{0}; i < 9; ++i)
  {
    if (HasRowDuplicates(m, i) || HasColDuplicates(m, i) || HasBlockDuplicates(m, i))
      return false;
  }

  return true;
}

int main(int argc, char **argv)
{
  std::vector<std::vector<int>> m
  {{1,2,3,4,5,6,7,8,9},
   {4,5,6,7,8,9,1,2,3},
   {7,8,9,1,2,3,4,5,6},
   {2,3,4,5,6,7,8,9,1},
   {5,6,7,8,9,1,2,3,4},
   {8,9,1,2,3,4,5,6,7},
   {3,4,0,6,7,8,9,1,2},
   {6,7,8,9,1,2,3,4,5},
   {9,1,0,3,4,5,6,7,8}};

  std::cout << IsSodokuValid(m) << std::endl;

  return 0;
}
