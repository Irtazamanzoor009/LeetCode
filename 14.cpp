#include <iostream>
#include<vector>
#include<numeric>
using namespace std;

int maxSubarraySumCircular(vector<int> &nums)
{
    // [1,-2,3,-2]
    int maxSum = nums[0];
    int currSum = nums[0];
    for(int i=1; i<nums.size(); i++)
    {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }

    currSum = nums[0];
    int minSum = nums[0];
    for(int i=1; i<nums.size(); i++)
    {
        currSum = min(nums[i], currSum + nums[i]);
        minSum = min(minSum, currSum);
    }

    int TotalSum = accumulate(nums.begin(), nums.end(),0);

    int Wrap = TotalSum - minSum;

    if(Wrap == 0)
    {
        return maxSum;
    }

    return max(Wrap, maxSum);
}

int main()
{
    vector<int> a = {-3,-2,-3};
    int sum = maxSubarraySumCircular(a);
    cout << sum;
}