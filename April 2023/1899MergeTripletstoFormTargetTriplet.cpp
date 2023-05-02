#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
{
}
int main()
{
    vector<vector<int>> triplets = {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}};

    vector<int> target = {2, 7, 5};
    cout << mergeTriplets(triplets, target);
    return 0;
}