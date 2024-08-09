#include<iostream>
#include<vector>
using namespace std;

// class MinStack {
// public:
//     vector<int> arr;
//     MinStack() {
//         arr.reserve(4);
//     }
    
//     void push(int val) {
//         arr.push_back(val);
//     }
    
//     void pop() {
//         arr.pop_back();
//     }
    
//     int top() {
//         return arr[arr.size()-1];
//     }
    
//     int getMin() 
//     {
//         int min = top();
//         for(int i=0; i<arr.size(); i++)
//         {
//             if(arr[i] < min)
//             {
//                 min = arr[i];
//             }
//         }   
//         return min;
//     }
// };

class MinStack {
public:
    vector<int> arr;
    vector<int> minStack;
    MinStack() {
        arr.reserve(4);
    }
    
    void push(int val) {
        arr.push_back(val);
        if(minStack.empty() || val <= minStack.back())
        {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        if(arr.back() == minStack.back())
        {
            minStack.pop_back();
        }
        arr.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() 
    {
        return minStack.back();
    }
};

int main()
{
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << endl;
    s.pop();
    s.top();
    int t = s.getMin();

}