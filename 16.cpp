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

    Node()
    {
        data = 0;
        next = nullptr;
    }
};

Node* mergeLists(Node* list1, Node* list2)
{
    if(list1 == nullptr && list2 == nullptr)
    {
        return NULL;
    }
    else if(list1 == nullptr && list2 != nullptr)
    {
        return list2;
    }
    else if(list2 == nullptr && list1 != nullptr)
    {
        return list1;
    }

    Node* merged = new Node();
    Node* temp = merged;
    while(list1 != nullptr && list2 != nullptr)
    {
        if(list1->data <= list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if(list1 != nullptr)
    {
        temp->next = list1;
    }
    if(list2 != nullptr)
    {
        temp->next = list2;
    }
    return merged->next;
    
}