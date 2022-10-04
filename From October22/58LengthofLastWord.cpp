#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int lengthOfLastWord(string s)
{
    if (s.size() == 0)
        return 0;
    if (s.size() == 1 && s[0] != ' ')
    {
        return 1;
    }
    int end = s.size() - 1;
    int trailspaces = 0;
    int trackerword = 0;
    if (s[end] == ' ')
    {
        int trailspaces = 1;
    }
    int length = 0;
    do
    {
        if (s[end] != ' ')
        {
            trackerword = 1;
            ++length;
        }
        if ((trackerword == 1) && (s[end] == ' '))
        {
            return length;
        }
        // printf("%c Length %d\n", s[end], length);
        end--;
    } while (end >= 0);
    return length;
}
int main()
{
    string str = "aa";
    cout << lengthOfLastWord(str);
    return 0;
}