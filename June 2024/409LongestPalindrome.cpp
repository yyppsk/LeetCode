#include <bits/bits-stdc++.h>
using namespace std;
int longestPalindrome(string s)
{
    unordered_map<int, int> mp;
    for (const char &ch : s)
    {
        mp[ch]++;
    }
    int length = 0;
    int odd = 0;
    int atleast = 0;
    for (const auto &ele : mp)
    {
        if (ele.second % 2 == 0)
        {
            length += ele.second;
        }
        else
        {
            atleast = 1;
            odd += (ele.second - 1);
        }
    }
    return length + odd + atleast;
}
int main()
{
    string s = "aaabccccdd";

    cout << longestPalindrome(s);
    return 0;
}