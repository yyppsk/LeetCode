#include <bits/bits-stdc++.h>
using namespace std;
int countPalindromicSubsequence(string s)
{
    unordered_set<char> charachters;
    int subseq = 0;
    for (int i = 0; i < s.length(); i++)
    {
        charachters.insert(s[i]);
    }

    for (auto &ch : charachters)
    {
        int start = -1, end = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ch)
            {
                if (start == -1)
                {
                    start = i;
                }

                end = i;
            }
        }
        unordered_set<char> gapElements;

        for (int i = start + 1; i < end; i++)
        {
            gapElements.insert(s[i]);
        }

        subseq += gapElements.size();
    }

    return subseq;
}
int main()
{
    string s = "aabca";
    countPalindromicSubsequence(s);
    return 0;
}