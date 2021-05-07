#include <iostream>

#include <BSTNode.h>

template <typename T>
class AVLTree
{
public:
  AVLTree(const T &t)
  : root(std::make_unique<BSTNode<T>>(t))
  {}

  std::vector<T> GetInorder()
  {
    std::vector<T> inorder;
    GetInorder(root, inorder);
    return inorder;
  }

  std::vector<T> GetPreorder()
  {
    std::vector<T> preorder;
    GetPreorder(root, preorder);
    return preorder;
  }

  void Insert(const T &t)
  {
    if (root == nullptr)
    {
      root = std::make_unique<BSTNode<T>>(t);
      return;
    }

    auto ptr = root.get();
    while (ptr != NULL)
    {
      if (t <= ptr->data)
      {
        if (ptr->left == nullptr)
        {
          ptr->left = std::make_unique<BSTNode<T>>(t);
          return;
        }
        else
          ptr = ptr->left.get();
      }
      else
      {
        if (ptr->right == nullptr)
        {
          ptr->right = std::make_unique<BSTNode<T>>(t);
          return;
        }
        else
          ptr = ptr->right.get();
      }
    }
  }

  void RotateRight(std::unique_ptr<BSTNode<T>> &node)
  {
    if (node->left == nullptr)
      return;
    std::unique_ptr<BSTNode<T>> temp;
    temp = std::move(node->left);
    node->left = std::move(temp->right);
    temp->right = std::move(node);
    node = std::move(temp);
  }

  void RotateLeft(std::unique_ptr<BSTNode<T>> &node)
  {
    if (node->right == nullptr)
      return;
    std::unique_ptr<BSTNode<T>> temp;
    temp = std::move(node->right);
    node->right = std::move(temp->left);
    temp->left = std::move(node);
    node = std::move(temp);
  }

  std::unique_ptr<BSTNode<T>> root;

private:
  void GetInorder(const std::unique_ptr<BSTNode<T>> &root, std::vector<T> &inorder)
  {
    if (root == nullptr)
      return;
    GetInorder(root->left, inorder);
    inorder.emplace_back(root->data);
    GetInorder(root->right, inorder);
  }

  void GetPreorder(const std::unique_ptr<BSTNode<T>> &root, std::vector<T> &preorder)
  {
    if (root == nullptr)
      return;
    preorder.emplace_back(root->data);
    GetPreorder(root->left, preorder);
    GetPreorder(root->right, preorder);
  }
};

