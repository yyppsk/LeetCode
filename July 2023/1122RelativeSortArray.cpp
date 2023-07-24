#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
vector<int> relativeSortArray1(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> res;
    unordered_map<int, int> arrmp;
    for (auto const &ele : arr1)
    {
        arrmp[ele]++;
    }
    for (auto const &ele : arr2)
    {
        if (arrmp.find(ele) == arrmp.end())
        {
            continue;
        }
        else
        {
            while (arrmp[ele] > 0)
            {
                // cout << "Mp :" << ele << " " << arrmp[ele] << endl;
                res.push_back(ele);
                --arrmp[ele];
                if (arrmp[ele] == 0)
                    arrmp.erase(ele);
            }
        }
    }
    for (const auto &i : arr1)
    {
        while (arrmp[i])
        {
            res.push_back(i);
            --arrmp[i];
        }
    }
    for (const auto &i : arrmp)
    {
        cout << i.first << ":" << i.second << endl;
    }
    for (auto i : res)
    {
        cout << i << " ";
    }
    return res;
}
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    map<int, int> countStuff;
    // Using map because a map would store the elements in a sorted order and to search
    // an element it would take O(logn)

    for (auto i : arr1)
        countStuff[i]++;
    int correctPositionOfArray2Element = 0; // this will help us determine the correct position
    // for the arr2 element
    for (auto j : arr2)
    {
        while (countStuff[j]-- > 0)
            arr1[correctPositionOfArray2Element++] = j;
    }
    for (auto it : countStuff)
    {
        while (it.second-- > 0)
            arr1[correctPositionOfArray2Element++] = it.first;
    }
    return arr1;
}
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    // counting sort
    if (arr1.empty() || arr2.empty())
    {
        return arr1;
    }

    int max_element_val = *max_element(arr1.begin(), arr1.end());
    vector<int> countStuff(max_element_val + 1, 0);

    for (auto i : arr1)
    {
        countStuff[i]++;
    }

    int correctPositionOfArray2Element = 0;

    for (auto j : arr2)
    {
        while (countStuff[j]-- > 0)
        {
            arr1[correctPositionOfArray2Element++] = j;
        }
    }

    for (int i = 0; i <= max_element_val; ++i)
    {
        while (countStuff[i]-- > 0)
        {
            arr1[correctPositionOfArray2Element++] = i;
        }
    }

    return arr1;
}
int main()
{
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    relativeSortArray(arr1, arr2);
    return 0;
}