/*
 *  15.1
 *  Write a program that takes as input a binary tree and checks if the tree satisfies the
 *    BST property.
 */

#include <limits>
#include <memory>

#include <gtest/gtest.h>

template <typename T>
struct BSTNode
{
  T data;
  std::unique_ptr<BSTNode<T>> left, right;

  BSTNode(T data)
  : data(data)
  , left(nullptr)
  , right(nullptr)
  {}

  void PushLeft(T data)
  {
    left = std::make_unique<BSTNode<T>>(data);
  }

  void PushRight(T data)
  {
    right = std::make_unique<BSTNode<T>>(data);
  }
};

bool IsBst(const std::unique_ptr<BSTNode<int>> &root, int left, int right)
{
  if (root == nullptr)
    return true;
  if (root->data < left || root->data > right)
    return false;
  return IsBst(root->left, left, root->data) && IsBst(root->right, root->data, right);
}

bool IsBst(const std::unique_ptr<BSTNode<int>> &root)
{
  return IsBst(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

TEST(IsBstTest, UnitTest)
{
  auto root = std::make_unique<BSTNode<int>>(3);
  EXPECT_EQ(true, IsBst(root));

  root->PushLeft(2);
  root->PushRight(5);
  EXPECT_EQ(true, IsBst(root));

  root = nullptr;
  EXPECT_EQ(true, IsBst(root));

  root = std::make_unique<BSTNode<int>>(5);
  root->PushLeft(3);
  root->left->PushLeft(2);
  root->left->left->PushRight(3);
  root->left->PushRight(4);
  root->PushRight(10);
  root->right->PushLeft(7);
  root->right->left->PushRight(7);
  EXPECT_EQ(true, IsBst(root));

  root->right->left->PushLeft(4);
  EXPECT_EQ(false, IsBst(root));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
