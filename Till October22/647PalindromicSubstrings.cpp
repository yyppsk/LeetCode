#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int countSubstrings(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, false));
    int counter = 0;
    for (int g = 0; g < n; g++)
    {
        int i = 0;
        int j = g;
        while (j < n)
        {
            if (g == 0)
            {
                dp[i][j] = true;
                counter++;
            }
            else if (g == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = true;
                    counter++;
                }
            }
            else
            {
                if (s[i] == s[j])
                {
                    if (dp[i + 1][j - 1] == true)
                    {
                        dp[i][j] = true;
                        counter++;
                    }
                }
            }
            j++;
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return counter;
}
int main()
{
    string s = "abccbc";
    cout << countSubstrings(s);
    return 0;
}