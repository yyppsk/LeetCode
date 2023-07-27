#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void findWays(int col, vector<vector<string>> &ans, vector<string> &board, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n - 1 + (col - row)] == 0)
        {
            // Checkedd safety
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperDiagonal[row + col] = 1;
            lowerDiagonal[n - 1 + (col - row)] = 1;
            findWays(col + 1, ans, board, leftRow, upperDiagonal, lowerDiagonal, n);
            // Back Track
            board[row][col] = '.';
            leftRow[row] = 0;
            upperDiagonal[row + col] = 0;
            lowerDiagonal[n - 1 + (col - row)] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    string s(n, '.');
    vector<string> board(n, s);
    // string s(n,'.');
    //  for(int i = 0; i < s.size(); i++){

    // }
    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); // as 14 numbers in a 8*8 chessboard;
    findWays(0, ans, board, leftRow, upperDiagonal, lowerDiagonal, n);
    return ans;
}
int main()
{
    return 0;
}