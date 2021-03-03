/*
 *  10.2
 *  Write a program that checks whether a binary tree is symmetric.
 */

#include <gtest/gtest.h>

#include <TreeNode.h>

template <typename T>
bool IsSymmetric(std::unique_ptr<TreeNode<T>> &leftNode, std::unique_ptr<TreeNode<T>> &rightNode)
{
  // left subtree traverse order = (left, root, right)
  // right subtree traverse order = (right, root, left)
  if (leftNode == nullptr && rightNode == nullptr)
    return true;

  if ((leftNode == nullptr && rightNode != nullptr) ||
      (leftNode != nullptr && rightNode == nullptr))
    return false;

  return IsSymmetric(leftNode->left, rightNode->right) &&
    leftNode->data == rightNode->data &&
    IsSymmetric(leftNode->right, rightNode->left);
}

template <typename T>
bool IsSymmetric(const std::unique_ptr<TreeNode<T>> &root)
{
  if (root == nullptr || (root != nullptr && root->left == nullptr && root->right == nullptr))
    return true;

  return IsSymmetric(root->left, root->right);
}

TEST(IsSymmetricTest, UnitTest)
{
  std::unique_ptr<TreeNode<int>> root;
  EXPECT_EQ(true, IsSymmetric(root));

  root = std::make_unique<TreeNode<int>>(1);
  EXPECT_EQ(true, IsSymmetric(root));

  root->PushLeft(2);
  EXPECT_EQ(false, IsSymmetric(root));

  root->PushRight(2);
  EXPECT_EQ(true, IsSymmetric(root));

  root->left->PushRight(3);
  root->right->PushLeft(3);
  EXPECT_EQ(true, IsSymmetric(root));

  // structural symmetric but not value symmetric
  root->left->right->PushLeft(4);
  root->right->left->PushRight(3);
  EXPECT_EQ(false, IsSymmetric(root));

  // structural asymmetric
  root->right->left->PushRight(4);
  root->right->left->right->PushLeft(5);
  EXPECT_EQ(false, IsSymmetric(root));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
