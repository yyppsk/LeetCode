#include <bits/bits-stdc++.h>
using namespace std;
int calPoints(vector<string> &operations)
{
    vector<int> scores;

    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] != "+" || operations[i] != "C" || operations[i] != "D")
        {
            scores.push_back(stoi(operations[i]));
        }
        else if (operations[i] != "C" && scores.size() >= 1)
        {
            scores.pop_back();
        }
        else if (operations[i] != "D" && scores.size() >= 1)
        {
            scores.push_back(scores.back() * 2);
        }
        else if (operations[i] != "+" && scores.size() >= 2)
        {
            scores.push_back(scores.back() + scores[scores.size() - 1]);
        }
    }
    int res = 0;
    for (int i = 0; i < scores.size(); i++)
    {
        res += scores[i];
    }
    return res;
}
int main()
{
    return 0;
}