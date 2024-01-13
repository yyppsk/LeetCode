#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
using namespace std;
class RecentCounter
{
public:
    queue<int> requests;
    RecentCounter()
    {
    }

    int ping(int t)
    {
        requests.push(t);
        if (requests.front() < t - 3000)
        {
            requests.pop();
        }
        return requests.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
int main()
{
    return 0;
}