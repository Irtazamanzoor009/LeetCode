#include <iostream>
#include <vector>
#include<numeric>
using namespace std;

int maxSubArray(vector<int> &nums)
{

    int maxSum = nums[0];
    int currentsum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        currentsum = min(nums[i], currentsum + nums[i]);
        maxSum = min(maxSum, currentsum);
    }
    return maxSum;
}

int main()
{
    vector<int> arr = {-2,-1,-4};
    int sum = accumulate(arr.begin(), arr.end(),0);
    cout << sum;
    // int sum = maxSubArray(arr);
    // cout << sum;
    // int sum = maxSubArray(arr);
    // cout << sum;
}