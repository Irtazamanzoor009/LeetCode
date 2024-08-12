#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;
    Node(int value)
    {
        data = value;
        next = nullptr;
        previous = nullptr;
    }
};

class DoubleLinkList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoubleLinkList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void InsertAtTail(int value)
    {
        Node *temp = new Node(value);
        if (head == nullptr && tail == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->previous = tail;
            tail = temp;
        }
        size++;
    }

    void InsertAtHead(int value)
    {
        Node *temp = new Node(value);
        if (head == nullptr && tail == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head->previous = temp;
            head = temp;
        }
        size++;
    }

    bool isEmpty()
    {
        if(head == nullptr && tail == nullptr)
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
        Node *new_node = new Node(value);
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                break;
            }
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            return;
        }
        else
        {
            if(temp == tail)
            {
                InsertAtTail(value);
            }
            else
            {
                new_node->next = temp->next;
                temp->next->previous = new_node;
                temp->next = new_node;
                new_node->previous = temp;
            }
            size++;
        }
    }

    void InsertBefore(int value, int key)
    {
        Node* temp = head;
        Node* new_node = new Node(value);
        while(temp != nullptr)
        {
            if(temp->data == key)
            {
                break;
            }
            temp = temp->next;
        }
        if(temp == nullptr)
        {
            return;
        }
        else
        {
            if(temp == head)
            {
                InsertAtHead(value);
            }
            else
            {
                new_node->next = temp;
                temp->previous->next = new_node;
                new_node->previous = temp->previous;
                temp->previous = new_node;
            }
            size++;
        }
    }

    int GetFront()
    {
        return head->data;
    }

    int GetTail()
    {
        return tail->data;
    }

    void RemoveFront()
    {
        if(head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head->next->previous = nullptr;
            head = head->next;
        }
        size--;
    }

    void RemoveEnd()
    {
        if(head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            
        }
    }

    void Display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "-------";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void DisplayReverse()
    {
        Node* temp = tail;
        while(temp != nullptr)
        {
            cout << temp->data << "-------";
            temp = temp->previous;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoubleLinkList l;
    l.InsertAtTail(1);
    l.InsertAtTail(2);
    l.InsertAtTail(3);
    l.InsertAtTail(4);
    l.InsertAtTail(5);
    l.RemoveFront();
    l.Display();
    cout << l.GetFront();
}