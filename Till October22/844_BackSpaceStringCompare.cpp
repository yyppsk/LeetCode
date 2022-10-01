#include <iostream>
#include <vector>

using namespace std;
bool backspaceCompare(string s, string t)
{
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == '#')
        {
            if (i == 0)
            {
                s.erase(i, 1);
            }
            else
            {
                s.erase(i - 1, 2);
                i--;
            }
        }
        else
        {
            i++;
        }
    }
    i = 0;
    while (i < t.size())
    {
        if (t[i] == '#')
        {
            if (i == 0)
            {
                t.erase(i, 1);
            }
            else
            {
                t.erase(i - 1, 2);
                i--;
            }
        }
        else
        {
            i++;
        }
    }
    return s == t;
}
int main()
{
    string s = "ab#c", t = "ad#c";
    cout << backspaceCompare(s, t);
    return 0;
}