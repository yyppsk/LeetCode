#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {0, 0}};
void recur(vector<vector<char>> &board, string word, int x, int y, string required, int idx)
{
    if (required == word)
        return;

    for (auto &el : delta)
    {
        int movex = el.first + x;
        int movey = el.second + y;

        if (movex >= 0 && movey >= 0 && movex < board.size() && movey < board[0].size())
        {
            if (board[movex][movey] == word[idx])
            {
                required += word[idx];
                recur(board, word, movex, movey, required, idx + 1);
            }
        }
    }
}
bool exist(vector<vector<char>> &board, string word)
{
}
int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    exist(board, word);
    return 0;
}