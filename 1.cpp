#include <iostream>
#include <vector>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int> nums)
{
    // [8,1,2,2,3]
    vector<int> SmallerValues(nums.size(), 0);
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] > nums[j])
            {
                count++;
            }
        }
        SmallerValues[i] = count;
        count=0;
    }
    return SmallerValues;
}

int main()
{
    vector<int> nums = {7,7,7,7};
    vector<int> ans = smallerNumbersThanCurrent(nums);
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    // cout << "hello world";
    return 0;
}