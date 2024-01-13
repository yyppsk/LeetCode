#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
class SmallestInfiniteSet
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> visitedSet;
    SmallestInfiniteSet()
    {
        for (int i = 1; i < 1001; i++)
        {
            pq.push(i);
            visitedSet.insert(i);
        }
    }

    int popSmallest()
    {
        int smallest = pq.top();
        pq.pop();
        visitedSet.erase(smallest);
        return smallest;
    }

    void addBack(int num)
    {
        if (visitedSet.find(num) == visitedSet.end())
        {
            pq.push(num);
            visitedSet.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
int main()
{
    return 0;
}