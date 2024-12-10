#include <bits/bits-stdc++.h>
using namespace std;

int maximumLength(string s)
{
    unordered_map<string, int> count;
    for (int start = 0; start < s.length(); start++)
    {
        string currString;
        for (int end = start; end < s.length(); end++)
        {
            if (currString.empty() or currString.back() == s[end])
            {
                currString.push_back(s[end]);
                count[currString]++;
            }
            else
            {
                break;
            }
        }
    }

    int ans = 0;
    for (auto i : count)
    {
        string str = i.first;
        if (i.second >= 3 && str.length() > ans)
            ans = str.length();
    }
    if (ans == 0)
        return -1;
    return ans;
}

// Space Optimal

int maximumLength_2(string s)
{
    int n = s.length();

    map<pair<char, int>, int> mp;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        int l = 0;
        for (int j = i; j < n; j++)
        {
            if (s[j] == ch)
            {
                l++;
                mp[{ch, l}]++;
            }
            else
            {
                break;
            }
        }
    }

    int result = 0;
    for (auto &it : mp)
    {
        // char ch = it.first.first;
        int length = it.first.second;
        int freq = it.second;

        if (freq >= 3 && length > result)
        {
            result = length;
        }
    }

    return result == 0 ? -1 : result;
}
int main()
{
    string s = "ababab";
    maximumLength(s);
    return 0;
}