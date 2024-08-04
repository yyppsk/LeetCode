#include <bits/bits-stdc++.h>
using namespace std;
string finalString(string s)
{
    string result = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'i')
        {
            reverse(result.begin(), result.end());
        }
        else
            result.push_back(s[i]);
    }

    return result;
}

int main()
{
    finalString("poiinter");
    return 0;
}