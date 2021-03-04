/*
 *  10.11
 *  Write a nonrecursive program for computing the inorder traversal sequence for a binary tree.
 *    Assume nodes have parent fields.
 */

#include <iostream>
#include <vector>

#include <gtest/gtest.h>

#include <TreeNode.h>

template <typename T>
bool HasParent(const std::shared_ptr<TreeNodeParent<T>> &node)
{
  return node != nullptr && node->parent != nullptr;
}

template <typename T>
bool IsLeftChild(const std::shared_ptr<TreeNodeParent<T>> &node)
{
  return node != nullptr && HasParent(node) && node->parent->left == node;
}

template <typename T>
bool IsRightChild(const std::shared_ptr<TreeNodeParent<T>> &node)
{
  return node != nullptr && HasParent(node) && node->parent->right == node;
}

template <typename T>
std::vector<T> InorderTraversal(std::shared_ptr<TreeNodeParent<T>> root)
{
  std::vector<T> traversal;

  auto node = root;
  auto prev = root;

  while (true)
  {
    std::cout << "node = " << node->data << std::endl;
    std::cout << "traversal = ";
    for (auto &x : traversal)
      std::cout << x << ",";
    std::cout << std::endl;

    if (node == nullptr)
    {
      if (IsLeftChild(prev))
      {
        traversal.push_back(prev->data);
        traversal.push_back(prev->parent->data);
        node = prev->parent->right;
      }
      else if (IsRightChild(prev))
      {
        while (IsRightChild(prev))
          prev = prev->parent;
      }
    }
    else if (node->left != nullptr)
    {
      prev = node;
      node = node->left;
    }
  }

  return traversal;
}

TEST(InorderTraversalTest, NodeTest)
{
  std::shared_ptr<TreeNodeParent<int>> root;
  EXPECT_EQ(false, HasParent(root));

  root = std::make_shared<TreeNodeParent<int>>(1);
  root->PushLeft(2);
  root->PushRight(3);

  EXPECT_EQ(false, HasParent(root));
  EXPECT_EQ(true, HasParent(root->left));
  EXPECT_EQ(true, HasParent(root->right));

  EXPECT_EQ(true, IsLeftChild(root->left));
}

TEST(InorderTraversalTest, UnitTest)
{
  auto root = std::make_shared<TreeNodeParent<char>>('H');
  root->PushLeft('B');
  root->left->PushLeft('F');
  root->left->PushRight('E');
  root->left->right->PushLeft('A');
  root->left->right->PushRight('J');
  root->PushRight('C');
  root->right->PushRight('D');
  root->right->right->PushRight('G');
  root->right->right->right->PushLeft('I');

  std::vector<char> traversal{'F','B','A','E','J','H','C','D','I','G'};
  EXPECT_EQ(traversal, InorderTraversal(root));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
