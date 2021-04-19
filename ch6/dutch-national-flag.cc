/*
 *  6.1
 *  Write a program that takes an array A and an index i into A, and rearranges the elemnts such
 *    that all elements less than A[i] (the "pivot") appear first, followed by elements equal to
 *    the pivot, followed by elements greater than the pivot.
 */

#include <iostream>
#include <vector>

int traceNextGreater(std::vector<int> &v, int next, int target)
{
  for (auto i{next}; i < v.size(); ++i)
  {
    if (v[i] >= target)
      return i;
  }
}

int traceNextLesser(std::vector<int> &v, int next, int target)
{
  for (auto i{next}; i < v.size(); ++i)
  {
    if (v[v.size() - i - 1] <= target)
      return v.size() - i - 1;
  }
}

void swap(std::vector<int> &v, int a, int b)
{
  int temp = v[a];
  v[a] = v[b];
  v[b] = temp;
}

void DutchNationalFlagSort(std::vector<int> &v, int index)
{
  int target = v[index];
  int next = traceNextGreater(v, 0, target);

  // less than
  for (auto i{0}; i < v.size(); ++i)
  {
    if (v[i] < target)
    {
      swap(v, i, next);
      next = traceNextGreater(v, next, target);
    }
  }

  next = traceNextLesser(v, v.size() - 1, target);
  // greater than
  for (auto i{0}; i < v.size(); ++i)
  {
    if (v[v.size() - i - 1] > target)
    {
      swap(v, v.size() - i - 1, next);
      next = traceNextLesser(v, next, target);
    }
  }
}

void PrintVector(const std::vector<int> &v)
{
  for (auto &x : v)
    std::cout << x << ",";
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  std::vector<int> v{0,1,2,2,1,2,0,0,1,1,2,0};
  int index = 1;

  std::cout << "index = " << index << std::endl;
  PrintVector(v);
  DutchNationalFlagSort(v, index);
  PrintVector(v);
  return 0;
}
