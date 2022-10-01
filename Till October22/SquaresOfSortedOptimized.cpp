#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> sortedSquares(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;
    int n = nums.size();
    int i = 1;
    cout << "\nNums size : " << nums.size();
    cout << "\nl : " << 0;
    cout << "\nr : " << nums.size() - 1;
    cout << "\nn : " << nums.size();

    vector<int> res(n);
    if (nums.size() == 0)
        return {};
    while (n--)
    {
        cout << "\nLoop Number : " << i;
        cout << "\nNums size : " << nums.size();
        cout << "\nl : " << l;
        cout << "\nr : " << r;
        cout << "\nn : " << n;
        if (abs(nums[l]) < abs(nums[r]))
        {
            printf("\nabs(nums[%d]): %d < abs(nums[%d]): %d", l, nums[l], r, nums[r]);
            res[n] = nums[r] * nums[r];
            printf("\nres[n]:res[%d] = %d", n, res[n]);
            r--;
            cout << "\nr = " << r;
        }
        else
        {
            res[n] = nums[l] * nums[l];
            printf("\nres[n]:res[%d] = %d", n, res[n]);
            l++;
            cout << "\nl = " << l;
        }
        i++;
    }
    cout << endl;
    for (auto it = res.begin(); it != res.end(); ++it)
    {
        cout << *it << " ";
    }
}
int main()
{
    vector<int> abc = {-4, -1, 0, 3, 10};
    (sortedSquares(abc));
    return 0;
}