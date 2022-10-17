#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <deque>
#include <queue>
#include <string>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++; // calculating frequency
    }
    unordered_map<int, int>::iterator it = m.begin();
    priority_queue<pair<int, int>> pq;
    for (; it != m.end(); it++)
    {
        pq.push(make_pair(it->second, it->first));
        // pushing pair of <frequency,distinct element of nums array> so that we get most occuring element on top
    }
    it = m.begin();
    for (; it != m.end(); it++)
    {
        cout << pq.top().first << ":" << pq.top().second << endl;
        pq.pop();
    }
    vector<int> ans;
    int a = 0;
    while (a < k)
    {
        ans.push_back(pq.top().second);
        pq.pop(); // popping k top most elements, inserting in our answer vector and returning the answer.
        a++;
    }
    return ans;
}
int main()
{
    vector<int> nums = {3, 6, 1, 1, 1, 2, 2, 3};
    int k = 2;
    topKFrequent(nums, k);
    return 0;
}