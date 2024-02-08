#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        if (t.size() > n)
        {
            return "";
        }
        unordered_map<char, int> mp;

        for (const char &ch : t)
        {
            mp[ch]++;
        }

        int countNeeded = t.size();
        int i = 0, j = 0, windowsize = INT_MAX;
        int start = 0;
        while (j < n)
        {
            if (mp[s[j]] > 0)
                countNeeded--;
            mp[s[j]]--;

            while (countNeeded == 0)
            {
                // shrink
                int currentwindow = j - i + 1;
                if (windowsize > currentwindow)
                {
                    windowsize = currentwindow;
                    start = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    countNeeded++;

                i++;
            }
            j++;
        }

        return windowsize == INT_MAX ? "" : s.substr(start, windowsize);
    }
};
int main()
{
    return 0;
}