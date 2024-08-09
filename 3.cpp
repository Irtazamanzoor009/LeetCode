#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> flatArray;

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            flatArray.push_back(matrix[i][j]);
        }
    }

    int size = flatArray.size();
    int start = 0;
    int end = flatArray.size()-1;

    while(start <= end)
    {
        int mid = start + (end - start )/2;
        if(target == flatArray[mid])
        {
            return true;
        }
        else if(target > flatArray[mid])
        {
            start = mid + 1;
        }
        else if (target < flatArray[mid])
        {
            end = mid - 1;
        }
    }
     return false;
}

int main()
{
    // vector<vector<int>> a = {{1,3}};
    vector<vector<int>> a = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    bool value = searchMatrix(a,3);
    cout << value;
    // for (int i = 0; i < a.size(); i++)
    // {
    //     for(int j=0; j<=a.size(); j++)
    //     {
    //         cout << a[i][j] << ',';
    //     }
    // }
    // cout << a[1].size();
}