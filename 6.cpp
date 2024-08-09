#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    // [1,2,0] => [0,1,2]
    sort(nums.begin(),nums.end());
    int number = 1;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] == number)
        {
            number++;
        }
    }
    return number;
    
    
}

int main()
{
    vector<int> arr = {0,1, 3};
    int a = firstMissingPositive(arr);
    cout << a << endl;
    
}