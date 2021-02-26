/*
 *  8.8
 *  Write a program that computes the even-odd merge
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

void EvenOddMerge(std::shared_ptr<ListNode<int>> head)
{
  auto oddStart = head->next;
  auto evenEnd = head;
  auto nextNode = head;

  bool isEven = true;

  while (head)
  {
    if (isEven)
      evenEnd = head;

    nextNode = head->next;

    // TODO: check if not nullptr
    if (head->next)
      head->next = head->next->next;

    head = nextNode;
    isEven = !isEven;
  }

  evenEnd->next = oddStart;
}

int main(int argc, char **argv)
{
  auto head = std::make_shared<ListNode<int>>(0);
  head->next = std::make_shared<ListNode<int>>(1);
  head->next->next = std::make_shared<ListNode<int>>(2);
  head->next->next->next = std::make_shared<ListNode<int>>(3);
  head->next->next->next->next = std::make_shared<ListNode<int>>(4);
  head->next->next->next->next->next = std::make_shared<ListNode<int>>(5);


  PrintList(head);

  EvenOddMerge(head);

  PrintList(head);

  return 0;
}
