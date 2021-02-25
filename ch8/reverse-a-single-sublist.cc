/*
 *  8.2
 *  Write a program which takes a singly linked list L and two integers s and f as arguments,
 *    and reverses the order of the nodes from the sth node to the fth node, inclusive. The
 *    numbering begins at 1, i.e., the head node is the first node. Do not allocate additional
 *    nodes.
 */

#include <iostream>

#include <ListNode.h>

void PrintList(std::shared_ptr<ListNode<int>> head)
{
  while (head)
  {
    std::cout << head->data << " -> ";
    head = head->next;
  }

  std::cout << std::endl;
}

void ReverseSublist(std::shared_ptr<ListNode<int>> &h, int s, int f)
{
  if (s == f)
    return;

  auto head = h;
  int current = 1;
  auto next = head;
  auto prev = head;
  std::shared_ptr<ListNode<int>> reverseLeft = nullptr;
  std::shared_ptr<ListNode<int>> reverseRight = nullptr;

  while (head && current <= f + 1)
  {
    std::cout << "current = " << current << std::endl;
    if (s < current && current <= f)
    {
      if (current == f && reverseLeft)
        reverseLeft->next = head;
      if (current == f && !reverseLeft)
        h = head;

      // reverse
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    else if (current + 1 == s)
    {
      reverseLeft = head;
      head = head->next;
      reverseLeft->next = nullptr;
    }
    else if (current == s)
    {
      reverseRight = head;
      prev = head;
      head = head->next;
      reverseRight->next = nullptr;
    }
    else if (current == f + 1)
    {
      reverseRight->next = head;
      head = head->next;
    }

    current++;
  }
}

int main(int argc, char **argv)
{
  auto head = std::make_shared<ListNode<int>>(1);
  head->next = std::make_shared<ListNode<int>>(2);
  head->next->next = std::make_shared<ListNode<int>>(3);
  head->next->next->next = std::make_shared<ListNode<int>>(4);
  head->next->next->next->next = std::make_shared<ListNode<int>>(5);

  PrintList(head);

  ReverseSublist(head, 2, 2);

  PrintList(head);

  return 0;
}
