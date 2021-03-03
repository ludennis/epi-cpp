/*
 *  10.4
 *  Given two nodes in a binary tree, design an algorithm that computes their LCA. Assume that
 *    each node has a parent pointer.
 */

#include <gtest/gtest.h>

#include <TreeNode.h>

template <typename T>
int GetNodeDepth(const std::shared_ptr<TreeNodeParent<T>> &root,
  const std::shared_ptr<TreeNodeParent<T>> &node, int depth = 1)
{
  if (root == nullptr)
    return 0;
  if (root == node)
    return depth;

  return std::max(GetNodeDepth(root->left, node, depth + 1),
    GetNodeDepth(root->right, node, depth + 1));
}

template <typename T>
std::shared_ptr<TreeNodeParent<T>> ComputeLCA(const std::shared_ptr<TreeNodeParent<T>> &root,
  std::shared_ptr<TreeNodeParent<T>> n1, std::shared_ptr<TreeNodeParent<T>> n2)
{
  // traverse to find each node, bring both to same depth
  // then iterate to parents until they meet
  int n1Depth = GetNodeDepth(root, n1);
  int n2Depth = GetNodeDepth(root, n2);

  while (n1Depth > n2Depth)
  {
    n1 = n1->parent;
    n1Depth--;
  }

  while (n2Depth > n1Depth)
  {
    n2 = n2->parent;
    n2Depth--;
  }

  while (n1 != n2)
  {
    n1 = n1->parent;
    n2 = n2->parent;
  }

  return n1;
}

TEST(TreeNodeParentClassTest, UnitTest)
{
  auto root = std::make_shared<TreeNodeParent<int>>(1);
  root->PushLeft(2);
  root->left->PushLeft(3);
  root->PushRight(4);

  EXPECT_EQ(1, root->data);
  EXPECT_EQ(2, root->left->data);
  EXPECT_EQ(1, root->left->parent->data);
  EXPECT_EQ(1, root->right->parent->data);
  EXPECT_EQ(3, root->left->left->data);
  EXPECT_EQ(4, root->right->data);
}

TEST(ComputeLCATest, GetNodeDepthTest)
{
  auto root = std::make_shared<TreeNodeParent<int>>(1);
  root->PushLeft(2);
  root->left->PushLeft(3);
  root->PushRight(4);

  EXPECT_EQ(1, GetNodeDepth(root, root));
  EXPECT_EQ(2, GetNodeDepth(root, root->left));
  EXPECT_EQ(2, GetNodeDepth(root, root->right));
  EXPECT_EQ(3, GetNodeDepth(root, root->left->left));
}

TEST(ComputeLCATest, UnitTest)
{
  auto root = std::make_shared<TreeNodeParent<int>>(1);
  root->PushLeft(2);
  root->PushRight(3);
  root->left->PushLeft(4);
  root->left->PushRight(5);
  root->right->PushLeft(6);
  root->right->PushRight(7);
  root->left->right->PushLeft(8);
  root->right->right->PushLeft(9);

  EXPECT_EQ(1, (ComputeLCA(root, root, root))->data);
  EXPECT_EQ(1, (ComputeLCA(root, root->left, root->right))->data);
  EXPECT_EQ(1, (ComputeLCA(root, root->left, root))->data);
  EXPECT_EQ(2, (ComputeLCA(root, root->left->left, root->left->right->left))->data);
  EXPECT_EQ(1, (ComputeLCA(root, root->left->left, root->right->right->left))->data);
  EXPECT_EQ(3, (ComputeLCA(root, root->right->left, root->right->right->left))->data);
  EXPECT_EQ(1, (ComputeLCA(root, root->left, root->right->right->left))->data);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

  return 0;
}
