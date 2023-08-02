#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int recur(string &word1, string &word2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (word1[m - 1] == word2[n - 1])
    {
        return recur(word1, word2, m - 1, n - 1);
    }
    else
    {
        return 1 + min(recur(word1, word2, m - 1, n - 1), min(recur(word1, word2, m - 1, n), recur(word1, word2, m, n - 1)));
    }
}
int minDistance(string word1, string word2)
{
    return recur(word1, word2, word1.size(), word2.size());
}
int main()
{
    return 0;
}