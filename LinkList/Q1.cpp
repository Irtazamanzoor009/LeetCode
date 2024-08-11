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

    int operator[](int index)
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            if (count == index)
            {
                return temp->data;
            }
            temp = temp->next;
            count++;
        }
        throw out_of_range("Index out of bounds");
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
        Node *temp1 = head;
        Node *temp2 = head;
        Node *temp3 = head;
        int count = 0;
        int count2 = 0;
        while (temp1->next != nullptr)
        {
            temp1 = temp1->next;
            if (count == 2)
            {
                temp2 = temp2->next;
                count = 0;
                if (count2 == 1)
                {
                    temp3 = temp3->next;
                    count2 = 0;
                }
                count2++;
            }
            count++;
        }

        temp3->next = temp2->next;
        delete temp2;
    }

    Node *getHead()
    {
        return head;
    }

    void PrintRecursively(Node *temp)
    {
        if (temp == nullptr)
        {
            cout << "NULL" << endl;
            return;
        }
        cout << temp->data << "------";
        PrintRecursively(temp->next);
    }

    void PrintReverseRecursively(Node *temp)
    {
        if (temp == nullptr)
        {
            return;
        }
        PrintReverseRecursively(temp->next);
        cout << temp->data << "------";
    }

    int FindMiddle()
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
        return temp2->data;
    }

    bool CheckCircular()
    {
        if (head == nullptr && tail == nullptr)
        {
            return false;
        }
        if (tail->next = head)
        {
            return true;
        }
        return false;
    }

    Node *ReverseLinkList()
    {
        Node *current = head;
        Node *previous = nullptr;
        Node *next = nullptr;
        while(current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
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

class Stack
{
private:
    LinkList l;

public:
    Stack()
    {
    }

    void Push(int v)
    {
        l.InsertAtTail(v);
    }

    int operator[](int index)
    {
        return l[index];
    }

    int Pop()
    {
        int last = l.GetTail();
        l.RemoveTail();
        return last;
    }

    bool isEmpty()
    {
        return l.isEmpty();
    }

    void Display()
    {
        l.Display();
    }
};

class Queue
{
private:
    LinkList l;

public:
    Queue()
    {
    }
    void Enque(int value)
    {
        l.InsertAtTail(value);
    }

    int operator[](int index)
    {
        return l[index];
    }

    int Deque()
    {
        int front = l.GetFront();
        l.RemoveFront();
        return front;
    }

    void Display()
    {
        l.Display();
    }

    bool isEmpty()
    {
        return l.isEmpty();
    }
};

int main()
{
    LinkList l;
    l.InsertAtTail(1);
    l.InsertAtTail(2);
    l.InsertAtTail(3);
    l.InsertAtTail(4);
    l.InsertAtTail(5);
    l.InsertAtTail(6);
    Node head = *l.ReverseLinkList();
    l.PrintRecursively(&head);
}