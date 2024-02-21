#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        while (right > left)
        {
            right = right & (right - 1);
        }
        return right;
    }

    int rangeBitwiseAnd2(int left, int right)
    {
        int shifts = 0;
        while (right != left)
        {
            right = right >> 1;
            left = left >> 1;
            shifts++;
        }
        return right << shifts;
    }
};
int main()
{
    return 0;
}