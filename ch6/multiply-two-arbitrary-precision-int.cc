/*
 *  6.3
 *  Write a program that  takes two arrays representing integers, and returns an integer
 *    representing their product. For example, since 193707721 * -761838257287 =
 *    -147573952589676412927, if the inputs are <1,9,3,7,0,7,7,2,1> and <-7,6,1,8,3,8,2,5,7,2,8,7>,
 *    your function should return <-1,4,7,5,7,3,9,5,2,5,8,9,6,7,6,4,1,2,9,2,7>.
 */

#include <iostream>
#include <vector>

void AddDigit(std::vector<int> &v, int d, int offset)
{
  v[v.size() - 1 - offset] += d;
  if (v[v.size() - 1 - offset] / 10 > 0)
  {
    v[v.size() - 1 - offset] %= 10;
    v[v.size() - 2 - offset] += 1;
  }
}

void Add(std::vector<int> &v, int x, int offset)
{
  // 0 <= x <= 81
  while (x > 0)
  {
    AddDigit(v, x % 10, offset++);
    x /= 10;
  }
}

std::vector<int> Multiply(std::vector<int> &a, std::vector<int> &b)
{
  // TODO: determine negativity
  bool negative;
  if ((a[0] > 0 && b[0] > 0) || (a[0] < 0 && b[0] < 0))
    negative = false;
  else
    negative = true;

  a[0] = std::abs(a[0]);
  b[0] = std::abs(b[0]);

  std::vector<int> product(a.size() + b.size(), 0);

  for (auto i{0}; i < a.size(); ++i)
  {
    for (auto j{0}; j < b.size(); ++j)
    {
      Add(product, a[a.size() - 1 - i] * b[b.size() - 1 - j], i + j);
    }
  }

  if (product[0] == 0)
    product.erase(product.begin());

  if (negative == true)
    product[0] *= -1;

  return product;
}

int main(int argc, char **argv)
{

  std::vector<int> a{1,9,3,7,0,7,7,2,1};
  std::vector<int> b{-7,6,1,8,3,8,2,5,7,2,8,7};

  auto product = Multiply(a, b);

  for (auto &x : product)
    std::cout << x << ",";
  std::cout << std::endl;

  return 0;
}
