#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkList
{
private:
    Node *head;
    Node *tail;

public:
    LinkList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void InsertAtTail(int value)
    {
        Node *temp = new Node(value);
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

    void InsertAtHead(int value)
    {
        Node *temp = new Node(value);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void InsertAtMid(int value)
    {
        Node *temp1 = head;
        Node *temp2 = head;
        int count = 0;
        while (temp1 != nullptr)
        {
            temp1 = temp1->next;
            if (count == 2)
            {
                temp2 = temp2->next;
                count = 0;
            }
            count++;
        }
        Node *temp = new Node(value);
        temp->next = temp2->next;
        temp2->next = temp;
    }

    bool isEmpty()
    {
        if (head == nullptr && tail == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void InsertAfter(int value, int key)
    {
        Node *temp1 = head;
        while (temp1->data != key)
        {
            temp1 = temp1->next;
        }
        Node *temp = new Node(value);
        if (temp1->next == nullptr)
        {
            InsertAtTail(value);
        }
        else
        {
            temp->next = temp1->next;
            temp1->next = temp;
        }
    }

    void InsertBefore(int value, int key)
    {
        Node *temp1 = head;
        Node *temp2 = head;
        int count = 0;
        bool atStart = true;
        while (temp1->data != key)
        {
            temp1 = temp1->next;
            if (count == 1)
            {
                temp2 = temp2->next;
                count = 0;
            }
            count++;
            atStart = false;
        }
        Node *temp = new Node(value);
        if (atStart)
        {
            InsertAtHead(value);
        }
        else
        {
            temp->next = temp2->next;
            temp2->next = temp;
        }
    }

    int GetFront()
    {
        if (!isEmpty())
        {
            return head->data;
        }
    }

    int GetTail()
    {
        if (!isEmpty())
        {
            return tail->data;
        }
    }

    Node *Search(int key)
    {
        Node *temp1 = head;
        while (temp1 != nullptr)
        {
            if (temp1->data == key)
            {
                return temp1;
            }
            temp1 = temp1->next;
        }
        return nullptr;
    }

    int RemoveFront()
    {
        int ReturnHead = head->data;
        if (!isEmpty())
        {
            head = head->next;
        }
        return ReturnHead;
    }

    int RemoveTail()
    {
        int gettail = tail->data;
        if (!isEmpty())
        {
            Node *temp1 = head;
            Node *temp2 = head;
            int count = 0;
            if (head == tail)
            {
                delete tail;
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                while (temp1->next != nullptr)
                {
                    temp1 = temp1->next;
                    if (count == 1)
                    {
                        temp2 = temp2->next;
                        count = 0;
                    }
                    count++;
                }
                delete tail;
                tail = temp2;
                temp2->next = nullptr;
            }
        }
        return gettail;
    }

    void RemoveMiddle()
    {
        Node* temp1 = head;
        Node* temp2 = head;
        int count = 0;
        while(temp1->next != nullptr)
        {
            
        }
    }

    void Display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "-----";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{
    LinkList l;
    l.InsertAtTail(1);
    l.InsertAtTail(2);
    l.InsertAtTail(3);
    l.InsertAtMid(4);
    l.InsertBefore(10, 1);
    l.InsertAfter(11, 2);
    l.Display();
    cout << endl;
    cout << l.RemoveTail();
    cout << endl;
    l.Display();
    cout << l.GetTail();
}