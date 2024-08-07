#include <bits/bits-stdc++.h>
using namespace std;

char shift(char c, int x)
{
    return c + x;
}
string replaceDigits(string s)
{

    for (int i = 1; i < s.size(); i++)
    {
        s[i] = shift(s[i - 1], s[i] - '0');
    }
    return s;
}

int main()
{
    replaceDigits("a1");
    return 0;
}