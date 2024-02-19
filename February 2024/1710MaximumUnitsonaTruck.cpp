#include <bits/stdc++.h>
using namespace std;

class SecondElementComparator
{
public:
    bool operator()(const vector<int> &a, const vector<int> &b) const
    {
        return a[1] > b[1];
    }
};
int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    sort(boxTypes.begin(), boxTypes.end(), SecondElementComparator());
    int idx = 0;
    int load = 0;
    int n = boxTypes.size();

    while (truckSize > 0 && idx < n)
    {
        if (truckSize - boxTypes[idx][0] >= 0)
        {
            truckSize -= boxTypes[idx][0];
            load += (boxTypes[idx][1] * boxTypes[idx][0]);
        }
        else if (truckSize > 0)
        {
            int availableUnits = boxTypes[idx][0];
            while (availableUnits >= 0 && truckSize > 0)
            {
                load += (boxTypes[idx][1]);
                truckSize--;
                availableUnits--;
            }
        }
        idx++;
    }
    return load;
}
int main()
{
    vector<vector<int>> boxTypes = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    int truckSize = 10;
    cout << "\n"
         << maximumUnits(boxTypes, truckSize);
    return 0;
}