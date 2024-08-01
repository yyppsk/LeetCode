#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int numberOfCuts(int n)
    {
        if (n == 1)
            return 0;
        int store = n;
        if ((n & 1) == 0)
        {
            return store / 2;
        }
        return store;
    }
};
int main()
{
    return 0;
}