/*
 *  15.2
 *  Write a program that takes as input a BST and a value, and returns the first key that would
 *    appear in an inorder traversal which is greater than the input value. For example, when
 *    applied to the BST in Figure 15.1 on Page 251 you should return 29 for input 23.
 */

#include <iostream>

#include <gtest/gtest.h>

#include <BSTNode.h>

void FindGreaterThan(const std::unique_ptr<BSTNode<int>> &tree, int target, int &result)
{
  if (tree == nullptr)
    return;
  if (tree->data > target && tree->data < result)
    result = tree->data;

  if (tree->left != nullptr && target <= tree->data)
    FindGreaterThan(tree->left, target, result);

  if (tree->right != nullptr && target >= tree->data)
    FindGreaterThan(tree->right, target, result);
}

int FindGreaterThan(const std::unique_ptr<BSTNode<int>> &tree, int target)
{
  int result = std::numeric_limits<int>::max();
  FindGreaterThan(tree, target, result);
  return result;
}

TEST(FindGreaterThanTest, UnitTest)
{
  auto tree = std::make_unique<BSTNode<int>>(19);
  tree->PushLeft(7);
  tree->left->PushLeft(3);
  tree->left->left->PushLeft(2);
  tree->left->left->PushRight(5);
  tree->left->PushRight(11);
  tree->left->right->PushRight(17);
  tree->left->right->right->PushLeft(13);
  tree->PushRight(43);
  tree->right->PushLeft(23);
  tree->right->left->PushRight(37);
  tree->right->left->right->PushLeft(29);
  tree->right->left->right->left->PushRight(31);
  tree->right->left->right->PushRight(41);
  tree->right->PushRight(47);
  tree->right->right->PushRight(53);

  EXPECT_EQ(29, FindGreaterThan(tree, 23));
  EXPECT_EQ(5, FindGreaterThan(tree, 3));
  EXPECT_EQ(5, FindGreaterThan(tree, 4));
  EXPECT_EQ(2, FindGreaterThan(tree, 0));
  EXPECT_EQ(41, FindGreaterThan(tree, 39));
  EXPECT_EQ(53, FindGreaterThan(tree, 50));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
