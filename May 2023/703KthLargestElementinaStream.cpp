#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
class KthLargest
{
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, std::vector<int> &nums)
    {
        this->k = k;
        for (int num : nums)
        {
            add(num);
        }
    }
    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
        {
            pq.pop();
        }
        return pq.top();
    }
};
int main()
{
    vector<int> arr = {10, 2, 4, 8, 6, 9};
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const auto &i : arr)
    {
        pq.push(i);
    }
    while (!pq.empty())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}