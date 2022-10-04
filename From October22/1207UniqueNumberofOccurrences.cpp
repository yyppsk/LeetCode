#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> map;
    for (auto i : arr)
    {
        map[i]++;
    }
    for (auto i : map)
    {
        cout << i.first << ":" << i.second << endl;
    }
    unordered_set<int> keys;
    for (auto i : map)
    {
        keys.insert(i.second);
    }
    if (keys.size() == map.size())
        return true;
    else
        return false;
}
int main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    cout << uniqueOccurrences(arr);
    return 0;
}