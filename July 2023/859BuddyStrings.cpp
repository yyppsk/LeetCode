#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool buddyStrings(string s, string goal)
{
    int i = 0, j = s.size() - 1;
    while ()
    {
        if (s[i] != goal[i])
        {
            char nowfindme = goal[i];
            for (auto it = goal.rbegin(); it != goal.rend(); ++it)
            {
                if (*it == nowfindme)
                {
                                }
            }
        }
    }
}
int main()
{
    buddyStrings("abcbcadefck", "abckcadefcb") ? cout << "true" : cout << "false";
    return 0;
}