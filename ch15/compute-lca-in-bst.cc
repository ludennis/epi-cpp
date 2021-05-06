/*
 *  15.4
 *  Design an algorithm that takes as input a BST and two nodes, and returns the LCA of the
 *    two nodes. For example, for the BST in Figure 15.1 on Page 251, and nodes C and G,
 *    your algorithm should return B. Assume all keys are distinct. Nodes do not have references
 *    to their parents.
 */

#include <gtest/gtest.h>

#include <BSTNode.h>

BSTNode<int>* ComputeLCA(BSTNode<int> *tree, int low, int high)
{
  if (tree->data >= low && tree->data <= high)
    return tree;
  if (tree->left != nullptr && tree->data > high)
    return ComputeLCA(tree->left.get(), low, high);
  if (tree->right != nullptr && tree->data < low)
    return ComputeLCA(tree->right.get(), low, high);

  return nullptr;
}

BSTNode<int>* ComputeLCA(const std::unique_ptr<BSTNode<int>> &tree,
    const std::unique_ptr<BSTNode<int>> &a, const std::unique_ptr<BSTNode<int>> &b)
{
  return (a->data < b->data) ? ComputeLCA(tree.get(), a->data, b->data)
      : ComputeLCA(tree.get(), b->data, a->data);
}

TEST(ComputeLCATest, UnitTest)
{
  auto tree = std::make_unique<BSTNode<int>>(19); // A
  tree->PushLeft(7); // B
  tree->left->PushLeft(3); // C
  tree->left->left->PushLeft(2); // D
  tree->left->left->PushRight(5); // E
  tree->left->PushRight(11); // F
  tree->left->right->PushRight(17); // G
  tree->left->right->right->PushLeft(13); // H
  tree->PushRight(43); // I
  tree->right->PushLeft(23); // J
  tree->right->left->PushRight(37); // K
  tree->right->left->right->PushLeft(29); // L
  tree->right->left->right->left->PushRight(31); // M
  tree->right->left->right->PushRight(41); // N
  tree->right->PushRight(47); // O
  tree->right->right->PushRight(53); // P

  EXPECT_EQ(tree->left.get(), ComputeLCA(tree, tree->left->left, tree->left->right->right->left));
  EXPECT_EQ(tree.get(), ComputeLCA(tree, tree->left->right, tree->right->left));
  EXPECT_EQ(tree->right->left->right.get(), ComputeLCA(tree, tree->right->left->right->left,
      tree->right->left->right));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
