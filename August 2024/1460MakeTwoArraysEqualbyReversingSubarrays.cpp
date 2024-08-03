#include <bits/bits-stdc++.h>
using namespace std;
bool canBeEqual(vector<int> &target, vector<int> &arr)
{
    unordered_set<int> t1(target.begin(), target.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (t1.find(arr[i]) == t1.end())
            return false;
    }
    return true;
}
int main()
{
    return 0;
}