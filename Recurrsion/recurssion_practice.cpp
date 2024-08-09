#include <iostream>
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

int main()
{
    int sum = sumOfDigits(56459);
    cout << sum;
}