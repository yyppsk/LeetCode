#include <bits/bits-stdc++.h>
using namespace std;

int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    vector<pair<int, int>> jobs;

    for (int i = 0; i < difficulty.size(); i++)
    {
        jobs.push_back({profit[i], difficulty[i]});
    }

    sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());

    int result = 0;
    for (int i = 0; i < worker.size(); i++)
    {

        for (auto &ele : jobs)
        {
            if (ele.second <= worker[i])
            {
                result += ele.first;
                break;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> difficulty = {2, 4, 6, 8, 10}, profit = {50, 40, 30, 20, 10}, worker = {4, 5, 6, 7};
    cout << maxProfitAssignment(difficulty, profit, worker);
    return 0;
}