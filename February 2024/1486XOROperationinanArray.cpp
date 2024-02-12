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
    int xorOperation(int n, int start)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int current = start + 2 * i;
            res ^= current;
        }
        return res;
    }
};
int main()
{
    return 0;
}