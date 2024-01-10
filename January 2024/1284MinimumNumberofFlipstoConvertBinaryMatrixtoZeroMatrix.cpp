#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// Convert matrix to a single integer for easy hashing
int toInt(const vector<vector<int>> &mat)
{
    int num = 0;
    for (const auto &row : mat)
    {
        for (int cell : row)
        {
            num = (num << 1) | cell;
        }
    }
    return num;
}

// Flip the cell at (i, j) and its neighbors
void flip(vector<vector<int>> &mat, int i, int j)
{
    int m = mat.size(), n = mat[0].size();
    vector<pair<int, int>> dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (const auto &dir : dirs)
    {
        int ni = i + dir.first, nj = j + dir.second;
        if (ni >= 0 && ni < m && nj >= 0 && nj < n)
        {
            mat[ni][nj] = 1 - mat[ni][nj];
        }
    }
}

int minFlips(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    int start = toInt(mat), target = 0;
    if (start == target)
        return 0;
    queue<int> q;
    unordered_set<int> visited;
    q.push(start);
    visited.insert(start);
    int steps = 0;
    while (!q.empty())
    {
        ++steps;
        int size = q.size();
        while (size--)
        {
            int cur = q.front();
            q.pop();
            vector<vector<int>> curMat = mat;
            int num = cur;
            for (int i = m - 1; i >= 0; --i)
            {
                for (int j = n - 1; j >= 0; --j)
                {
                    curMat[i][j] = num & 1;
                    num >>= 1;
                }
            }
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    flip(curMat, i, j);
                    int next = toInt(curMat);
                    if (next == target)
                        return steps;
                    if (!visited.count(next))
                    {
                        q.push(next);
                        visited.insert(next);
                    }
                    flip(curMat, i, j); // Backtrack
                }
            }
        }
    }
    return -1; // Impossible to reach target
}

int main()
{
    vector<vector<int>> mat = {{0, 0}, {0, 1}};
    cout << minFlips(mat) << endl;
    return 0;
}
