#include <bits/bits-stdc++.h>
using namespace std;
bool vowel(char &ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        return true;
    }
    return false;
}
vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
{
    vector<int> precomp(words.size(), 0);
    precomp[0] = vowel(words[0].front()) && vowel(words[0].back()) ? 1 : 0;
    for (int i = 1; i < words.size(); i++)
    {
        if (vowel(words[i].front()) && vowel(words[i].back()))
        {
            precomp[i] = 1;
            precomp[i] += precomp[i - 1];
        }
        else
            precomp[i] = precomp[i - 1];
    }

    vector<int> answer;
    for (int i = 0; i < queries.size(); i++)
    {
        if (queries[i][0] > 0)
        {
            answer.push_back(precomp[queries[i][1]] - precomp[queries[i][0] - 1]);
        }
        else
        {
            answer.push_back(precomp[queries[i][1]]);
        }
    }
    // for (auto &ele : answer)
    // {
    //     cout << ele << " ";
    // }
    return answer;
}
int main()
{
    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
    vowelStrings(words, queries);
    return 0;
}