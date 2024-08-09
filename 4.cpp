#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    // [1,1,2,3,1,4,5]
    for (int i = 0; i < nums.size(); i++)
    {
        int temp = nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (temp == nums[j])
            {
                nums.erase(nums.begin() + j);
                j--;
            }
        }
    }
    return nums.size();
}

int main()
{
    vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
    int a = removeDuplicates(arr);
    // cout << a;
    // for (int i = 0; i < a.size(); i++)
    // {
    //     for(int j=0; j<=a.size(); j++)
    //     {
    //         cout << a[i][j] << ',';
    //     }
    // }
    // cout << a[1].size();
}