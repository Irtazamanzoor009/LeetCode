#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int value)
    {
        data = value;
        next = nullptr;
    }

    ListNode()
    {
        data = 0;
        next = nullptr;
    }
};

class LinkList
{
private:
    ListNode *head;
    ListNode *tail;

public:
    LinkList()
    {
        head = nullptr;
        tail = nullptr;
    }

    ListNode* GetHead()
    {
        return head;
    }

    void Insert(int value)
    {
        ListNode *temp = new ListNode(value);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void Display(ListNode* head1)
    {
        ListNode* temp = head1;
        while(temp != nullptr)
        {
            cout << temp->data << "-------";
            temp = temp->next;
        }
        cout << "NULL";
    }
    void Display()
    {
        ListNode* temp = head;
        while(temp != nullptr)
        {
            cout << temp->data << "-------";
            temp = temp->next;
        }
        cout << "NULL";

    }
};
