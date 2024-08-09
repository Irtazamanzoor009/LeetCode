#include <iostream>
#include <deque>
using namespace std;

class FrontMiddleBackQueue
{
public:
    deque<int> q;
    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        q.push_front(val);
    }

    void pushMiddle(int val)
    {
        int mid = q.size() / 2;
        q.insert(q.begin() + mid, val);
    }

    void pushBack(int val)
    {
        q.push_back(val);
    }

    int popFront()
    {
        if (q.empty())
        {
            return -1;
        }
        else
        {
            int front = q.front();
            q.pop_front();
            return front;
        }
    }

    int popMiddle()
    {
        if (q.empty())
        {
            return -1;
        }
        else
        {
            int size = q.size();
            int mid = q.size() / 2;
            int num;
            if (size % 2 == 0)
            {
                num = q[mid - 1];
                q.erase(q.begin() + (mid - 1));
            }
            else
            {
                num = q[mid];
                q.erase(q.begin() + mid);
            }
            return num;
        }
    }

    int popBack()
    {
        if (q.empty())
        {
            return -1;
        }
        else
        {
            int back = q.back();
            q.pop_back();
            return back;
        }
    }

    void Print()
    {
        for (int i = 0; i < q.size(); i++)
        {
            cout << q[i];
        }
    }
};

int main()
{
    FrontMiddleBackQueue a;
    a.pushFront(1);
    a.pushBack(2);
    a.pushMiddle(3);
    a.pushMiddle(4);
    a.popFront();
    a.popMiddle();
    a.popMiddle();
    a.popBack();
    int v = a.popFront();
    cout << v;
    
}