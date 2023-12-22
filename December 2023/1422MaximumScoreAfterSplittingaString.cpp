#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int maxScore(string s)
    {
        int ones = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                ones++;
            }
        }
        int maxi = INT_MIN;
        int zero = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '0')
            {
                zero++;
            }
            else
            {
                ones--;
            }
            maxi = max(maxi, zero + ones);
        }
        return maxi;
    }
};
int main()
{
    cout << maxScore("011101");
    return 0;
}