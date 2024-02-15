#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=J5IIH35EBVE
int sumOddLengthSubarrays(vector<int> arr)
{
    int n = arr.size();
    int totalAppearanceOfCurrentElement;
    int appearanceInOdd;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        totalAppearanceOfCurrentElement = (n - i) * (i + 1);
        if (totalAppearanceOfCurrentElement % 2 == 0)
            appearanceInOdd = totalAppearanceOfCurrentElement / 2;
        else
            appearanceInOdd = (totalAppearanceOfCurrentElement / 2) + 1;
        sum += (appearanceInOdd * arr[i]);
    }
    return sum;
}
int main()
{
    cout << sumOddLengthSubarrays({1, 4, 2, 5, 3});
    return 0;
}