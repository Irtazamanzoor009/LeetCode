#include <iostream>
#include <string>
#include <stack>
using namespace std;

string DecodeString(string s)
{
    int tempNum = 0;
    stack<string> str;
    stack<int> num;
    string decodeString = "";
    for (int i = 0; i < s.length(); i++)
    {
        if(isdigit(s[i]))
        {
            tempNum = 10 * tempNum + s[i] - '0';
        }
        else if(s[i] == '[')
        {
            str.push(decodeString);
            decodeString = "";
            num.push(tempNum);
            tempNum = 0;
        }
        else if(s[i] == ']')
        {
            string temp = decodeString;
            decodeString = str.top();
            str.pop();
            int time = num.top();
            num.pop();
            while(time != 0)
            {
                decodeString += temp;
                time--;
            }
        }
        else
        {
            decodeString += s[i];
        }
    }
    return decodeString;
}

int main()
{
    string a = "[a]";
    string ans = DecodeString(a);
    cout << ans;
}