/*
 *  9.4
 *  Write a program which takes a pathname, and returns the shortest equivalent pathname. Assume
 *    individual directories and files have names that use only alphanumeric characters. Sub-
 *    directory names may be combined using forward slashes (/), the current directory (.), and
 *    parent directory (..).
 */

#include <iostream>
#include <stack>
#include <string>

#include <gtest/gtest.h>

std::string NormalizePathnames(std::string path)
{
  std::stack<std::string> traversal;
  std::string delimiter = "/";
  bool fromRoot = false;
  std::size_t found;
  std::string token;
  std::string result;

  if (path[0] == '/')
    fromRoot = true;

  while (!path.empty())
  {
    found = path.find(delimiter);
    if (found == std::string::npos)
    {
      token = path;
      path = "";
    }
    else
    {
      token = path.substr(0, found);
      path.erase(0, found + delimiter.length());
    }

    if (token == "..")
      traversal.pop();
    else if (token != "." && token != "")
      traversal.push(token);
  }

  while (!traversal.empty())
  {
    if (result == "")
      result = traversal.top();
    else
      result = traversal.top() + "/" + result;
    traversal.pop();
  }

  if (fromRoot)
    result = "/" + result;

  return result;
}

TEST(NormalizePathnamesTest, UnitTest)
{
  EXPECT_EQ("/usr/bin/gcc", NormalizePathnames("/usr/bin/gcc"));
  EXPECT_EQ("/usr/bin/gcc", NormalizePathnames("/usr/lib/../bin/gcc"));
  EXPECT_EQ("scripts/awkscripts", NormalizePathnames("scripts/awkscripts"));
  EXPECT_EQ("scripts/awkscripts", NormalizePathnames("scripts//./../scripts/awkscripts/././"));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
