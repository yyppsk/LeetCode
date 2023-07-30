#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
bool isPallindrome(string &s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}
void parting(string &s, vector<string> &ans, vector<vector<string>> &result, int idx, int count, int &minAns, unordered_map<string, bool> &mp)
{
    if (idx == s.size())
    {
        result.push_back(ans);
        minAns = min(minAns, count);

        return;
    }
    for (int i = idx; i < s.size(); i++)
    {
        if (isPallindrome(s, idx, i))
        {
            ans.push_back(s.substr(idx, i - idx + 1));
            mp[s.substr(idx, i - idx + 1)] = true;
            if (mp[s.substr(idx, i - idx + 1)] == true)
                parting(s, ans, result, i + 1, count + 1, minAns, mp);
            // mp[s.substr(idx, i - idx + 1)] = false
            ans.pop_back();
            for (auto i : mp)
            {
                cout << i.first << " " << i.second << " ";
                cout << endl;
            }
            cout << endl;
        }
        return;
    }
}
int minCut(string s)
{
    vector<string> ans;
    vector<vector<string>> result;
    unordered_map<string, bool> mp;
    int cnt = INT_MAX;
    parting(s, ans, result, 0, 0, cnt, mp);
    return cnt - 1;
}
int main()
{
    cout << minCut("aaab");
    return 0;
}