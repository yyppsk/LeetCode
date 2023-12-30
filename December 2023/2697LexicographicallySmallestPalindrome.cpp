#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    string makeSmallestPalindrome(string s)
    {
        int low = 0, high = s.size() - 1;
        while (low <= high)
        {
            if (s[low] == s[high])
            {
                low++, high--;
            }
            else if (s[low] < s[high])
            {
                s[high] = s[low];
            }
            else
            {
                s[low] = s[high];
            }
        }
        return s;
    }
};
int main()
{
    return 0;
}