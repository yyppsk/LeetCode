#include <bits/bits-stdc++.h>
using namespace std;
bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int x1 = coordinates[1][0];
    int y1 = coordinates[1][1];

    int dx = x1 - x0;
    int dy = y1 - y0;

    for (int i = 2; i < coordinates.size(); i++)
    {
        int xi = coordinates[i][0];
        int yi = coordinates[i][1];
        if (dy * (xi - x0) != dx * (yi - y0))
        {
            return false;
        }
    }
    return true;
}
int main()
{

    vector<vector<int>> case1 =
        {{-3, -2}, {-1, -2}, {2, -2}, {-2, -2}, {0, -2}};

    cout << checkStraightLine(case1);
    return 0;
}