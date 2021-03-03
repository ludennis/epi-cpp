#include <memory>

template <typename T>
struct TreeNode
{
  TreeNode<T>(T t)
  : data(t)
  , left(nullptr)
  , right(nullptr)
  {}

  T data;
  std::unique_ptr<TreeNode<T>> left;
  std::unique_ptr<TreeNode<T>> right;
};

template <typename T>
struct TreeNodeParent : public std::enable_shared_from_this<TreeNodeParent<T>>
{
  TreeNodeParent<T>(T t)
  : data(t)
  , parent(nullptr)
  , left(nullptr)
  , right(nullptr)
  {}

  void PushLeft(const T &t)
  {
    left = std::make_shared<TreeNodeParent<T>>(t);
    left->parent = TreeNodeParent<T>::shared_from_this();
  }

  void PushRight(const T &t)
  {
    right = std::make_shared<TreeNodeParent<T>>(t);
    right->parent = TreeNodeParent<T>::shared_from_this();
  }

  T data;
  std::shared_ptr<TreeNodeParent<T>> parent;
  std::shared_ptr<TreeNodeParent<T>> left;
  std::shared_ptr<TreeNodeParent<T>> right;
};
