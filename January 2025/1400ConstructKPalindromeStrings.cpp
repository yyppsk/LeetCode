#include <bits/bits-stdc++.h>
using namespace std;
bool canConstruct(string s, int k)
{
    if (k == s.length() || k > s.length())
        return true;
    array<int, 26> frequency = {};
    for (char &c : s)
    {
        ++frequency[c - 'a'];
    }
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] % 2 == 1)
        {
            ++count;
        }

        if (count > k)
        {
            return false;
        }
    }

    return true;
}
int main()
{
    return 0;
}