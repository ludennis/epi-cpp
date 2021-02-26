/*
 *  8.7
 *  Given a singly linked list and an integer k, write a program to remove the kth last element
 *    from the list. Your algorithm cannot use more than a few words of storage, regardless of
 *    the length of the list. In particular, you cannot assume that it is possible to record
 *    the length of the list.
 */

#include <iostream>

#include <ListNode.h>

void PrintList(std::shared_ptr<ListNode<int>> l)
{
  while (l)
  {
    std::cout << l->data << " -> ";
    l = l->next;
  }

  std::cout << std::endl;
}

void RemoveKthLast(std::shared_ptr<ListNode<int>> &l, int k)
{
  if (k <= 0)
    return;

  auto track = l;
  auto prev = l;
  auto head = l;

  for (auto i{0}; i < k; ++i)
  {
    if (!track)
      return;
    track = track->next;
  }

  while (track)
  {
    prev = head;
    head = head->next;
    track = track->next;
  }

  // removing the first element
  if (prev == head)
    l = l->next;

  // with shared_ptr, removing any pointee of l should cause it to call its destructor
  prev->next = head->next;
}

int main(int argc, char **argv)
{
  auto l = std::make_shared<ListNode<int>>(1);
  l->next = std::make_shared<ListNode<int>>(2);
  l->next->next = std::make_shared<ListNode<int>>(3);
  l->next->next->next = std::make_shared<ListNode<int>>(4);

  PrintList(l);

  RemoveKthLast(l, 1);

  PrintList(l);

  return 0;
}
