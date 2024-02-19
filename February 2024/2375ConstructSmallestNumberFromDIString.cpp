#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string smallestNumber(string pattern)
    {
        int j = 0, n = pattern.size();
        string res = "";
        for (int i = 0; i <= n; i++)
        {
            res.push_back('1' + i);
            if (i == n || pattern[i] == 'I')
            {
                reverse(res.begin() + j, res.end());
                j = i + 1;
            }
        }
        return res;
    }
};
int main()
{
    return 0;
}