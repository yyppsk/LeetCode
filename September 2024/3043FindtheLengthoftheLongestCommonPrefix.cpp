#include <bits/bits-stdc++.h>
using namespace std;
int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    unordered_map<string, int> s1;
    for (int i = 0; i < arr1.size(); i++)
    {
        string curr = to_string(arr1[i]);

        for (int j = 1; j <= curr.length(); j++)
        {
            s1.insert({curr.substr(0, j),
                       j});
        }
    }

    // for (auto &ele : s1)
    // {
    //     cout << ele.first << ":" << ele.second << "\n";
    // }

    int currMax = 0;
    for (int i = 0; i < arr2.size(); i++)
    {
        string curr = to_string(arr2[i]);

        for (int j = 0; j <= curr.length(); j++)
        {
            if (s1.find(curr.substr(0, j)) != s1.end())
            {
                if (s1[curr.substr(0, j)] > currMax)
                {
                    currMax = s1[curr.substr(0, j)];
                }
            }
        }
    }

    return currMax;
}
int main()
{
    vector<int> arr1, arr2;
    arr1 = {98765432}, arr2 = {987};
    cout << longestCommonPrefix(arr1, arr2);
    return 0;
}