#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    if (s.length() < 2)
        return s.length();
    unordered_map<char, int> mp;
    int start = 0, end = 0;
    int mxlen = 0;
    while (end < s.size())
    {
        char ch = s[end];
        for (auto ele : mp)
        {
            cout << ele.first << " : " << ele.second << endl;
        }
        cout << endl;
        auto it = mp.find(ch);
        if (it != mp.end())
        {
            mxlen = max(mxlen, end - start);
            start = max(start, mp[s[end]] + 1);
        }
        mp[ch] = end++;
    }
    return max(mxlen, end - start);
}
int main()
{
    cout << lengthOfLongestSubstring("abcabcbb");
    return 0;
}