/*
 *  12.5
 *  Implement a function which takes as input a floating point value and returns its square root.
 */

#include <math.h>
#include <iostream>

#include <gtest/gtest.h>

bool AlmostEqual(double a, double b)
{
//  std::cout << "Comparing => " << a << " vs " << b << std::endl;
//  std::cout << "epsilon = " << std::numeric_limits<double>::epsilon() << std::endl;
//  std::cout << "diff = " << std::fabs(a - b) << std::endl;
  if (std::fabs(a - b) <= std::numeric_limits<double>::epsilon() * 100)
    return true;
  else
    return false;
}

double FindSquareRoot(double target, double left, double right)
{
  double root = left + (right - left) / 2;
//  std::cout << "root = " << root << ", root^2 = " << root * root << std::endl;
  if (AlmostEqual(root * root, target))
    return root;
  if (root * root < target)
    return FindSquareRoot(target, root, right);
  else
    return FindSquareRoot(target, left, root);
}

double GetSquareRoot(double x)
{
  auto root = FindSquareRoot(x, 1.0, x);
}

TEST(GetSquareRootTest, UnitTest)
{
  EXPECT_EQ(3.25, GetSquareRoot(10.5625));
  EXPECT_EQ(3, GetSquareRoot(9));
  EXPECT_EQ(5.65685, GetSquareRoot(32));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
