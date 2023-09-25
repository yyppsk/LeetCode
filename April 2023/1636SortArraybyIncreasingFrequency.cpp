#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    static bool compare(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first; // a ascend
    }
    vector<int> frequencySort(vector<int> &nums)
    {
        vector<int> answer;

        map<int, int> frequencyMap;

        for (int i = 0; i < nums.size(); i++)
        {
            frequencyMap[nums[i]]++;
        }

        vector<pair<int, int>> pairVector;

        for (auto i : frequencyMap)
        {
            pairVector.push_back({i.second, i.first});
        }

        sort(pairVector.begin(), pairVector.end(), compare);

        for (int i = 0; i < pairVector.size(); i++)
        {

            int timesOccurNumber = pairVector[i].first;

            int value = pairVector[i].second;

            for (int j = 0; j < timesOccurNumber; j++)
            {

                answer.push_back(value);
            }
        }
        return answer;
    }
};
int main()
{
    return 0;
}