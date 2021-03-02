/*
 *  9.9
 *  Implement a queue given a library implementing stacks.
 */

#include <stack>

#include <gtest/gtest.h>

template <typename T>
class StackedQueue
{
public:
  StackedQueue<T>(){}
  void Push(T t)
  {
    mStack.push(t);
    if (mStack.size() == 1)
      mFront = mStack.top();
  }

  void Pop()
  {
    std::stack<T> temp;
    while (mStack.size() > 1)
    {
      temp.push(mStack.top());
      mStack.pop();
    }

    mFront = temp.top();
    mStack.pop();

    while (!temp.empty())
    {
      mStack.push(temp.top());
      temp.pop();
    }
  }

  T Front()
  {
    return mFront;
  }

private:
  T mFront;
  std::stack<T> mStack;
};

TEST(StackedQueueTest, PushTest)
{
  StackedQueue<int> sq;

  sq.Push(1);
  EXPECT_EQ(1, sq.Front());

  sq.Push(2);
  EXPECT_EQ(1, sq.Front());

  sq.Push(3);
  EXPECT_EQ(1, sq.Front());
}

TEST(StackedQueueTest, PopTest)
{
  StackedQueue<int> sq;

  sq.Push(1);
  sq.Push(2);
  sq.Push(3);

  sq.Pop();
  EXPECT_EQ(2, sq.Front());

  sq.Pop();
  EXPECT_EQ(3, sq.Front());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
