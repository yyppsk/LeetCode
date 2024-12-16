#include <bits/bits-stdc++.h>
using namespace std;

string removeStars(string s)
{
    string sol;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '*')
        {
            sol.push_back(s[i]);
        }
        else
        {
            sol.pop_back();
        }
    }

    return sol;
}
int main()
{
    string s = "leet**cod*e";
    cout << removeStars(s);
    return 0;
}