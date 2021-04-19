/*
 *  5.11
 *  Write a program which tests if two rectanges have a nonempty intersection. If the intersection
 *    is nonempty, return the rectange formed by their intersection.
 */

#include <utility>

struct Rectangle
{
  Rectangle(std::pair<int,int> topLeft, std::pair<int,int> botRight)
  : topLeft(topLeft)
  , botRight(botRight)
  {}

  std::pair<int,int> topLeft;
  std::pair<int,int> botRight;
};

Rectangle GetIntersection(Rectangle &a, Rectangle &b)
{
 
}

int main(int argc, char **argv)
{
  Rectangle a({0,0}, {2,2});
  Rectangle b({2,2}, {4,4});

  return 0;
}
