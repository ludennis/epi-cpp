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

  void Insert(const T &t)
  {
    if (root == nullptr)
    {
      root = std::make_unique<AVLNode<T>>(t);
      return;
    }

    std::vector<AVLNode<T>*> traversal;
    Insert(root, t, traversal);
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

  int Insert(std::unique_ptr<AVLNode<T>> &root, const T &t,
    std::vector<AVLNode<T>*> &traversal)
  {
    if (root == nullptr)
    {
      return 0;
    }
    else if (t < root->data)
    {
      traversal.emplace_back(root.get());
      if (root->left == nullptr)
      {
        root->left = std::make_unique<AVLNode<T>>(t);
        root->leftHeight = 1;
        traversal.emplace_back(root->left.get());
        return root->leftHeight;
      }
      else
      {
        auto height = Insert(root->left, t, traversal) + 1;
        if (root->leftHeight < height)
          root->leftHeight = height;
        if (std::abs(root->leftHeight - root->rightHeight) > 1)
        {
          #ifdef DEBUG
            std::cout << "Node has height imbalance: " << root->data << ", when inserting: "
              << t << std::endl;
            std::cout << "traversal = ";
            for (auto &n : traversal)
              std::cout << n->data << ",";
            std::cout << std::endl;
          #endif

          MaintainBalance(root, traversal);
        }
        return root->leftHeight;
      }
    }
    else
    {
      traversal.emplace_back(root.get());
      if (root->right == nullptr)
      {
        root->right = std::make_unique<AVLNode<T>>(t);
        root->rightHeight = 1;
        traversal.emplace_back(root->right.get());
        return root->rightHeight;
      }
      else
      {
        auto height = Insert(root->right, t, traversal) + 1;
        if (root->rightHeight < height)
          root->rightHeight = height;
        if (std::abs(root->leftHeight - root->rightHeight) > 1)
        {
          #ifdef DEBUG
            std::cout << "Node has height imbalance: " << root->data << ", when inserting: "
              << t << std::endl;
            std::cout << "traversal = ";
            for (auto &n : traversal)
              std::cout << n->data << ",";
            std::cout << std::endl;
          #endif

          MaintainBalance(root, traversal);
        }
        return root->rightHeight;
      }
    }
  }

  void MaintainBalance(std::unique_ptr<AVLNode<T>> &root, std::vector<AVLNode<T>*> &traversal)
  {
    if (traversal.size() < 3)
      return;

    if (root->left.get() == traversal[1] && root->left->left.get() == traversal[2])
    {
      RotateRight(root);
    }
    else if (root->left.get() == traversal[1] && root->left->right.get() == traversal[2])
    {
      RotateLeft(root->left);
      RotateRight(root);
    }
    else if (root->right.get() == traversal[1] && root->right->right.get() == traversal[2])
    {
      RotateLeft(root);
    }
    else
    {
      RotateRight(root->right);
      RotateLeft(root);
    }
  }

  void RotateRight(std::unique_ptr<AVLNode<T>> &node)
  {
    #ifdef DEBUG
      std::cout << "Performed RotateRight() on " << node->data << std::endl;
    #endif

    if (node->left == nullptr)
      return;
    std::unique_ptr<AVLNode<T>> temp = std::move(node->left);
    node->left = std::move(temp->right);
    temp->right = std::move(node);
    node = std::move(temp);

    // update heights
    node->right->leftHeight = node->rightHeight;
    node->rightHeight = std::max(node->right->leftHeight, node->right->rightHeight) + 1;
  }

  void RotateLeft(std::unique_ptr<AVLNode<T>> &node)
  {
    #ifdef DEBUG
      std::cout << "Performed RotateLeft() on " << node->data << std::endl;
    #endif

    if (node->right == nullptr)
      return;
    std::unique_ptr<AVLNode<T>> temp = std::move(node->right);
    node->right = std::move(temp->left);
    temp->left = std::move(node);
    node = std::move(temp);

    // update heights
    node->left->rightHeight = node->leftHeight;
    node->leftHeight = std::max(node->left->leftHeight, node->left->rightHeight) + 1;
  }
};

