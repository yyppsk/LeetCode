#include <bits/bits-stdc++.h>
using namespace std;
int appendCharacters(string s, string t)
{
    int i = 0, j = 0;
    int count = 0;
    while (j < t.size() && i < s.size())
    {
        if (s[i] == t[j])
        {
            i++, j++;
        }
        else
        {
            i++;
        }
    }

    if (j == t.size())
    {
        return 0;
    }
    if (j != t.size() && i == s.size())
    {
        count += ((t.size() - 1) - j + 1);
        return count;
    }
    return -1;
}
int main()
{
    cout << "1 :"
         << appendCharacters("coaching", "coding") << "\n";
    cout << "2 :"
         << appendCharacters("abcde", "a") << "\n";
    cout << "3 :"
         << appendCharacters("z", "abcde") << "\n";
    cout << "4 :"
         << appendCharacters("abcde", "az") << "\n";
    cout << "5 :"
         << appendCharacters("a", "a") << "\n";
    cout << "5 :"
         << appendCharacters("at", "cat") << "\n";

    return 0;
}