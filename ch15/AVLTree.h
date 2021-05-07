#include <iostream>

#include <AVLNode.h>

enum Direction {Left, Right};

template <typename T>
class AVLTree
{
public:
  std::unique_ptr<AVLNode<T>> root;

  AVLTree(const T &t)
  : root(std::make_unique<AVLNode<T>>(t))
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

  // TODO: call RotateLeft() and/or RotateRight() to maintain height balance
  void Insert(const T &t)
  {
    if (root == nullptr)
    {
      root = std::make_unique<AVLNode<T>>(t);
      return;
    }

    Insert(root, t);
  }

  void Rotate(std::unique_ptr<AVLNode<T>> &node, Direction dir)
  {
    if (dir == Left)
      RotateLeft(node);
    else
      RotateRight(node);
  }

private:
  void GetInorder(const std::unique_ptr<AVLNode<T>> &root, std::vector<T> &inorder)
  {
    if (root == nullptr)
      return;
    GetInorder(root->left, inorder);
    inorder.emplace_back(root->data);
    GetInorder(root->right, inorder);
  }

  void GetPreorder(const std::unique_ptr<AVLNode<T>> &root, std::vector<T> &preorder)
  {
    if (root == nullptr)
      return;
    preorder.emplace_back(root->data);
    GetPreorder(root->left, preorder);
    GetPreorder(root->right, preorder);
  }

  int Insert(const std::unique_ptr<AVLNode<T>> &root, const T &t)
  {
    if (root == nullptr)
    {
      return 0;
    }
    else if (t < root->data)
    {
      if (root->left == nullptr)
      {
        root->left = std::make_unique<AVLNode<T>>(t);
        root->leftHeight = 1;
        return root->leftHeight;
      }
      else
      {
        auto height = Insert(root->left, t) + 1;
        if (root->leftHeight < height)
          root->leftHeight = height;
        return root->leftHeight;
      }
    }
    else
    {
      if (root->right == nullptr)
      {
        root->right = std::make_unique<AVLNode<T>>(t);
        root->rightHeight = 1;
        return root->rightHeight;
      }
      else
      {
        auto height = Insert(root->right, t) + 1;
        if (root->rightHeight < height)
          root->rightHeight = height;
        return root->rightHeight;
      }
    }
  }

  void RotateRight(std::unique_ptr<AVLNode<T>> &node)
  {
    if (node->left == nullptr)
      return;
    std::unique_ptr<AVLNode<T>> temp;
    temp = std::move(node->left);
    node->left = std::move(temp->right);
    temp->right = std::move(node);
    node = std::move(temp);
  }

  // TODO: to be put into private
  void RotateLeft(std::unique_ptr<AVLNode<T>> &node)
  {
    if (node->right == nullptr)
      return;
    std::unique_ptr<AVLNode<T>> temp;
    temp = std::move(node->right);
    node->right = std::move(temp->left);
    temp->left = std::move(node);
    node = std::move(temp);
  }
};

