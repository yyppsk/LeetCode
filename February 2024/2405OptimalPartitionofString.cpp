#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int partitionString(string s)
    {
        int length = 1;
        unordered_set<char> visited;
        for (int i = 0; i < s.size(); i++)
        {
            if (visited.find(s[i]) != visited.end())
            {
                length++;
                visited.clear();
            }
            visited.insert(s[i]);
        }
        return length;
    }
};

// BIT MANIP
int main()
{
    return 0;
}