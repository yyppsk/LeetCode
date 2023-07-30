#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
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
            if (mp[s.substr(idx, i - idx + 1)] == false)
            {
                parting(s, ans, result, i + 1, count + 1, minAns, mp);
            }
            ans.push_back(s.substr(idx, i - idx + 1));
            mp[s.substr(idx, i - idx + 1)] = true;

            ans.pop_back();
        }
    }
    return;
}
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
vector<vector<string>> partition(string s)
{
    vector<string> ans;
    vector<vector<string>> result;
    parting(s, ans, result, 0);
    return result;
}
int main()
{
    return 0;
}