#include <bits/bits-stdc++.h>
using namespace std;
string kthDistinct(vector<string> &arr, int k)
{
    unordered_map<string, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (mp[arr[i]] == 1)
        {
            k--;
            if (k == 0)
            {
                return arr[i];
            }
        }
    }

    return "";
}

int main()
{
    vector<string> arr = {"d", "b", "c", "b", "c", "a"};
    int k = 2;
    kthDistinct(arr, k);
    return 0;
}