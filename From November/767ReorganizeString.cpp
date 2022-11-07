#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
string reorganizeString(string s)
{
    unordered_map<int, int> mask_map;
    for (auto a : s)
    {
        mask_map[a]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>> 
}
int main()
{
    return 0;
}
