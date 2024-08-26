#include <bits/bits-stdc++.h>
using namespace std;
class Solution
{
public:
    int countKConstraintSubstrings(string s, int k)
    {
        int l = 0, r = 0;
        int one = 0, zero = 0;
        int ans = 0;

        while (r < s.size())
        {
            if (s[r] == '0')
                zero++;
            else
                one++;

            while (zero > k && one > k)
            {
                if (s[l] == '0')
                    zero--;
                else
                    one--;
                l++;
            }

            ans += (r - l + 1);
            r++;
        }

        return ans;
    }
};
int main()
{
    return 0;
}