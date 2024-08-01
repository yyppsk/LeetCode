#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void rotateNaive(vector<vector<int>> &matrix)
{
    // trying to fill the stuff, coloumn wise firstly
    vector<vector<int>> res(matrix.size(), vector<int>(matrix.size(), 0));

    int i = 0, j = 0;
    for (int col = matrix.size() - 1; col >= 0; col--)
    {

        for (int row = 0; row <= matrix.size() - 1; row++)
        {
            // cout << "(" << col << "," << row << ")"<< "=> " << i << "," << j;
            res[i++][j] = matrix[col][row];
        }
        i = 0, j++;
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            matrix[i][j] = res[i][j];
        }
    }
}
void rotate(vector<vector<int>> &matrix)
{
    // trying to fill the stuff, coloumn wise firstly

    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = i + 1; j < matrix[i].size(); ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
            for (auto e : matrix)
            {
                for (auto k : e)
                {
                    cout << k << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
    return 0;
}