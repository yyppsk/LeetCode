#include <bits/bits-stdc++.h>
using namespace std;

bool canMakeSubsequence(string str1, string str2)
{

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int m = str1.size(), n = str2.size();
    if (m < n)
        return false;
    int i = 0, j = 0;

    while (i < str1.length() && j < str2.length())
    {
        if (str2[j] == str1[i])
        {
            i += 1, j += 1;
        }
        else
        {
            char convert = (str1[i] - 'a' + 1) % 26 + 'a';
            if (convert == str2[j])
            {
                i += 1, j += 1;
            }
            else
            {
                i += 1;
            }
        }
    }

    if (j == str2.length())
    {
        return true;
    }
    return false;
}
int main()
{
    char ch = 'z';
    char convert = (ch - 'a' + 1) % 26 + 'a';
    cout << convert;
    return 0;
}