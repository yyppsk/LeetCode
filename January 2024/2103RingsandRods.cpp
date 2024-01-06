#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int countPoints(string rings)
{
    unordered_map<char, unordered_set<char>> rods;
    for (int i = 0; i < rings.size() - 1; i += 2)
    {
        rods[rings[i + 1]].insert(rings[i]);
    }
    int count = 0;
    for (auto ele : rods)
    {
        // cout << ele.first << ":";
        // for (auto &ele2 : ele.second)
        // {
        //     cout << ele2 << " ";
        // }
        // cout << endl;
        if (ele.second.size() >= 3)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    cout << countPoints("B0B6G0R6R0R6G9");
    return 0;
}