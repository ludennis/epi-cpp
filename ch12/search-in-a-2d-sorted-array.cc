/*
 *  12.6
 *  Design an algorithm that takes a 2D-sorted array and a number and checks whether that number
 *    appears in the array. For example, if the input is the 2D sorted array in Figure 12.3, and
 *    the number if 7, your algorithm should return false; if the number if 8, your algorithm
 *    should return true.
 */

#include <utility>
#include <vector>

#include <gtest/gtest.h>

enum CutDirection {Horizontal, Vertical};

void PrintPair(const std::pair<int,int> &p)
{
  std::cout << "(" << p.first << "," << p.second << ")" << std::endl;
}

int Get(const std::vector<std::vector<int>> &matrix, const std::pair<int,int> &p)
{
  return matrix[p.first][p.second];
}

bool In2DSortedArray(const std::vector<std::vector<int>> &matrix, int target,
  std::pair<int,int> minIndex, std::pair<int,int> maxIndex, CutDirection cutDirection)
{
  std::cout << "min = " << Get(matrix, minIndex) << ", max = "
    << Get(matrix, maxIndex) << std::endl;
  std::cout << "minIndex = "; PrintPair(minIndex);
  std::cout << "maxIndex = "; PrintPair(maxIndex);

  if (target < matrix[minIndex.first][minIndex.second] ||
      target > matrix[maxIndex.first][maxIndex.second])
    return false;

  if (minIndex == maxIndex)
    if (matrix[minIndex.first][minIndex.second] != target)
      return false;
    else
      return true;

  if (matrix[minIndex.first][minIndex.second] == target ||
      matrix[maxIndex.first][maxIndex.second] == target)
    return true;

  if (cutDirection == Horizontal)
  {
    return
      In2DSortedArray(matrix, target, minIndex,
        std::make_pair(maxIndex.first / 2, maxIndex.second), CutDirection{Vertical}) ||
      In2DSortedArray(matrix, target,
        std::make_pair(minIndex.first + maxIndex.first / 2 + 1, minIndex.second), maxIndex,
        CutDirection{Vertical});
  }
  else
  {
    return
      In2DSortedArray(matrix, target, minIndex,
        std::make_pair(maxIndex.first, maxIndex.second / 2), CutDirection{Horizontal}) ||
      In2DSortedArray(matrix, target,
        std::make_pair(minIndex.first, minIndex.second + maxIndex.second / 2 + 1), maxIndex,
        CutDirection{Horizontal});
  }
}

bool In2DSortedArray(const std::vector<std::vector<int>> &matrix, int target)
{
  return In2DSortedArray(matrix, target, std::make_pair(0,0),
    std::make_pair(matrix.size() - 1, matrix[0].size() - 1), CutDirection{Horizontal});
}

TEST(In2DSortedArrayTest, UnitTest)
{
  std::vector<std::vector<int>> matrix
  {{-1,2,4,4,6},
   {1,5,5,9,21},
   {3,6,6,9,22},
   {3,6,8,10,24},
   {6,8,9,12,25},
   {8,10,12,13,40}};

  EXPECT_EQ(true, In2DSortedArray(matrix, 21));
  EXPECT_EQ(false, In2DSortedArray(matrix, 11));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
