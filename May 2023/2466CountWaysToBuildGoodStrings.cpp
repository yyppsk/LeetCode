#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define mod 1000000007
using namespace std;
void generate(string str, int size)
{

    if (size <= 0)
    {
        cout << str << endl;
        return;
    }
    generate(str + "0", size - 1);
    str.pop_back();
    // take 0
    generate(str + "1", size - 1);
    str.pop_back();
    // take 1
}
int countGoodStrings(int low, int high, int zero, int one)
{
    vector<int> dp(high + 1, 0);
    dp[0] = 1;
    int ans = 0;
    for (int len = 1; len <= high; len++)
    {
        if (len >= zero)
            dp[len] = dp[len - zero];
        if (len >= one)
            dp[len] = (dp[len] + dp[len - one]) % mod;
        if (len >= low)
            ans = (ans + dp[len]) % mod;
    }
    return ans;
}
int main()
{
    generate("", 3);
    return 0;
}