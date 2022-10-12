#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
double findMaxAverageSol1(vector<int> &nums, int k) // O(nk)
{
    int n = nums.size();
    double maxa = INT_MIN;
    for (int i = 0; i <= n - k; i++)
    {
        double sum = 0;
        // cout << "Sum of : ";
        for (int j = i; j < i + k; j++)
        {
            // printf("%d +", nums[j]);
            sum += nums[j];
        }
        sum /= k;
        maxa = max(maxa, sum);
        // printf("is %f\n", sum / 4);
    }
    return maxa;
}
int main()
{
    vector<int> arr = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << findMaxAverage(arr, k);
    return 0;
}