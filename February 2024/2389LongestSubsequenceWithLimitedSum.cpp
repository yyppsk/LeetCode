#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin(), nums.end());
        int m = queries.size();
        vector<int> answer;
        for (int i = 0; i < m; i++)
        {
            int sum = 0;
            int ctr = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum < queries[i])
                {
                    ctr++;
                }
                else if (sum == queries[i])
                {
                    ctr++;
                    break;
                }
                else
                {
                    break;
                }
            }
            answer.push_back(ctr);
        }
        return answer;
    }
};
int main()
{
    return 0;
}