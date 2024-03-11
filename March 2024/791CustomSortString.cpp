#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<char, int> mp;
    // bool compare(char a, char b) {
    //     if (mp[a] < mp[b]) {
    //         return true;
    //     }
    //     return false;
    // }
    string customSortString(string order, string s)
    {
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            mp[ch] = 28;
        }

        for (int i = 0; i < order.size(); i++)
        {
            mp[order[i]] = i;
        }
        sort(s.begin(), s.end(), [this](char a, char b)
             { return mp[a] < mp[b]; });
        return s;
    }
};
int main()
{
    return 0;
}