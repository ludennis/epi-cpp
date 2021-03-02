/*
 *  10.1
 *  Write a program that takes as input the root of a binary tree and checks whether the tree
 *    is height-balanced.
 */

#include <gtest/gtest.h>

#include <TreeNode.h>

int GetHeight(std::unique_ptr<TreeNode<int>> &root)
{
  if (root == nullptr)
    return 0;

  return std::max(GetHeight(root->left) + 1, GetHeight(root->right) + 1);
}

bool IsHeightBalanced(std::unique_ptr<TreeNode<int>> &root)
{
  if (root == nullptr)
    return true;

  return std::abs(GetHeight(root->left) - GetHeight(root->right)) <= 1 &&
    IsHeightBalanced(root->left) && IsHeightBalanced(root->right);
}

TEST(IsHeightBalancedTest, GetHeightTest)
{
  auto root = std::make_unique<TreeNode<int>>(1);
  EXPECT_EQ(1, GetHeight(root));

  root->left = std::make_unique<TreeNode<int>>(2);
  EXPECT_EQ(2, GetHeight(root));

  root->left->left = std::make_unique<TreeNode<int>>(3);
  EXPECT_EQ(3, GetHeight(root));
  EXPECT_EQ(2, GetHeight(root->left));
  EXPECT_EQ(0, GetHeight(root->right));
}

TEST(IsHeightBalancedTest, UnitTest)
{
  auto root = std::make_unique<TreeNode<int>>(1);
  EXPECT_EQ(true, IsHeightBalanced(root));

  root->left = std::make_unique<TreeNode<int>>(2);
  EXPECT_EQ(true, IsHeightBalanced(root));

  root->left->left = std::make_unique<TreeNode<int>>(3);
  EXPECT_EQ(false, IsHeightBalanced(root));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
