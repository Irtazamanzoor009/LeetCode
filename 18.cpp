#include <iostream>
#include "linklist.h"
using namespace std;

ListNode *swapPairs(ListNode *head)
{
    ListNode *Dummy = new ListNode();
    Dummy->next = head;

    ListNode *point = Dummy;

    while (point->next != nullptr && point->next->next != nullptr)
    {
        ListNode *swap1 = point->next;
        ListNode *swap2 = point->next->next;

        swap1->next = swap2->next;
        swap2->next = swap1;

        point->next = swap2;
        point = swap1;
    }
    return Dummy->next;
}

ListNode *ReverseList(ListNode *head)
{
    ListNode *current = head;
    ListNode *next = nullptr;
    ListNode *previous = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == nullptr || head->next == nullptr || left == right)
    {
        return head;
    }
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *temp = dummy;

    for (int i = 1; i < left; i++)
    {
        temp = temp->next;
    }

    ListNode *current = temp->next;
    ListNode *previous = nullptr;
    ListNode *next = nullptr;

    for (int i = 0; i <= right - left; i++)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    temp->next->next = current;
    temp->next = previous;

    return dummy->next;
}



int main()
{
    LinkList l;
    l.Insert(1);
    l.Insert(2);
    l.Insert(3);

    ListNode *ishead = l.GetHead();
    ListNode *head = reverseBetween(ishead, 1, 2);
    l.Display(head);
}