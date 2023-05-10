#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{

    vector<vector<int>> res(n, vector<int>(n, 0));
    int row = n, col = n;
    int count = 1;
    int up = 0, down = row - 1, left = 0, right = col - 1;

    while (count <= n * n)
    {
        for (int j = left; j <= right && count <= n * n; j++)
        {
            res[up][j] = count++;
        }
        up++;

        for (int i = up; i <= down && count <= n * n; i++)
        {
            res[i][right] = count++;
        }
        right--;

        for (int j = right; j >= left && count <= n * n; j--)
        {
            res[down][j] = count++;
        }
        down--;

        for (int i = down; i >= up && count <= n * n; i--)
        {
            res[i][left] = count++;
        }
        left++;
    }

    return res;
}

int main()
{
    vector<vector<int>> res = generateMatrix(20);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
