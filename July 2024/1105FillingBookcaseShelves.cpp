#include <bits/bits-stdc++.h>
using namespace std;

vector<vector<int>> memo;
int findMinArrangement(int currentBook, int remainingWidth, int maximumHeight, vector<vector<int>> &books, int n, int shelfWidth)
{
    if (currentBook >= n)
    {
        return maximumHeight;
    }

    if (memo[currentBook][remainingWidth] != -1)
        return memo[currentBook][remainingWidth];

    int keptInCurrentShelf = INT_MAX;
    int keptInNewShelf = INT_MAX;

    if (remainingWidth - books[currentBook][0] >= 0)
    {
        keptInCurrentShelf = findMinArrangement(currentBook + 1, remainingWidth - books[currentBook][0], max(maximumHeight, books[currentBook][1]), books, n, shelfWidth);
    }
    keptInNewShelf = maximumHeight + findMinArrangement(currentBook + 1, shelfWidth - books[currentBook][0], books[currentBook][1], books, n, shelfWidth);

    return memo[currentBook][remainingWidth] = min(keptInCurrentShelf, keptInNewShelf);
}

int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
{

    memo.resize(1000);

    for (int i = 0; i < 1000; ++i)
    {
        memo[i].resize(1000, -1);
    }
    return findMinArrangement(0, shelfWidth, 0, books, books.size(), shelfWidth);
}
int main()
{
    return 0;
}