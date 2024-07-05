#include <bits/bits-stdc++.h>
using namespace std;

int minDifference(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    // 3 20 100
}
int main()
{

    vector<int> A = {5, 3, 2, 4};
    vector<int> B = {1, 5, 0, 10, 14};
    vector<int> C = {3, 100, 20};

    cout << minDifference(A) << "\n";
    cout << minDifference(B) << "\n";
    cout << minDifference(C) << "\n";
    return 0;
}