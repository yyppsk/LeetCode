#include "./bits/bits-stdc++.h"

using namespace std;
int main()
{
    unordered_map<int, int> mp;

    vector<int> arr = {1, 1, 1, 2, 3, 4, 44, 44, 5, 99, 99, 9, 9, 9, 5, 5, 5};

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    for (int &ele : arr)
    {
        mp[ele]++;
    }

    for (auto &element : mp)
    {
        cout << element.first << " : " << element.second << endl;
    }
    return 0;
}