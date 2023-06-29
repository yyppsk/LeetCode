#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string removeOccurrences(string s, string part)
{
    /*Approach 1*/
    int position = s.find(part);
    // cout << position << endl;
    while (position != string::npos)
    {
        s.erase(position, part.length());
        position = s.find(part);
    }

    return s;
}
int main()
{
    cout << removeOccurrences("daabcbaabcbc", "abc");
    return 0;
}