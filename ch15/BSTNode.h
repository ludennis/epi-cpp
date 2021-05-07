#include <memory>

template <typename T>
struct BSTNode
{
  T data;
  std::unique_ptr<BSTNode<T>> left, right;

  BSTNode(T data)
  : data(data)
  , left(nullptr)
  , right(nullptr)
  {}

  void PushLeft(const T &data)
  {
    left = std::make_unique<BSTNode<T>>(data);
  }

  void PushRight(const T &data)
  {
    right = std::make_unique<BSTNode<T>>(data);
  }
};

