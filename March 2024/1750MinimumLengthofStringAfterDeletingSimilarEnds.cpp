#include <bits/stdc++.h>
using namespace std;
int minimumLength(string s)
{

    int start = 0, end = s.size() - 1;

    while (start < end)
    {
        if (s[start] == s[end])
        {
            char ch = s[start];
            while (start <= end && s[start] == ch)
            {
                start++;
            }
            while (start < end && s[end] == ch)
            {
                end--;
            }
        }
        else
            break;
    }

    return end - start + 1;
}
int main()
{
    cout << minimumLength("cac");
    return 0;
}