/*
 *  15.3
 *  Write a program that takes as input a BST and an integer k, and returns the k largest
 *    elements in the BST in decreasing order. For example, if the input is the BST in Figure 15.1
 *    on Page 251 and k = 3, your program should return (53,47,43).
 */

#include <vector>

#include <gtest/gtest.h>

#include <BSTNode.h>

void KLargestInBST(const std::unique_ptr<BSTNode<int>> &tree, int k, std::vector<int> &result)
{
  if (result.size() >= k)
    return;
  if (tree->right != nullptr)
    KLargestInBST(tree->right, k, result);
  if (result.size() < k)
    result.emplace_back(tree->data);
  if (tree->left != nullptr)
    KLargestInBST(tree->left, k, result);
}

std::vector<int> KLargestInBST(const std::unique_ptr<BSTNode<int>> &tree, int k)
{
  std::vector<int> result = {};
  KLargestInBST(tree, k, result);
  return result;
}

TEST(KLargestInBSTTest, UnitTest)
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

  std::vector<int> expected = {53,47,43};
  EXPECT_EQ(expected, KLargestInBST(tree, 3));
  expected.emplace_back(41);
  EXPECT_EQ(expected, KLargestInBST(tree, 4));
  expected.emplace_back(37);
  EXPECT_EQ(expected, KLargestInBST(tree, 5));
  expected.emplace_back(31);
  EXPECT_EQ(expected, KLargestInBST(tree, 6));
  expected.emplace_back(29);
  EXPECT_EQ(expected, KLargestInBST(tree, 7));
  expected.emplace_back(23);
  EXPECT_EQ(expected, KLargestInBST(tree, 8));
  expected.emplace_back(19);
  EXPECT_EQ(expected, KLargestInBST(tree, 9));
  expected.emplace_back(17);
  EXPECT_EQ(expected, KLargestInBST(tree, 10));
  expected.emplace_back(13);
  EXPECT_EQ(expected, KLargestInBST(tree, 11));
  expected.emplace_back(11);
  EXPECT_EQ(expected, KLargestInBST(tree, 12));
  expected.emplace_back(7);
  EXPECT_EQ(expected, KLargestInBST(tree, 13));
  expected.emplace_back(5);
  EXPECT_EQ(expected, KLargestInBST(tree, 14));
  expected.emplace_back(3);
  EXPECT_EQ(expected, KLargestInBST(tree, 15));
  expected.emplace_back(2);
  EXPECT_EQ(expected, KLargestInBST(tree, 16));
  EXPECT_EQ(expected, KLargestInBST(tree, 20));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
