#include <bits/bits-stdc++.h>
using namespace std;
vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> diagonals;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            diagonals[i - j].push(mat[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            mat[i][j] = diagonals[i - j].top(), diagonals[i - j].pop();
        }
    }
    return mat;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}};
    diagonalSort(mat);
    return 0;
}