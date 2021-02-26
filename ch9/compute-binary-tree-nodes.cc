/*
 *  9.7
 *  Given a binary tree, return an array consiting of the keys at the same level. Keys should
 *    appear in the order of the corresponding nodes' depths, breaking ties from left to right.
 *    For example, you should return ((314),(6,6),(271,561,2,271),(28,0,3,1,28),(17,401,257),(641))
 *    for binary tree
 */

#include <iostream>
#include <memory>
#include <vector>

template <typename T>
struct TreeNode
{
  TreeNode<T>(T t)
  : data(t)
  , left(nullptr)
  , right(nullptr)
  {}

  T data;
  std::shared_ptr<TreeNode<T>> left;
  std::shared_ptr<TreeNode<T>> right;
};

void BinaryTreeNodes(std::shared_ptr<TreeNode<int>> root, int depth,
  std::vector<std::vector<int>> &nodes)
{
  if (!root)
    return;

  if (nodes.size() <= depth)
    nodes.emplace_back(std::vector<int>{root->data});
  else
    nodes[depth].emplace_back(root->data);

  BinaryTreeNodes(root->left, depth + 1, nodes);
  BinaryTreeNodes(root->right,  depth + 1, nodes);
}

std::vector<std::vector<int>> BinaryTreeNodes(std::shared_ptr<TreeNode<int>> root)
{
  std::vector<std::vector<int>> nodes;

  BinaryTreeNodes(root, 0, nodes);

  return nodes;
}

int main(int argc, char **argv)
{
  auto root = std::make_shared<TreeNode<int>>(314);
  root->left = std::make_shared<TreeNode<int>>(6);
  root->right = std::make_shared<TreeNode<int>>(6);
  root->left->left = std::make_shared<TreeNode<int>>(271);
  root->left->right = std::make_shared<TreeNode<int>>(561);
  root->right->left = std::make_shared<TreeNode<int>>(2);
  root->right->right = std::make_shared<TreeNode<int>>(271);

  auto nodes = BinaryTreeNodes(root);

  for (auto &v : nodes)
  {
    for (auto &x : v)
    {
      std::cout << x << ",";
    }
    std::cout << std::endl;
  }

  return 0;
}
