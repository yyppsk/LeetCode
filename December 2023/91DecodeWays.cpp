#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<int, int> dp;
int numDecodings(string s, int idx)
{
    if (s[idx] == '0')
        return 0;
    if (idx >= s.length() - 1)
        return 1;

    if (dp.find(idx) != dp.end())
        return dp[idx];
    int ans = numDecodings(s, idx + 1);
    if (stoi(s.substr(idx, 2)) <= 26)
    {
        ans += numDecodings(s, idx + 2);
    }

    return dp[idx] = ans;
}
int main()
{
    cout << numDecodings("2263", 0) << endl;
    for (auto &ele : dp)
    {
        cout << ele.first << " : " << ele.second << endl;
    }
    return 0;
}