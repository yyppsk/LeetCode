#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
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