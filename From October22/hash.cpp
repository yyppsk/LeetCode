#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
void solve()
{
}
int main()
{
    vector<int> arr = {2, 6, 4, 1, 3, 1, 5};
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        map[arr[i]]++;
    }
    for (auto i : map)
    {
        cout << i.first << ":" << i.second << endl;
    }
    return 0;
}