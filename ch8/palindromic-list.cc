/*
 *  8.11
 *  Write a program that tests whether a singly linked list is palindromic.
 */

#include <iostream>

#include <ListNode.h>

std::shared_ptr<ListNode<int>> Seek(std::shared_ptr<ListNode<int>> l, int n)
{
  for (auto i{0}; i < n; ++i)
    if (l)
      l = l->next;

  return l;
}

bool IsListPalindromic(std::shared_ptr<ListNode<int>> head)
{
  auto mid = head;
  auto track = head->next;
  int size = 1;

  while (track && track->next)
  {
    mid = mid->next;

    if (track)
    {
      track = track->next;
      size++;
    }

    if (track)
    {
      track = track->next;
      size++;
    }
  }

  std::cout << "size = " << size << std::endl;

  std::cout << "mid = " << mid->data << std::endl;


  for (auto i{0}; i < size / 2 ; ++i)
  {
    std::cout << "left = " << (Seek(head,i))->data << std::endl;
    std::cout << "right = " << Seek(mid, size / 2 - i)->data << std::endl;
    if ((Seek(head, i))->data != (Seek(mid, size / 2 - i))->data)
      return false;
  }

  return true;
}

int main(int argc, char **argv)
{
  auto l = std::make_shared<ListNode<int>>(1);
  l->next = std::make_shared<ListNode<int>>(2);
  l->next->next = std::make_shared<ListNode<int>>(3);
  l->next->next->next = std::make_shared<ListNode<int>>(2);
  l->next->next->next->next = std::make_shared<ListNode<int>>(1);

  std::cout << IsListPalindromic(l) << std::endl;

  return 0;
}
