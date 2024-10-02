#include <bits/bits-stdc++.h>
using namespace std;
vector<int> arrayRankTransform(vector<int> &arr)
{
    vector<int> A(arr);
    sort(A.begin(), A.end());
    unordered_map<int, int> rank;
    for (int &a : A)
        rank.emplace(a, rank.size() + 1);
    for (int i = 0; i < A.size(); ++i)
        A[i] = rank[arr[i]];
    return A;
}
int main()
{
    vector<int> arr = {40, 10, 20, 30};
    arrayRankTransform(arr);
    return 0;
}