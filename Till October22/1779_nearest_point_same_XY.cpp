#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int nearestValidPoint(int x, int y, vector<vector<int>> &points)
{
    int min_dist = 9999999;
    int dist;
    int index = -1;
    // printf("%d",points.size());
    if (points.size() == 1)
    {
        if (points[0][0] == x && points[0][1] == y)
            cout << 0;
        else
            cout << -1;
    }
    for (int i = 0; i < points.size(); i++)
    {
        if (x != points[i][0] && y != points[i][1])
        {
            continue;
        }
        else
        {
            dist = abs(x - points[i][0]) + abs(y - points[i][1]);
            if (dist < min_dist)
            {
                min_dist = dist;
                index = i;
            }
        }
    }
    return index;
}
int main()
{ //, {3, 1}, {2, 4}, {2, 3}, {4, 4
    vector<vector<int>> points = {{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
    nearestValidPoint(3, 4, points);
    return 0;
}