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

// precompute

int countPalindromicSubsequence(string s)
{
    int n = s.length();
    vector<pair<int, int>> indices(26, {-1, -1});

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        int idx = ch - 'a';

        if (indices[idx].first == -1)
        {
            indices[idx].first = i;
        }

        indices[idx].second = i;
    }

    int result = 0;
    for (int i = 0; i < 26; i++)
    {
        if (indices[i] == make_pair(-1, -1))
        {
            continue;
        }

        unordered_set<char> st;
        for (int middle = indices[i].first + 1; middle <= indices[i].second - 1; middle++)
        {

            st.insert(s[middle]);
        }

        result += st.size();
    }

    return result;
}
int main()
{
    string s = "aabca";
    countPalindromicSubsequence(s);
    return 0;
}