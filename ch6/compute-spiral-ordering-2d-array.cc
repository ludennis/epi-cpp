/*
 *  6.17
 *  Write a program which takes an n x n 2D array and returns the spiral ordering of the array
 */

#include <iostream>
#include <utility>
#include <vector>

enum Direction {right, down, left, up};

struct Coordinate
{
  Coordinate(int row, int col, Direction dir)
  : row(row)
  , col(col)
  , dir(dir)
  {}

  int row;
  int col;
  Direction dir;
};

Coordinate MoveNext(std::vector<std::vector<bool>> &traversed,
  Coordinate current)
{
  if (current.dir == up)
  {
    if (current.row - 1 >= 0 && traversed[current.row - 1][current.col] == false)
    {
      current.row--;
    }
    else
    {
      current.col++;
      current.dir = right;
    }
  }
  else if (current.dir == down)
  {
    if (current.row + 1 < traversed.size() && traversed[current.row + 1][current.col] == false)
    {
      current.row++;
    }
    else
    {
      current.col--;
      current.dir = left;
    }
  }
  else if (current.dir == left)
  {
    if (current.col - 1 >= 0 && traversed[current.row][current.col - 1] == false)
    {
      current.col--;
    }
    else
    {
      current.row--;
      current.dir = up;
    }
  }
  else
  {
    if (current.col + 1 < traversed[0].size() && traversed[current.row][current.col + 1] == false)
    {
      current.col++;
    }
    else
    {
      current.row++;
      current.dir = down;
    }
  }

  return current;
}

std::vector<int> GetSpiralOrder(std::vector<std::vector<int>> &m)
{
  Coordinate current{0, 0, right};

  std::vector<int> spiral(m.size() * m[0].size());
  std::vector<std::vector<bool>> traversed(m.size(), std::vector<bool>(m[0].size(), false));


  for (auto i{0}; i < spiral.size(); ++i)
  {
    std::cout << "current (" << current.row << "," << current.col << "), dir = " << current.dir << std::endl;
    std::cout << "current number = " << m[current.row][current.col] << std::endl;

    spiral[i] = m[current.row][current.col];
    traversed[current.row][current.col] = true;
    current = MoveNext(traversed, current);

    std::cout << std::endl;
  }

  return spiral;
}

int main(int argc, char **argv)
{
  std::vector<std::vector<int>> m
  {{1,2,3,100},
   {4,5,6,101},
   {7,8,9,102},
   {10,11,12,103},
   {13,14,15,104}};

  auto spiral = GetSpiralOrder(m);

  for (auto &x : spiral)
    std::cout << x << ",";
  std::cout << std::endl;

  return 0;
}
