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
    int minSteps(string s, string t)
    {
        int freqS[26] = {0};
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            freqS[s[i] - static_cast<int>('a')]++;
            freqS[t[i] - static_cast<int>('a')]--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (freqS[i] > 0)
            {
                // becasue of extra chars in t may lead to -ve frequency
                ans += freqS[i];
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}