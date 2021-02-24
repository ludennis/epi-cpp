/*
 *  8.1
 *  Write a program that takes two lists, assumed to be sorted, and returns their merge. The only
 *    field your program can change in a node is its next field.
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

std::shared_ptr<ListNode<int>> MergeLists(const std::shared_ptr<ListNode<int>> &l1,
  const std::shared_ptr<ListNode<int>> &l2)
{
  std::shared_ptr<ListNode<int>> current = (l1->data < l2->data ? l1 : l2);
  std::shared_ptr<ListNode<int>> a = (current == l1 ? l1->next : l1);
  std::shared_ptr<ListNode<int>> b = (current == l2 ? l2->next : l2);
  std::shared_ptr<ListNode<int>> temp;

  while (a || b)
  {
    if (!b)
    {
      current->next = a;
      break;
    }
    else if (!a)
    {
      current->next = b;
      break;
    }
    else if (a->data < b->data)
    {
      current->next = a;
      a = a->next;
    }
    else
    {
      current->next = b;
      b = b->next;
    }
    current = current->next;
  }

  return (l1->data < l2->data ? l1 : l2);
}

int main(int argc, char **argv)
{
  auto l1 = std::make_shared<ListNode<int>>(2);
  l1->next = std::make_shared<ListNode<int>>(5);
  l1->next->next = std::make_shared<ListNode<int>>(7);

  PrintList(l1);

  auto l2 = std::make_shared<ListNode<int>>(3);
  l2->next = std::make_shared<ListNode<int>>(11);

  PrintList(l2);

  auto l = MergeLists(l1, l2);

  PrintList(l);

  return 0;
}
