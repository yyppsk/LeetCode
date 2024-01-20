#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
using namespace std;
int sumSubarrayMins2(vector<int> &arr)
{
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int minimum = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                minimum = min(minimum, arr[k]);
                cout
                    << arr[k] << " ";
            }
            cout << endl;
            cout << "Minimum for Previous Sub Array " << minimum << endl;
            result += minimum;
        }
    }
    return result;
}
class Solution
{
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int> &arr)
    {
        vector<int> leftSmaller = getLeft(arr);
        vector<int> rightSmaller = getRight(arr);
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            long long left;
            long long right;
            left = i - leftSmaller[i];
            right = rightSmaller[i] - i;

            long long totalSubArrays = left * right;
            long long totalSum = totalSubArrays * arr[i];
            sum = (sum + totalSum) % mod;
        }

        return sum;
    }

private:
    vector<int> getLeft(vector<int> &arr)
    {
        stack<int> st;
        vector<int> left(arr.size());

        for (int i = 0; i < arr.size(); i++)
        {
            if (st.empty())
            {
                left[i] = -1;
            }
            else
            {
                while (!st.empty() && arr[i] < arr[st.top()])
                {
                    st.pop();
                }
                left[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return left;
    }
    vector<int> getRight(vector<int> &arr)
    {
        stack<int> st;
        vector<int> right(arr.size());

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                right[i] = arr.size();
            }
            else
            {
                while (!st.empty() && arr[i] <= arr[st.top()])
                {
                    st.pop();
                }
                right[i] = st.empty() ? arr.size() : st.top();
            }
            st.push(i);
        }
        return right;
    }
};
int main()
{
    Solution obj;
    vector<int> arr = {11, 81, 94, 43, 3};
    cout << "\n"
         << obj.sumSubarrayMins(arr);
    return 0;
}