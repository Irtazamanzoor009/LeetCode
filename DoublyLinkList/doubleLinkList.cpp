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
            if (temp == tail)
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
        Node *temp = head;
        Node *new_node = new Node(value);
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
            if (temp == head)
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

    Node *GetHead()
    {
        return head;
    }

    Node *GetTail()
    {
        return tail;
    }

    int GetFront()
    {
        return head->data;
    }

    int GetBack()
    {
        return tail->data;
    }

    void RemoveFront()
    {
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
            size--;
        }
        else
        {
            head->next->previous = nullptr;
            head = head->next;
            size--;
        }
    }

    void RemoveEnd()
    {
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
            size--;
        }
        else
        {
            tail->previous->next = nullptr;
            tail = tail->previous;
            size--;
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

    void RemoveAtSpecificPosition(int key)
    {
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
            if (temp == head)
            {
                RemoveFront();
            }
            else if (temp == tail)
            {
                RemoveEnd();
            }
            else if (temp != head && temp != tail)
            {
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                delete temp;
            }
        }
    }

    void DeleteDataWithIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        else if (index == 0)
        {
            RemoveFront();
        }
        else if (index == size - 1)
        {
            RemoveEnd();
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            delete temp;
        }
        size--;
    }

    void DisplayReverse()
    {
        Node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data << "-------";
            temp = temp->previous;
        }
        cout << "NULL" << endl;
    }
};

void Splice(DoubleLinkList &l1, DoubleLinkList &l2, int key)
{
    Node *temp1 = l1.GetHead();
    Node *temp1_tail = l1.GetTail();
    Node *temp2 = l2.GetHead();
    Node *temp2_tail = l2.GetTail();
    while (temp1 != nullptr)
    {
        if (temp1->data == key)
        {
            break;
        }
        temp1 = temp1->next;
    }
    if (temp1 == nullptr)
    {
        return;
    }
    else
    {
        if (temp1 == temp1_tail)
        {
            Node *new_node = l2.GetHead();
            while (new_node != nullptr)
            {
                l1.InsertAtTail(new_node->data);
                new_node = new_node->next;
            }
        }
        else
        {
            temp2->previous = temp1;
            temp2_tail->next = temp1->next;
            temp1->next->previous = temp2_tail;
            temp1->next = temp2;
        }
    }
}

int main()
{
    DoubleLinkList l1;
    DoubleLinkList l2;

    l1.InsertAtTail(1);
    l1.InsertAtTail(2);
    l1.InsertAtTail(3);
    l1.InsertAtTail(4);
    l1.DeleteDataWithIndex(2);
    l1.Display();
}