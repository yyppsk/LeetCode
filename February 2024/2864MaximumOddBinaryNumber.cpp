#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        sort(s.begin(), s.end(), greater<int>());
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
                swap(s[i], s[s.size() - 1]);
        }
        return s;
    }
};

int main()
{
    return 0;
}