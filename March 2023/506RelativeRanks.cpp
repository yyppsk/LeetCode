#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;
vector<string> findRelativeRanks(vector<int> &score)
{
    vector<string> answer;
    unordered_map<int, int> mp;
    vector<int> scorenew(score);
    sort(scorenew.begin(), scorenew.end(), greater<int>());
    int rank = 1;
    for (auto i : scorenew)
    {
        mp[i] = rank++;
        cout << i << " ";
    }
    cout << endl;
    for (auto i : mp)
    {
        cout << i.first << " : " << i.second << endl;
    }
    for (int i = 0; i < score.size(); i++)
    {
        if (mp[score[i]] == 1)
        {
            answer.push_back("Gold Medal");
        }
        else if (mp[score[i]] == 2)
        {
            answer.push_back("Silver Medal");
        }
        else if (mp[score[i]] == 3)
        {
            answer.push_back("Bronze Medal");
        }
        else
            answer.push_back(to_string(mp[score[i]]));
    }
    for (auto i : answer)
    {
        cout << i << " ";
    }
    return {};
}
int main()
{
    vector<int> score = {10, 3, 8, 9, 4};
    //["Gold Medal","5","Bronze Medal","Silver Medal","4"]
    findRelativeRanks(score);
    return 0;
}