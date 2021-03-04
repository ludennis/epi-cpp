/*
 *  10.12
 *  Given an inorder traversal sequence and a preorder traversal sequence of a binary tree, write
 *    a program to reconstruct the tree. Assume each node has a unique key. Assume each node will
 *    hold an unique key.
 */

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <TreeNode.h>

template <typename T>
int FindInVector(const std::vector<T> &v, const T t)
{
  for (auto i{0}; i < v.size(); ++i)
  {
    if (t == v[i])
      return i;
  }

  return -1;
}

template <typename T>
void ConstructBinaryTree(std::unique_ptr<TreeNode<T>> &root, const std::vector<T> &preorder,
  int &preorderIndex, const std::vector<T> &inorder, int left, int right)
{
  if (right - left < 0 || preorderIndex >= preorder.size())
    return;

  root = std::make_unique<TreeNode<T>>(preorder[preorderIndex]);
  preorderIndex++;
  std::cout << root->data << ", left = " << left << ", right = " << right << std::endl;

  auto rootIndex = FindInVector(inorder, root->data);
  auto nextRootIndex = FindInVector(inorder, preorder[preorderIndex]);

  ConstructBinaryTree(root->left, preorder, preorderIndex, inorder, left, rootIndex - 1);
  ConstructBinaryTree(root->right, preorder, preorderIndex, inorder, rootIndex + 1, right);
}

template <typename T>
std::unique_ptr<TreeNode<T>> ConstructBinaryTree(
  const std::vector<T> &inorder, const std::vector<T> &preorder)
{
  std::unique_ptr<TreeNode<T>> root;
  int preorderIndex = 0;

  ConstructBinaryTree(root, preorder, preorderIndex, inorder, 0, inorder.size() - 1);

  return root;
}

TEST(ConstructBinaryTreeTest, UnitTest)
{
  std::string inorder = "FBAEHCDIG";
  std::string preorder = "HBFEACDGI";

  auto root = ConstructBinaryTree(std::vector<char>(inorder.begin(), inorder.end()),
    std::vector<char>(preorder.begin(), preorder.end()));

  EXPECT_EQ('H', root->data);
  EXPECT_EQ('B', root->left->data);
  EXPECT_EQ('F', root->left->left->data);
  EXPECT_EQ('E', root->left->right->data);
  EXPECT_EQ('A', root->left->right->left->data);
  EXPECT_EQ('C', root->right->data);
  EXPECT_EQ('D', root->right->right->data);
  EXPECT_EQ('G', root->right->right->right->data);
  EXPECT_EQ('I', root->right->right->right->left->data);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
