#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
long long mostPoints(vector<vector<int>> &questions)
{
    long long ans = 0;
    vector<long long> dp(questions.size() + 1, 0);
    for (int i = questions.size() - 1; i >= 0; i--)
    {
        int upcoming = questions[i][1] + i + 1;
        if (upcoming >= questions.size())
            dp[i] = questions[i][0];
        else
            dp[i] = questions[i][0] + dp[upcoming];
        ans = max(ans, dp[i]);
        dp[i] = max(dp[i], dp[i + 1]);
    }
    return ans;
    // https://www.youtube.com/watch?v=3H2JHSAUUgY
}
int main()
{
    vector<vector<int>> questions = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    cout << mostPoints(questions);
    return 0;
}