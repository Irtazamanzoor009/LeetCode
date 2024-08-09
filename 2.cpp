#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    // nums = [3,2,2,3], val = 3
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] == val)
        {
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    return nums.size();
}

int main()
{
    vector<int> a = {0,1,2,2,3,0,4,2};
    int size = removeElement(a,2);
    cout << "Size: " << size << endl;
    for(int i=0; i<a.size(); i++)
    {
        cout << a[i];
    }
}