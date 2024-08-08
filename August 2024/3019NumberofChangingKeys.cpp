#include <bits/bits-stdc++.h>
using namespace std;
int countKeyChanges(string s)
{
    int change = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (tolower(s[i - 1]) != tolower(s[i]))
        {
            change += 1;
        }
    }

    return change;
}
int main()
{
    return 0;
}