#include <gtest/gtest.h>

#include <AVLTree.h>

TEST(AVLTreeTest, InsertTest)
{
  auto tree = AVLTree<int>(5);
  tree.Insert(3);

  std::vector<int> expect{3,5};
  EXPECT_EQ(expect, tree.GetInorder());

  tree.Insert(1);
  tree.Insert(6);
  tree.Insert(5);
  expect = {1,3,5,5,6};
  EXPECT_EQ(expect, tree.GetInorder());
  EXPECT_EQ(2, tree.root->leftHeight);
  EXPECT_EQ(2, tree.root->rightHeight);
  EXPECT_EQ(1, tree.root->left->leftHeight);
  EXPECT_EQ(0, tree.root->left->rightHeight);
  EXPECT_EQ(1, tree.root->right->leftHeight);
  EXPECT_EQ(0, tree.root->right->rightHeight);

  tree.Insert(8);
  tree.Insert(9);
  EXPECT_EQ(3, tree.root->rightHeight);
  EXPECT_EQ(2, tree.root->right->rightHeight);
  EXPECT_EQ(1, tree.root->right->leftHeight);
  EXPECT_EQ(1, tree.root->right->right->rightHeight);
  EXPECT_EQ(0, tree.root->right->right->leftHeight);

  // TODO: test if height balance is maintained
}

TEST(AVLTreeTest, RotateTest)
{
  auto tree = AVLTree<int>(10);

  tree.Rotate(tree.root, Direction::Left);
  EXPECT_EQ(10, tree.root->data);


  tree.Insert(5);
  tree.Insert(20);
  std::vector<int> expect{10,5,20};
  EXPECT_EQ(expect, tree.GetPreorder());

  tree.Rotate(tree.root, Direction::Right);
  expect = {5,10,20};
  EXPECT_EQ(expect, tree.GetPreorder());

  tree.Rotate(tree.root, Direction::Left);
  expect = {10,5,20};
  EXPECT_EQ(expect, tree.GetPreorder());

  tree.Rotate(tree.root, Direction::Left);
  expect = {20,10,5};
  EXPECT_EQ(expect, tree.GetPreorder());

  tree.Rotate(tree.root, Direction::Right);
  tree.Insert(2);
  tree.Insert(8);
  tree.Insert(3);
  tree.Insert(30);
  expect = {10,5,2,3,8,20,30};
  EXPECT_EQ(expect, tree.GetPreorder());

  tree.Rotate(tree.root->left, Direction::Right);
  expect = {10,2,5,3,8,20,30};
  EXPECT_EQ(expect, tree.GetPreorder());

  tree.Rotate(tree.root->right, Direction::Left);
  expect = {10,2,5,3,8,30,20};
  EXPECT_EQ(expect, tree.GetPreorder());

  tree.Rotate(tree.root, Direction::Right);
  expect = {2,10,5,3,8,30,20};
  EXPECT_EQ(expect, tree.GetPreorder());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
