#include <bits/bits-stdc++.h>
using namespace std;
string addSpaces(string s, vector<int> &spaces)
{
    string res;
    for (int i = 0, j = 0; i < s.size(); ++i)
    {
        if (j < spaces.size() && i == spaces[j])
        {
            res += " ";
            ++j;
        }
        res += s[i];
    }
    return res;
}
int main()
{
    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8, 13, 15};
    addSpaces(s, spaces);
    return 0;
}