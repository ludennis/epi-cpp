/*
 *  9.8
 *  Implement a queue API using an array for storing elements. Your API should include a
 *    constructor function, which takes as argument the initial capacity of the queue, enqueue
 *    and dequeue functions, and a function which returns the number of elements stored.
 *    Implement dynamic resizing to support storing an arbitrarily large number of elements.
 */

#include <iostream>
#include <vector>

#include <gtest/gtest.h>

template <typename T>
class CircularQueue
{
public:
  CircularQueue<T>(int size)
  : mQueue(size)
  , mFront(0)
  , mBack(0)
  , mSize(0)
  {}

  int Capacity()
  {
    return mQueue.size();
  }

  int Size()
  {
    return mSize;
  }

  T Front()
  {
    return mQueue[mFront];
  }

  T Back()
  {
    return mQueue[mBack];
  }

  void Enqueue(T t)
  {
    if (mSize > 0)
      mBack = (mBack == Capacity() - 1 ? 0 : mBack + 1);

    mQueue[mBack] = t;

    mSize = (mSize < Capacity() ? mSize + 1 : mSize);

    if (mSize == Capacity() && mFront == mBack)
      mFront = (mFront == Capacity() - 1 ? 0 : mFront + 1);
  }

  void Dequeue()
  {
    if (mSize == 0)
      return;

    mFront = (mFront == Capacity() - 1 ? 0 : mFront + 1);
    mSize--;
  }

private:
  std::vector<T> mQueue;
  int mFront;
  int mBack;
  int mSize;
};

TEST(CircularQueueTest, SizeTest)
{
  CircularQueue<int> cq(4);

  EXPECT_EQ(0, cq.Size());
  EXPECT_EQ(4, cq.Capacity());
}

TEST(CircularQueueTest, EnqueueTest)
{
  CircularQueue<int> cq(4);

  cq.Enqueue(1);
  EXPECT_EQ(1, cq.Front());
  EXPECT_EQ(1, cq.Back());

  cq.Enqueue(2);
  EXPECT_EQ(1, cq.Front());
  EXPECT_EQ(2, cq.Back());

  cq.Enqueue(3);
  EXPECT_EQ(1, cq.Front());
  EXPECT_EQ(3, cq.Back());

  cq.Enqueue(4);
  EXPECT_EQ(1, cq.Front());
  EXPECT_EQ(4, cq.Back());

  cq.Enqueue(5);
  EXPECT_EQ(2, cq.Front());
  EXPECT_EQ(5, cq.Back());

  cq.Enqueue(6);
  EXPECT_EQ(3, cq.Front());
  EXPECT_EQ(6, cq.Back());

  cq.Enqueue(7);
  EXPECT_EQ(4, cq.Front());
  EXPECT_EQ(7, cq.Back());

  cq.Enqueue(8);
  EXPECT_EQ(5, cq.Front());
  EXPECT_EQ(8, cq.Back());
}

TEST(CircularQueueTest, DequeueTest)
{
  CircularQueue<int> cq(4);

  cq.Enqueue(1);
  cq.Enqueue(2);
  cq.Enqueue(3);
  cq.Enqueue(4);
  cq.Enqueue(5);

  cq.Dequeue();
  EXPECT_EQ(3, cq.Front());
  EXPECT_EQ(5, cq.Back());

  cq.Dequeue();
  EXPECT_EQ(4, cq.Front());
  EXPECT_EQ(5, cq.Back());

  cq.Dequeue();
  EXPECT_EQ(5, cq.Front());
  EXPECT_EQ(5, cq.Back());

  cq.Dequeue();
  EXPECT_EQ(0, cq.Size());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
