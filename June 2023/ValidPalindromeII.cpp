#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isPallindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        else
        {
            i++, j--;
        }
    }
    return true;
}
bool validPalindrome(string s)
{
    int i = 0, j = s.size() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return isPallindrome(s, i + 1, j) || isPallindrome(s, i, j - 1);
        }
        else
        {
            i++, j--;
        }
    }
    return true;
}
int main()
{
    string s = "abc";
    cout << validPalindrome(s);
    return 0;
}