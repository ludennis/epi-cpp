/*
 *  9.3
 *  Write a program that tests if a string made up of the characters '(', ')', '[', ']', '{', '}'
 *    is well-formed.
 */

#include <stack>

#include <gtest/gtest.h>

bool IsWellFormed(std::string s)
{
  std::stack<char> brackets;

  for (auto &c : s)
  {
    if (brackets.size() > 0 &&
        ((brackets.top() == '(' && c == ')') ||
        (brackets.top() == '[' && c == ']') ||
        (brackets.top() == '{' && c == '}')))
      brackets.pop();
    else
      brackets.push(c);
  }

  return brackets.empty();
}

TEST(IsWellFormedTest, UnitTest)
{
  EXPECT_EQ(true, IsWellFormed("()"));
  EXPECT_EQ(false, IsWellFormed("())"));
  EXPECT_EQ(true, IsWellFormed("(())"));
  EXPECT_EQ(true, IsWellFormed("{[()]}"));
  EXPECT_EQ(false, IsWellFormed("(("));
  EXPECT_EQ(false, IsWellFormed("))"));
  EXPECT_EQ(false, IsWellFormed("{}{{(({}}{("));
  EXPECT_EQ(true, IsWellFormed("{}()[]"));
  EXPECT_EQ(true, IsWellFormed("{{{((([[[]]])))}}}"));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
