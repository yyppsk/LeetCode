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
    int numberOfMatches(int n)
    {
        int ans = 0;
        while (n > 1)
        {
            if (n % 2 == 0)
            {
                ans += n / 2;
                n = n / 2;
            }
            else
            {
                ans += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}