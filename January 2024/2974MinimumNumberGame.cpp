#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int& ele : nums) {
            pq.push(ele);
        }

        vector<int> result;
        while (!pq.empty()) {
            int alice = pq.top();
            pq.pop();
            int bob = pq.top();
            pq.pop();
            result.push_back(bob);
            result.push_back(alice);
        }

        return result;
    }
};
int main()
{
    return 0;
}