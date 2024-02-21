#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int setUncommonPositions = x ^ y;
        int count = 0;
        while (setUncommonPositions > 0)
        {
            setUncommonPositions = setUncommonPositions & (setUncommonPositions - 1);
            count++;
        }
        return count;
    }
};
int main()
{
    return 0;
}