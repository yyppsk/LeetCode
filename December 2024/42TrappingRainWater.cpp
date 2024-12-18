#include <bits/bits-stdc++.h>
using namespace std;

int trap_brute(vector<int> &height)
{
    vector<int> leftMax(height.size());
    vector<int> rightMax(height.size());
    int res = 0;

    leftMax[0] = height[0];
    rightMax[height.size() - 1] = height[height.size() - 1];

    for (int i = 1; i < height.size(); i++)
    {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    for (int i = height.size() - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    for (int i = 0; i < height.size(); i++)
    {
        if (height[i] < leftMax[i] && height[i] < rightMax[i])
        {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
    }

    return res;
}

int trap(vector<int> &height)
{
    int res = 0;
    int left = 0, right = height.size() - 1;
    int lmax = 0, rmax = 0;
    while (left < right)
    {
        if (height[left] <= height[right])
        {
            if (lmax > height[left])
            {
                // ovbio left should be bigger, as I got the chance to store water as right
                // is bigger than current height[left]

                res += (lmax - height[left]);
            }
            else
            {
                // when left doesn't have a higher building
                lmax = height[left];
            }

            left += 1;
        }
        else
        {
            if (rmax > height[right])
            {
                res += (rmax - height[right]);
            }
            else
            {
                rmax = height[right];
            }

            right += 1;
        }
    }

    return res;
}
int main()
{
    return 0;
}