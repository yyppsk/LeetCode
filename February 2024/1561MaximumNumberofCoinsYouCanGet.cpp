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
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int mycoins = 0;

        for (int i = n / 3; i < n; i += 2)
        {
            mycoins += piles[i];
        }
        return mycoins;
    }
};
int main()
{
    return 0;
}