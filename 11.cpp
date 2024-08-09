#include <iostream>
#include <deque>
using namespace std;

class MyStack
{
public:
    deque<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push_back(x);
    }

    int pop()
    {
        int last = q.back();
        q.pop_back();
        return last;
    }

    int top()
    {
        return q.back();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    deque<int> a;
    
}