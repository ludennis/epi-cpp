/*
 *  8.3
 *  Write a program that takes the head of a singly linked list and returns null if there does
 *    not exist a cycle, and the node at the start of the cycle, if a cycle is present. (You do
 *    not know the length of the list in advance)
 */

#include <iostream>

#include <ListNode.h>

std::shared_ptr<ListNode<int>> DetectCycle(std::shared_ptr<ListNode<int>> head)
{
  bool hasCycle = false;
  auto tortoise = head;
  auto hare = head;

  while (tortoise && hare)
  {
    hare = hare->next;
    if (hare)
      hare = hare->next;

    tortoise = tortoise->next;

    if (tortoise == hare)
    {
      hasCycle = true;
      break;
    }
  }

  if (hasCycle)
  {
    // get cycle length
    int cycleLength = 1;
    hare = tortoise->next;
    while (tortoise != hare)
    {
      hare = hare->next;
      cycleLength++;
    }

    tortoise = head;
    hare = head;
    for (auto i{0}; i < cycleLength; ++i)
    {
      hare = hare->next;
    }

    while (hare != tortoise)
    {
      hare = hare->next;
      tortoise = tortoise->next;
    }

    return hare;
  }

  return nullptr;
}

int main(int argc, char **argv)
{
  auto head = std::make_shared<ListNode<int>>(1);
  head->next = std::make_shared<ListNode<int>>(2);
  head->next->next = std::make_shared<ListNode<int>>(3);
  head->next->next->next = std::make_shared<ListNode<int>>(4);
  head->next->next->next->next = std::make_shared<ListNode<int>>(5);
  head->next->next->next->next = head->next;

  auto node = DetectCycle(head);

  if (node)
  {
    std::cout << "Cycle detected that starts at " << node->data << std::endl;
  }
  else
  {
    std::cout << "No cycle detected" << std::endl;
  }

}
