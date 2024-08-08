#include <bits/bits-stdc++.h>
using namespace std;
vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
{
    vector<int> UAM(k, 0);
    unordered_map<int, unordered_set<int>> userActionsTime;
    for (int i = 0; i < logs.size(); i++)
    {
        userActionsTime[logs[i][0]].insert(logs[i][1]);
    }

    for (const auto &user : userActionsTime)
    {
        UAM[user.second.size() - 1]++;
    }
    return UAM;
}
int main()
{
    return 0;
}
/*

0 - 5 2
1 - 2 3



*/