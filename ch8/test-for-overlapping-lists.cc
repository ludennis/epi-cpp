/*
 *  8.4
 *  Write a program that takes two cycle-free signly linked lists, and determines if there
 *    exists a node that is common to both lists.
 */

#include <iostream>

#include <ListNode.h>

bool HasCommonNode(std::shared_ptr<ListNode<int>> l1, std::shared_ptr<ListNode<int>> l2)
{
  // let l1 traverse to last node
  while (l1->next)
  {
    l1 = l1->next;
  }

  // link last node of l1 to l2
  l1->next = l2;

  // see if l2 has cycle
  auto l2Head = l2;

  while (l2)
  {
    l2 = l2->next;
    if (l2 == l2Head)
    {
      l1->next = nullptr;
      return true;
    }
  }

  l1->next = nullptr;
  return false;
}

int main(int argc, char **argv)
{
  auto l1 = std::make_shared<ListNode<int>>(1);
  l1->next = std::make_shared<ListNode<int>>(2);
  l1->next->next = std::make_shared<ListNode<int>>(3);
  l1->next->next->next = std::make_shared<ListNode<int>>(4);

  auto l2 = std::make_shared<ListNode<int>>(6);
  l2->next = std::make_shared<ListNode<int>>(5);
  l2->next->next = l1->next->next->next;

  std::cout << HasCommonNode(l1, l2) << std::endl;

  return 0;
}
