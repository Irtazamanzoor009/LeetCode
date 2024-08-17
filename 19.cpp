#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int value)
    {
        val = value;
        next = nullptr;
    }
    ListNode()
    {
        val = 0;
        next = nullptr;
    }
};

class MyLinkedList
{
public:
    ListNode *head;
    ListNode *tail;
    int size;
    MyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }

        int count = 0;
        ListNode *temp = head;
        while (count != index)
        {
            temp = temp->next;
            count++;
        }
        return temp->val;
    }

    void addAtHead(int val)
    {
        ListNode *new_node = new ListNode(val);
        if (head == nullptr && tail == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
        size++;
    }

    void addAtTail(int val)
    {
        ListNode *new_node = new ListNode(val);
        if (head == nullptr && tail == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
        {
            return;
        }

        if (index == 0)
        {
            addAtHead(val);
        }
        else if (index == size)
        {
            addAtTail(val);
        }
        else
        {
            int count = 1;
            ListNode *temp = head;
            ListNode *new_node = new ListNode(val);
            while (count != index)
            {
                temp = temp->next;
                count++;
            }
            new_node->next = temp->next;
            temp->next = new_node;
            size++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }

        if (index == 0)
        {
            head = head->next;
            if (size == 1)
            {
                tail = nullptr;
            }
        }

        else if (index == size - 1)
        {
            ListNode *temp = head;
            ListNode *prev = nullptr;
            while (temp->next != nullptr)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = nullptr;
            tail = prev;
            delete temp;
        }
        else
        {
            int count = 1;
            ListNode *temp = head;
            while (count != index)
            {
                temp = temp->next;
                count++;
            }
            temp->next = temp->next->next;
        }
        size--;
    }

    void Display()
    {
        ListNode *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << "------";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int GetNode()
    {
        return tail->val;
    }
};

int main()
{
    MyLinkedList l;
    l.addAtHead(1);
    l.addAtTail(3);
    l.addAtIndex(1, 2);
    cout << l.get(1) << endl;
}