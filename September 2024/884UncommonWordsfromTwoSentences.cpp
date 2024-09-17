#include <bits/bits-stdc++.h>
using namespace std;
vector<string> uncommonFromSentences(string s1, string s2)
{
    unordered_map<string, int> mp1;
    stringstream obj(s1 + " " + s2);
    string token;
    while (getline(obj, token, ' '))
    {
        mp1[token]++;
    }
    vector<string> ans;
    for (const auto &ele : mp1)
    {
        if (ele.second == 1)
        {
            ans.push_back(ele.first);
        }
    }

    return ans;
}
int main()
{
    return 0;
}