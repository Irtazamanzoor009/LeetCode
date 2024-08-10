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
    void Insert(int value)
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
    void Display()
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            cout << temp->data << "-------";
            temp = temp->next;
        }
        cout << "NULL";

    }
};

int main()
{
    LinkList l;
    l.Insert(2);
    l.Insert(3);
    l.Insert(4);
    l.Insert(5);
    l.Display();
}