#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
double findMaxAverageSol2(vector<int> &nums, int k) // O(nk)
{
    int n = nums.size();
    double maxa = 0;
    double sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    // cout << "Sum " << sum << endl;
    double window = sum;
    maxa = window;
    if (k == nums.size())
        return maxa;
    for (int i = 1; k + i <= nums.size(); i++)
    {
        printf("Minus : Window %f - %d\n", window, nums[i - 1]);
        window = window - nums[i - 1];
        printf("Add : Window %f + %d\n", window, nums[i + k - 1]);
        window = window + nums[i + k - 1];
        cout << window << endl;
        printf("New window Sum in interval(%d,%d) : %f\n", i - 1, k + i, window);
        maxa = max(window, maxa);
        cout << "Maxa " << maxa << endl;
    }
    
    return maxa / k;
}
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
    vector<int> arr = {9, 7, 3, 5, 6, 2, 0, 8, 1, 9};
    int k = 6;
    cout << findMaxAverageSol2(arr, k);
    return 0;
}