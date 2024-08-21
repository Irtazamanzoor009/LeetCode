#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

//constant time
vector<int> twoSum_linearTime(vector<int> &nums, int target)
{
    unordered_map<int,int> numMap;
    vector<int> ans;

    for(int i=0; i<nums.size(); i++)
    {
        int complement = target - nums[i];
        if(numMap.find(complement) != numMap.end())
        {
            ans.push_back(numMap[complement]);
            ans.push_back(i);
            return ans;
        }
        numMap[nums[i]] = i;
    }
    return ans;
}

int main()
{
    vector<int> a = {3,3};
    vector<int> ans = twoSum_linearTime(a, 6);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}