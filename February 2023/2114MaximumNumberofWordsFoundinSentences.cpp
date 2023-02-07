#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int mostWordsFound(vector<string> &sentences)
{
    int maxim = INT_MIN;
    for (int i = 0; i < sentences.size(); i++)
    {
        int count = 1;
        for (int j = 0; j < sentences[i].size(); j++)
            if (sentences[i][j] == ' ')
                count++;
        maxim = max(maxim, count);
    }
    return maxim;
}
int main()
{
    vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    cout << mostWordsFound(sentences);
    return 0;
}