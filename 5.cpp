#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    // int sum=0;
    // int temp=0;
    // for(int i=0; i<nums.size(); i++)
    // {
    //     for(int j=i; j<nums.size(); j++)
    //     {
    //         for(int k=i; k<=j; k++)
    //         {
    //             temp += nums[k];
    //         }
    //         if(temp > sum)
    //         {
    //             sum = temp;
    //         }
    //         temp=0;
    //     }
    // }
    // return sum;

    int maxSum = nums[0];
    int currentsum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        currentsum = max(nums[i], currentsum + nums[i]);
        maxSum = max(maxSum, currentsum);
    }
    return maxSum;
}

int main()
{
    vector<int> arr = {1,-1,2};

    // for(int i=0; i<arr.size(); i++)
    // {
    //     for(int j=i; j<arr.size(); j++)
    //     {
    //         for(int k=i; k<=j; k++)
    //         {
    //             cout << arr[k] << " ";
    //         }
    //         cout << endl;

    //     }
    // }
    int sum = maxSubArray(arr);
    cout << sum;
}