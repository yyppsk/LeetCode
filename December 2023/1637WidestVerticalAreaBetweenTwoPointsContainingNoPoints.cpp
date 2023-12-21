// 1637. Widest Vertical Area Between Two Points Containing No Points
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int maxWidthOfVerticalArea(vector<vector<int>> &points)
{
    sort(points.begin(), points.end());
    int maxi = INT_MIN;
    for (int i = 1; i < points.size(); i++)
    {
        int distanceBetweenTwoPoints = points[i][0] - points[i - 1][0];
        maxi = max(maxi, distanceBetweenTwoPoints);
    }
    return maxi;
}
int main()
{
    return 0;
}