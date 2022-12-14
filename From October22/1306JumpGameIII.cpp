#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
bool canReach(vector<int> &arr, int start)
{
    queue<int> qu;
    qu.push(start);
    int i;
    while (!qu.empty())
    {
        i = qu.front();
        // cout << "i: " << i << endl;
        qu.pop();
        if (arr[i] == 0)
        {
            return true;
        }
        if (arr[i] + 1 < 0) // if visited
        {
            continue;
        }
        if (i - arr[i] >= 0)
        {
            qu.push(i - arr[i]);
        }
        if (i + arr[i] < arr.size())
        {
            qu.push(i + arr[i]);
        }
        arr[i] = arr[i] * -1;
    }
    return false;
}
int main()
{
    vector<int> arr = {1};
    int k = 5;
    cout << arr.size();
    // cout << canReach(arr, k);
    return 0;
}