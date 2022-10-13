#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> solve(vector<vector<int>> &nums, int rows)
{
}
void solve(int rows)
{
    if (--rows)
        return;
    
}
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> nums = {{1}, {1, 1}};
    solve(nums, numRows);
}
int main()
{
    // generate(5);
    solve(5);
    return 0;
}