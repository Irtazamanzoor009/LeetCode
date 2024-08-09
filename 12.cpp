#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    queue<int> stud;
    queue<int> sand;
    for (int i = 0; i < students.size(); i++)
    {
        stud.push(students[i]);
        sand.push(sandwiches[i]);
    }
    int count = 0;
    while(!stud.empty())
    {
        if (stud.front() == sand.front())
        {
            stud.pop();
            sand.pop();
            count = 0;
        }
        else
        {
            int front = stud.front();
            stud.pop();
            stud.push(front);
            count++;
        }
        if(count == stud.size())
        {
            break;
        }
    }
    return stud.size();
}

int main()
{
    vector<int> students = {1,1,1,0,0,1};
    vector<int> sandwiches = {1,0,0,0,1,1};

    int st = countStudents(students, sandwiches);
    cout << st;
}
