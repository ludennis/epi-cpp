/*
 *  10.13
 *  Design an algorithm for reconstructing a binary tree from preorder traversal visit sequence
 *    that uses null to mark empty children.
 */

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <TreeNode.h>

template <typename T>
void ReconstructTree(std::unique_ptr<TreeNode<T>> &root, const std::vector<T> &preorder, int &index)
{
  if (preorder[index] == "null")
  {
    index++;
    return;
  }

  root = std::make_unique<TreeNode<T>>(preorder[index]);

  index++;

  ReconstructTree(root->left, preorder, index);
  ReconstructTree(root->right, preorder, index);
}

template <typename T>
std::unique_ptr<TreeNode<T>> ReconstructTree(const std::vector<T> &preorder)
{
  int index = 0;
  std::unique_ptr<TreeNode<T>> root;

  ReconstructTree(root, preorder, index);

  return std::move(root);
}

TEST(ReconstructTreeTest, UnitTest)
{
  std::vector<std::string> preorder{"H", "null", "null"};

  auto root = ReconstructTree(preorder);

  EXPECT_EQ("H", root->data);
  EXPECT_EQ(nullptr, root->left);
  EXPECT_EQ(nullptr, root->right);

  preorder = std::vector<std::string>{"H", "B", "null", "null", "null"};
  root = ReconstructTree(preorder);
  EXPECT_EQ("H", root->data);
  EXPECT_EQ("B", root->left->data);
  EXPECT_EQ(nullptr, root->left->left);
  EXPECT_EQ(nullptr, root->left->right);
  EXPECT_EQ(nullptr, root->right);

  preorder = std::vector<std::string>{"H","B","F","null","null","E","A","null","null","null","C",
    "null","D","null","G","I","null","null","null"};
  root = ReconstructTree(preorder);
  EXPECT_EQ("H", root->data);
  EXPECT_EQ("B", root->left->data);
  EXPECT_EQ("F", root->left->left->data);
  EXPECT_EQ("E", root->left->right->data);
  EXPECT_EQ("A", root->left->right->left->data);
  EXPECT_EQ("C", root->right->data);
  EXPECT_EQ("D", root->right->right->data);
  EXPECT_EQ("G", root->right->right->right->data);
  EXPECT_EQ("I", root->right->right->right->left->data);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
