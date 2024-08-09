#include <iostream>
#include <stack>
using namespace std;

string ToPostFix(string eq);
string ReverseEquation(string s);
string ToPrefix(string eq);
int EvaluatePostFix(string postfix);
int EvaluatePrefix(string prefix);

int main()
{
    string eq = "(2-4/3)*(2/6-5)";
    string prefix = ToPrefix(eq);
    int ans = EvaluatePrefix(prefix);
    cout << "Prefix ans: " << ans << endl;

    string postfix = ToPostFix(eq);
    cout << postfix << endl;
    int postfixans = EvaluatePostFix(postfix);
    cout << "PostFix ans: " << postfixans;
}

int EvaluatePrefix(string prefix)
{
    stack<int> s;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isdigit(prefix[i]))
        {
            s.push(prefix[i] - '0');
        }
        else
        {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            int symbol = prefix[i];
            int ans;
            if (prefix[i] == '+')
            {
                ans = op1 + op2;
            }
            else if (prefix[i] == '-')
            {
                ans = op1 - op2;
            }
            else if (prefix[i] == '*')
            {
                ans = op1 * op2;
            }
            else if (prefix[i] == '/')
            {
                ans = op1 / op2;
            }
            s.push(ans);
        }
    }
    return s.top();
}

int EvaluatePostFix(string postfix)
{
    stack<int> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isdigit(postfix[i]))
        {
            s.push(postfix[i] - '0');
        }
        else
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            int symbol = postfix[i];
            int ans;
            if (postfix[i] == '+')
            {
                ans = op1 + op2;
            }
            else if (postfix[i] == '-')
            {
                ans = op1 - op2;
            }
            else if (postfix[i] == '*')
            {
                ans = op1 * op2;
            }
            else if (postfix[i] == '/')
            {
                ans = op1 / op2;
            }
            s.push(ans);
        }
    }
    return s.top();
}

string ReverseEquation(string s)
{
    string result = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
        {
            result += ')';
        }
        else if (s[i] == ')')
        {
            result += '(';
        }
        else
        {
            result += s[i];
        }
    }
    return result;
}

string ToPrefix(string eq)
{
    string Reverse = ReverseEquation(eq);
    string postfix = ToPostFix(Reverse);
    string prefix = ReverseEquation(postfix);
    return prefix;
}

string ToPostFix(string eq)
{
    stack<char> s;
    string result = "";
    for (int i = 0; i < eq.length(); i++)
    {
        if (isdigit(eq[i]))
        {
            result += eq[i];
        }
        else
        {
            if (s.empty() || eq[i] == '(')
            {
                s.push(eq[i]);
            }
            else if (eq[i] == ')')
            {
                while (s.top() != '(')
                {
                    result += s.top();
                    s.pop();
                }
                s.pop();
            }
            else if ((eq[i] == '+' && (s.top() == '-' || s.top() == '+')) || (eq[i] == '-' && (s.top() == '+' || s.top() == '-')) || (eq[i] == '*' && (s.top() == '/' || s.top() == '*')) || (eq[i] == '/' && (s.top() == '*' || s.top() == '/')))
            {
                result += s.top();
                s.pop();
                s.push(eq[i]);
            }
            else if ((s.top() == '*' || s.top() == '/') && (eq[i] == '+' || eq[i] == '-'))
            {
                result += s.top();
                s.pop();
                s.push(eq[i]);
            }
            else
            {
                s.push(eq[i]);
            }
        }
    }

    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }
    return result;
}