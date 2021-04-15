/*
 *  13.4
 *  Design an algorithm for computing the LCA of two nodes in a binary tree. The algorithm's
 *    time complexity should depend only on the distance from the nodes to the LCA.
 *  Assume each node has a parent pointer.
 */

#include <unordered_set>

#include <gtest/gtest.h>

#include <TreeNode.h>

template <typename T>
std::shared_ptr<TreeNodeParent<T>> GetLCA(
  std::shared_ptr<TreeNodeParent<T>> node1, std::shared_ptr<TreeNodeParent<T>> node2)
{
  std::unordered_set<std::shared_ptr<TreeNodeParent<T>>> traversedNodes;

  // alternate moving up of the two nodes, if anyone visited previously, then it's the LCA
  for (;;)
  {
    if (traversedNodes.find(node1) == traversedNodes.end())
      traversedNodes.insert(node1);
    else
      return node1;

    if (traversedNodes.find(node2) == traversedNodes.end())
      traversedNodes.insert(node2);
    else return node2;

    node1 = node1->parent;
    node2 = node2->parent;
  }

  return nullptr;
}

TEST(GetLCATest, UnitTest)
{
  auto root = std::make_shared<TreeNodeParent<int>>(1);
  root->PushLeft(2);
  root->PushRight(3);
  root->left->PushLeft(4);
  root->right->PushLeft(5);
  root->right->PushRight(6);
  root->left->left->PushLeft(7);
  root->left->left->left->PushLeft(8);
  root->left->left->left->PushRight(9);
  root->left->left->left->right->PushLeft(10);
  root->left->left->left->right->PushRight(11);

  EXPECT_EQ(1, GetLCA(root->left->left, root->right->left)->data);
  EXPECT_EQ(7, GetLCA(root->left->left->left->left, root->left->left->left->right->left)->data);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
