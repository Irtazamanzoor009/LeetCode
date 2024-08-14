#include <iostream>
#include "linklist.h"
using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == nullptr)
    {
        return NULL;
    }
    ListNode *temp = head;
    ListNode *temp1 = head;
    int length = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
        length++;
    }
    int nth = length - n;
    if(nth == 0)
    {
        return temp1->next;
    }
    int count = 1;
    while (count != nth)
    {
        temp1 = temp1->next;
        count++;
    }
    temp1->next = temp1->next->next;
    return head;
}

int main()
{
    LinkList l;
    l.Insert(1);
    l.Insert(2);
    ListNode *head = l.GetHead();
    ListNode* h = removeNthFromEnd(head,2);
    l.Display(h);
}
