#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool rotateString(string s, string goal)
{
    // Naive
    int idx = 0;
    while (idx < s.size())
    {
        char first = s[0];
        s.erase(s.begin());
        s.push_back(first);
        if (s == goal)
            return true;
        idx++;
    }
    return false;
}
int main()
{
    return 0;
}