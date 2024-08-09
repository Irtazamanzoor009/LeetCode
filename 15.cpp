#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> s;
    vector<int> ans;

    for (int i = 0; i < asteroids.size(); i++)
    {
        if (s.empty() || asteroids[i] > 0)
        {
            s.push(asteroids[i]);
        }
        else if (asteroids[i] < 0)
        {
            bool destroyed = false;

            while (!s.empty() && s.top() > 0)
            {
                if (s.top() < -asteroids[i])
                {
                    s.pop();
                }
                else if (s.top() == -asteroids[i])
                {
                    s.pop();
                    destroyed = true;
                    break;
                }
                else
                {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed)
            {
                s.push(asteroids[i]);
            }
        }
    }

    while (!s.empty())
    {
        ans.insert(ans.begin(), s.top());
        s.pop();
    }

    return ans;
}

int main()
{
    vector<int> a = {-2, 1, 1, -2};
    vector<int> ans = asteroidCollision(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ",";
    }
}
