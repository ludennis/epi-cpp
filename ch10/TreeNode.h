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
