#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> result(n + 1);
        result[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 != 0)
            {
                result[i] = result[i / 2] + 1;
            }
            else
                result[i] = result[i / 2];
        }
        return result;
    }
};
int main()
{
    return 0;
}