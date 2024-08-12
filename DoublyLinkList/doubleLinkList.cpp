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
};