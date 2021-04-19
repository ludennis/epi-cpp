/*
 *  12.9
 *  Suppose you were given a file containing roughly one billion IP addresses, each of which is
 *    a 32-bit quantity. How would you programmatically find an IP address that is not in that
 *    file? Assume you have unlimited drive space but only a few megabytes of RAM at your disposal.
 */

#include <fstream>
#include <iostream>
#include <vector>

#include <gtest/gtest.h>

std::vector<unsigned int> FindMissingIP(const std::string &filename = "addresses.txt")
{
  std::ifstream file(filename, std::ifstream::in);

  std::vector<unsigned int> counts(8 * 8);
  unsigned int address;

  // count the addresses against its 8 MSB, check if it's less than 2^24
  while (file >> address)
  {
    std::cout << "address = " << address << std::endl;
    counts[address >> 24]++;
  }

  for (auto &count : counts)
    std::cout << "Count[i] = " << count << std::endl;

  // count the addresses against its 16 MSB, check if it's less than 2^16

  // count the addresses against its 24 MSB, check if it's less than 2^8

  file.close();

  return counts;
}

TEST(FindMissingIPTest, UnitTest)
{
  auto missingAddresses = FindMissingIP("addresses.txt");
}

int main(int argc, char **argv)
{

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
