#include <bits/bits-stdc++.h>
using namespace std;
int findPermutationDifference(string s, string t)
{
    unordered_map<char, int> pos_s, pos_b;
    for (int i = 0; i < s.length(); i++)
    {
        pos_s[s[i]] = i;
        pos_b[t[i]] = i;
    }

    int result = 0;
    for (auto &ch : s)
    {
        result += abs(pos_s[ch] - pos_b[ch]);
    }
    return result;
}
int main()
{
    return 0;
}