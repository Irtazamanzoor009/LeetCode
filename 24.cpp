#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int missingInteger(vector<int> &nums)
{
    int num = nums[0];
    int sum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int a = nums[i];
        if (++num == nums[i])
        {
            num = nums[i];
            sum += num;
        }
        else
        {
            break;
        }
    }

    // int i = 0;
    // while (i < nums.size())
    // {
    //     if (sum == nums[i])
    //     {
    //         sum++;
    //         i = 0;
    //     }
    //     i++;
    // }

    unordered_set<int> list(nums.begin(), nums.end());
    int x = sum;
    while(list.find(x) != list.end())
    {
        x++;
    }
    return x;
}

int main()
{
    vector<int> s = {19, 20, 21, 22};
    cout << missingInteger(s);
}
