#include <bits/bits-stdc++.h>
using namespace std;
int countPrefixes(vector<string> &words, string s)
{
    int res = 0;

    for (int i = 0; i < words.size(); i++)
    {
        if (words[i].length() > s.length())
            continue;
        int j = 0;
        while (j < words[i].length())
        {
            if (s[j] == words[i][j])
                j += 1;
            else
                break;
        }
        if (j == words[i].length())
            res += 1;
    }

    return res;
}
int main()
{
    return 0;
}