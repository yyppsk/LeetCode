#include <iostream>
#include <vector>
using namespace std;
vector<int> sortArrayByParity(vector<int> &nums)
{
    for (int i = 0, j = 0; j < nums.size(); j++)
    {
        if (nums[j] % 2 == 0)
            swap(nums[i++], nums[j]);
        for (auto i : nums)
            cout << i << " ";
        cout << endl;
    }
    return nums;
    /*
    int size = nums.size();
    cout << size << endl;
    vector<int> arr(nums.size(), 1);
    int j = nums.size() - 1;
    int k = 0;
    for (auto i : nums)
    {
        if (i % 2 == 0)
        {
            arr[k] = i;
            k++;
        }
        else if (i % 2 != 0)
        {
            arr[j] = i;
            j--;
        }
    }
    for (auto i : arr)
        printf("%d ", i);

    return arr;
    */
}
int main()
{
    vector<int> n = {3, 81, 23, 65, 7, 2};
    sortArrayByParity(n);
    return 0;
}