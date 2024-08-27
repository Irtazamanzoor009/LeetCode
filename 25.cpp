#include <iostream>
using namespace std;

int strStr(string haystack, string needle)
{
    // haystack = "sadbutsad", needle = "sad"
    if(haystack.find(needle) <= haystack.size())
    {
        return haystack.find(needle);
    }
    return -1;
}

int main()
{
    cout << strStr("hello","ello");
}