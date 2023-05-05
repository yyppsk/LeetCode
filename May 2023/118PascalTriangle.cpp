#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> generate(int numRows)
{
    if (numRows == 1)
        return {{1}};
    if (numRows == 2)
        return {{1}, {1, 1}};
    vector<vector<int>> base = {{1}, {1, 1}};
    for (int i = 1; i <= numRows - 2; i++)
    {
        vector<int> nayawala = {1};
        int start = 0, end = 1;
        while (end < base.size())
        {
            nayawala.push_back(base[i][start] + base[i][end]);
            ++start, ++end;
        }
        nayawala.push_back(1);
        base.push_back(nayawala);
    }
    return base;
}
int main()
{
    generate(6);
    return 0;
}