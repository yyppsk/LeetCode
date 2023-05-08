#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int diagonalSum(vector<vector<int>> &mat)
{
    int left = 0, right = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
        {
            if (i == j)
                left += mat[i][j];
            if (i + j == mat.size() - 1 && (i != j))
                right += mat[i][j];
        }
    }
    // cout << left << endl;
    // cout << right << endl;
    return left + right;
    // Approach 2
    int n = mat.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        // Add elements from primary diagonal.
        ans += mat[i][i];
        // Addd elements from secondary diagonal.
        ans += mat[n - 1 - i][i];
    }
    // If n is odd, subtract the middle element as its added twice.
    if (n % 2 != 0)
    {
        ans -= mat[n / 2][n / 2];
    }

    return ans;
}
int main()
{
    vector<vector<int>> mat = {{1, 1, 1, 1},
                               {1, 1, 1, 1},
                               {1, 1, 1, 1},
                               {1, 1, 1, 1}};
    cout << diagonalSum(mat);
    return 0;
}