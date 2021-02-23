/*
 *  6.8
 *  Write a program that takes an integer argument and returns all the primes between 1 and the
 *    integer. For example, if the input is 18, you should return <2,3,5,7,11,13,17>
 */

#include <iostream>
#include <vector>

bool IsPrime(int n, std::vector<int> &primes)
{
  for (auto i{0}; i < primes.size(); ++i)
  {
    if (n % primes[i] == 0)
      return false;
  }

  return true;
}

std::vector<int> EnumeratePrimes(int n)
{
  std::vector<int> primes(1, 2);

  for (auto i{3}; i <= n; ++i)
  {
    if (IsPrime(i, primes))
    {
      primes.push_back(i);
    }
  }

  return primes;
}

int main(int argc, char **argv)
{
  auto primes = EnumeratePrimes(123);

  for (auto &prime : primes)
    std::cout << prime << ",";
  std::cout << std::endl;

  return 0;
}
