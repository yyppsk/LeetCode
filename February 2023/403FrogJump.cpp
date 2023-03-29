#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
bool cross3(vector<int> &stones)
{
    unordered_map <int , <set>
}
int cross2(vector<int> &stones, int curr, int prev)
{
    for (int i = curr + 1; i < stones.size(); i++)
    {
        int gap = stones[i] - stones[curr];
        if (gap >= prev - 1 && gap <= prev + 1)
        {
            if (cross2(stones, i, gap))
                return true;
        }
    }
    return curr == stones.size() - 1 ? true : false;
}
bool cross(vector<int> &stones, int curr, int prev)
{
    for (int i = curr + 1; i < stones.size(); i++)
    {
        int gap = stones[i] - stones[curr];
        if (gap >= prev - 1 && gap <= prev + 1)
        {
            if (cross(stones, i, gap))
                return true;
        }
    }
    return curr == stones.size() - 1 ? true : false;
}
bool canCross(vector<int> &stones)
{
    vector<vector<int>> meme(stones.size(), vector<int>(stones.size(), 0));
    // return cross(stones, 0, 0);
}
int main()
{
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << canCross(stones);
    return 0;
}