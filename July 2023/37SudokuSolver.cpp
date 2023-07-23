#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<vector<char>> &board, int row, int col, char val)
    {
        // for the row
        // for the col
        // for the whole freaking box
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            if (board[row][i] == val)
                return false;
            if (board[i][col] == val)
                return false;
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == val)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char val = '1'; val <= '9'; val++)
                    {
                        // trying to check if I can inser some value 0 to 9 into this particular
                        // cell
                        if (isPossible(board, i, j, val))
                        {
                            // insert it
                            board[i][j] = val;
                            bool furtherPossible = solve(board);
                            // recur for more values
                            // this furtherPossible ensures that the current cell decision made is right and makes decisions for backtracking
                            if (furtherPossible)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
int main()
{
    return 0;
}