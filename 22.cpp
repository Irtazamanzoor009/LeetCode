#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> values;
    values['I'] = 1;
    values['V'] = 5;
    values['X'] = 10;
    values['L'] = 50;
    values['C'] = 100;
    values['D'] = 500;
    values['M'] = 1000;

    int ans = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (i > 0 && s[i] == 'V' && s[i - 1] == 'I')
        {
            int v = values[s[i]] - values[s[i - 1]];
            ans += v;
            i--;
        }
        else if (i > 0 && s[i] == 'L' && s[i - 1] == 'X')
        {
            int v = values[s[i]] - values[s[i - 1]];
            ans += v;
            i--;
        }
        else if (i > 0 && s[i] == 'C' && s[i - 1] == 'X')
        {
            int v = values[s[i]] - values[s[i - 1]];
            ans += v;
            i--;
        }
        else if (i > 0 && s[i] == 'M' && s[i - 1] == 'D')
        {
            int v = values[s[i]] - values[s[i - 1]];
            ans += v;
            i--;
        }
        else if (i > 0 && s[i] == 'D' && s[i - 1] == 'C')
        {
            int v = values[s[i]] - values[s[i - 1]];
            ans += v;
            i--;
        }
        else if (i > 0 && s[i] == 'X' && s[i - 1] == 'I')
        {
            int v = values[s[i]] - values[s[i - 1]];
            ans += v;
            i--;
        }
        else if (i > 0 && s[i] == 'M' && s[i - 1] == 'C')
        {
            int v = values[s[i]] - values[s[i - 1]];
            ans += v;
            i--;
        }
        else if (values.find(s[i]) != values.end())
        {
            ans += values[s[i]];
        }
    }
    return ans;
}

int romanToInt2(string s)
{
    unordered_map<char, int> values = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 && values[s[i]] < values[s[i + 1]])
        {
            ans -= values[s[i]];
        }
        else
        {
            ans += values[s[i]];
        }
    }
    return ans;
}

int main()
{
    string s = "MCMXCIV";
    int ans = romanToInt2(s);
    cout << ans;
}