#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void setZeroes(vector<vector<int>> &matrix)
{
    vector<int> zerorow;
    vector<int> zerocol;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                zerocol.push_back(j);
                zerorow.push_back(i);
            }
        }
    }
    for (auto zero : zerorow)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (zero == i)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    for (auto zero : zerocol)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (zero == j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}};
    vector<vector<int>> matrix2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(matrix2);
    for (int i = 0; i < matrix2.size(); i++)
    {
        for (int j = 0; j < matrix2[i].size(); j++)
        {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}