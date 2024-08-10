#include <iostream>
#include <cmath>
using namespace std;

int sumOfArr(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return arr[n - 1] + sumOfArr(arr, n - 1);
}

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumOfDigits(int n)
{
    if (n >= 0 && n <= 9)
    {
        return n;
    }
    return (n % 10) + sumOfDigits(n / 10);
}

int findMax(int arr[], int start, int end)
{
    if (start == end)
    {
        return arr[start];
    }

    int mid = (start + end) / 2;
    int max1 = findMax(arr, start, mid);
    int max2 = findMax(arr, mid + 1, end);
    return (max1 > max2) ? max1 : max2;
}

int findMin(int arr[], int start, int end)
{
    if (start == end)
    {
        return arr[start];
    }

    int mid = (start + end) / 2;
    int min1 = findMin(arr, start, mid);
    int min2 = findMin(arr, mid + 1, end);
    return (min1 < min2) ? min1 : min2;
}

void ReverseString(string &s, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    swap(s[start], s[end]);
    ReverseString(s, start + 1, end - 1);
}

string ReverseString2(string s, int start, int end)
{
    if (start >= end)
    {
        return s;
    }
    swap(s[start], s[end]);
    return ReverseString2(s, start + 1, end - 1);
}

bool isPresent(int arr[], int start, int end, int target)
{
    if (start > end)
    {
        return false;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == target)
    {
        return true;
    }
    if (arr[mid] > target)
    {
        return isPresent(arr, start, mid - 1, target);
    }
    else
    {
        return isPresent(arr, mid + 1, end, target);
    }
}

bool isPresent_Linear(int arr[], int start, int end, int target)
{
    if (arr[start] == target)
    {
        return true;
    }
    if (start > end)
    {
        return false;
    }
    return isPresent_Linear(arr, start + 1, end, target);
}

int Power(int number, int p)
{
    if (p == 0)
    {
        return 1;
    }
    return number * Power(number, p - 1);
}

bool CheckPalindrome(string s, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    if (s[start] != s[end])
    {
        return false;
    }
    return CheckPalindrome(s, start + 1, end - 1);
}

int gcd(int x, int y)
{
    if (x == 0)
    {
        return y;
    }
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

int Count(int arr[], int start, int end, int target, int count)
{
    if (start > end)
    {
        return count;
    }
    if (target == arr[start])
    {
        count++;
    }
    return Count(arr, start + 1, end, target, count);
}

void GeneratePermutations(string s, int left, int right)
{
    if (left == right)
    {
        cout << s << endl;
    }
    for (int i = left; i <= right; i++)
    {
        swap(s[left], s[i]);
        GeneratePermutations(s, left + 1, right);
        swap(s[left], s[i]);
    }
}

// multipy without using *
int multiply(int a, int b)
{
    if (b == 0 || a == 0)
    {
        return 0;
    }
    if (b > 0)
    {
        return a + multiply(a, b - 1);
    }
    else
    {
        return -a + multiply(a, b + 1);
    }
}

void Sum_Of_Even_Odd(int start, int end, int &EvenSum, int &OddSum)
{
    if (start > end)
    {
        return;
    }
    if (start % 2 == 0)
    {
        EvenSum += start;
    }
    else
    {
        OddSum += start;
    }
    Sum_Of_Even_Odd(start + 1, end, EvenSum, OddSum);
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int sumOfPrime(int start, int end)
{
    if (start > end)
    {
        return 0;
    }
    int sum = isPrime(start) ? start : 0;
    return sum + sumOfPrime(start + 1, end);
}

int main()
{
    int sum = sumOfPrime(1,7);
    cout << sum;
}