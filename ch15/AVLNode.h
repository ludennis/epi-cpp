#include <BSTNode.h>

template <typename T>
struct AVLNode : public BSTNode<T>
{
  AVLNode(T data)
  : BSTNode<T>::BSTNode(data)
  , leftHeight(0)
  , rightHeight(0)
  {}

  std::unique_ptr<AVLNode<T>> left, right;
  int leftHeight;
  int rightHeight;
};
