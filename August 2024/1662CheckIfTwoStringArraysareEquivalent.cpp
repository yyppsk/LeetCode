#include <bits/bits-stdc++.h>
using namespace std;

bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
{
    string a = "", b = "";
    for (int i = 0; i < word1.size(); i++)
    {
        for (int j = 0; j < word1[i].size(); j++)
        {
            a.push_back(word1[i][j]);
        }
    }

    for (int i = 0; i < word2.size(); i++)
    {
        for (int j = 0; j < word2[i].size(); j++)
        {
            b.push_back(word2[i][j]);
        }
    }

    return a == b;
}
int main()
{
    return 0;
}