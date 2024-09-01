#include <bits/bits-stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        vector<string> res;
        for (char c = s[0]; c <= s[3]; ++c)
            for (char r = s[1]; r <= s[4]; ++r)
                res.push_back({c, r});
        return res;
    }
};
int main()
{
    return 0;
}