#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    // Brute force solution
    bool isPallindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++, end--;
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {

                if (isPallindrome(s, i, j))
                {
                    string ourPossibleString = s.substr(i, j - i + 1);
                    ans = ourPossibleString.size() > ans.size() ? ourPossibleString : ans;
                }
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}