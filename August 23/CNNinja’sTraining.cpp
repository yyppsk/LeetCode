#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int spaceOptimzed(int n, vector<vector<int>> &points)
{
    vector<int> previous(4, 0);

    previous[0] = max(points[0][1], points[0][2]);
    previous[1] = max(points[0][0], points[0][2]);
    previous[2] = max(points[0][0], points[0][1]);
    previous[3] = max(points[0][1], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> current(4, 0); // har day pr ek new set bnega
        for (int last = 0; last < 4; last++)
        {
            current[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + previous[task];
                    current[last] = max(point, previous[task]);
                }
            }
            previous = current;
        }
    }
    return previous[3];
}
int pureDp(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(points.size(), vector<int>(4, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(point, dp[day][last]);
                }
            }
        }
    }
    return dp[n - 1][3];
}
int recurMemoize(int day, vector<vector<int>> &points, int last, vector<vector<int>> &dp)
{

    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return dp[day][last] = maxi;
    }
    int maxi = 0;
    if (dp[day][last] != -1)
        return dp[day][last];
    for (int taskNumber = 0; taskNumber < 3; taskNumber++)
    {
        if (taskNumber != last)
        {
            int take = points[day][taskNumber] + recurMemoize(day - 1, points, taskNumber, dp);
            maxi = max(maxi, take);
        }
    }
    return dp[day][last] = maxi;
}
int recurMemoize(int day, vector<vector<int>> &points, int last)
{

    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for (int taskNumber = 0; taskNumber < 3; taskNumber++)
    {
        if (taskNumber != last)
        {
            int take = points[day][taskNumber] + recur(day - 1, points, taskNumber);
            maxi = max(maxi, take);
        }
    }
    return maxi;
}
int recur(int day, vector<vector<int>> &points, int last)
{

    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for (int taskNumber = 0; taskNumber < 3; taskNumber++)
    {
        if (taskNumber != last)
        {
            int take = points[day][taskNumber] + recur(day - 1, points, taskNumber);
            maxi = max(maxi, take);
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    return recur(n - 1, points, 3);
}
int main()
{
    return 0;
}