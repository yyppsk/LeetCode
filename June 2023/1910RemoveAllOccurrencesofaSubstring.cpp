#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int findpos(string s, string part)
{
    string checker = "";
    int i = 0, j = 0;
    for (; i < s.size();)
    {
        cout << "Checking " << s[i] << " and " << part[j] << endl;
        if (part[j] == s[i])
        {
            checker.push_back(s[i]);
            i++, j++;
            if (checker == part)
            {
                return i - part.size() - 1;
            }
        }
        else
        {
            checker = "";
            j = 0;
        }
    }
    return 0;
}
string removeOccurrences(string s, string part)
{
    /*Approach 1
    int position = s.find(part);
    // cout << position << endl;
    while (position != string::npos)
    {
        s.erase(position, part.length());
        position = s.find(part);
    }
*/
    cout << findpos(s, part);
    return "";
}
int main()
{
    cout << removeOccurrences("daabcbaabcbc", "abc");
    return 0;
}