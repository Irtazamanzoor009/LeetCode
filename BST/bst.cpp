#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
public:
    Node *top;
    BST()
    {
        top = nullptr;
    }

    void InsertInBST(int value)
    {
        Insert(top, value);
    }

private:
    void Insert(Node *&root, int value)
    {
        if (root == nullptr)
        {
            Node *new_node = new Node(value);
            root = new_node;
        }
        else if (value < root->data)
        {
            Insert(root->left, value);
        }
        else if (value > root->data)
        {
            Insert(root->right, value);
        }
    }

public:
    void PrintInOrder(Node *top)
    {
        if (top != nullptr)
        {
            PrintInOrder(top->left);
            cout << top->data << " ";
            PrintInOrder(top->right);
        }
    }

    void PrintPreOrder(Node *top)
    {
        if (top != nullptr)
        {
            cout << top->data << " ";
            PrintPreOrder(top->left);
            PrintPreOrder(top->right);
        }
    }

    void PrintPostOrder(Node *top)
    {
        if (top != nullptr)
        {
            PrintPostOrder(top->left);
            PrintPostOrder(top->right);
            cout << top->data << " ";
        }
    }

    int GetEnd(Node* top)
    {
        if(top == nullptr)
        {
            return -1;
        }
        else if(top->left == nullptr && top->right == nullptr)
        {
            return top->data;
        }
        return GetEnd(top->left);
    }

    Node* GetTop()
    {
        return top;
    }
};

int main()
{
    BST b;
    b.InsertInBST(22);
    b.InsertInBST(12);
    b.InsertInBST(30);
    b.InsertInBST(8);
    b.InsertInBST(20);
    b.InsertInBST(25);
    b.InsertInBST(40);
    Node* top = b.GetTop();
    cout << b.GetEnd(top);
}