#include <bits/bits-stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;
        for (int i = 1; i < rowIndex + 1; i++)
            for (int j = i; j >= 1; j--)
                row[j] += row[j - 1];
        return row;
    }
};
int main()
{
    return 0;
}