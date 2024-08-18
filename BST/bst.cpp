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

    int GetEnd(Node *top)
    {
        if (top == nullptr)
        {
            return -1;
        }
        else if (top->left == nullptr && top->right == nullptr)
        {
            return top->data;
        }
        else
        {
            if (top->left != nullptr)
            {
                return GetEnd(top->left);
            }
            else if (top->right != nullptr)
            {
                return GetEnd(top->right);
            }
        }
    }

    Node *GetTop()
    {
        return top;
    }
};

bool isIndentical(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if(root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    return isIndentical(root1->left, root2->left) && isIndentical(root1->right, root2->right);
}

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
    Node *top = b.GetTop();
    
    BST b2;
    b2.InsertInBST(22);
    b2.InsertInBST(12);
    b2.InsertInBST(30);
    b2.InsertInBST(8);
    b2.InsertInBST(20);
    b2.InsertInBST(25);
    b2.InsertInBST(40);
    Node *top2 = b2.GetTop();

    cout << isIndentical(top,top2);

}