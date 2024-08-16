#include <bits/bits-stdc++.h>
using namespace std;

    int maxDistance(vector<vector<int>>& arrays) {
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 1; i < arrays.size(); i++) {
            if (arrays[i][0] < minVal) {
                minVal = arrays[i][0];
                minIndex = i;
            }
            if (arrays[i].back() > maxVal) {
                maxVal = arrays[i].back();
                maxIndex = i;
            }
        }

        int secondMinVal = INT_MAX;
        int secondMaxVal = INT_MIN;
        for (int i = 0; i < arrays.size(); i++) {
            if (i != minIndex) {
                secondMaxVal = max(secondMaxVal, arrays[i].back());
            }
            if (i != maxIndex) {
                secondMinVal = min(secondMinVal, arrays[i][0]);
            }
        }

        int result =
            max(abs(maxVal - secondMinVal), abs(secondMaxVal - minVal));

        return result;
    }
int main()
{
    vector<vector<int>> arr = {{1, 4}, {0, 5}};
    cout << maxDistance(arr);
    return 0;
}