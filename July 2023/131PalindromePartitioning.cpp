#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void parting(string &s, vector<string> &ans, vector<vector<string>> &result, int idx)
{
    if (idx == s.size())
    {
        result.push_back(ans);
        return;
    }
    for (int i = idx; i < s.size(); i++)
    {
        if (isPallindrome(s, idx, i))
        {
            ans.push_back(s.substr(idx, i - idx + 1));
            parting(s, ans, result, i + 1);
            ans.pop_back();
        }
    }
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