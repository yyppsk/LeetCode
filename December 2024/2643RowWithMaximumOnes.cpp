#include <bits/bits-stdc++.h>
using namespace std;
vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    int count = 0, row = 0;

    for (int i = 0; i < mat.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j])
                cnt += 1;
        }
        if (cnt > count)
        {
            count = cnt;
            row = i;
        }
    }

    return {count, row};
}
int main()
{
    return 0;
}