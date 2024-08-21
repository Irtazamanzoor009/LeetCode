#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    string s = to_string(x);
    for (int i = 0, j = s.length() - 1; i < s.length(); i++, j--)
    {
        if(s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int x = -121;
    cout << isPalindrome(x);
}