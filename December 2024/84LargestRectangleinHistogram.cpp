#include <bits/bits-stdc++.h>
using namespace std;

// BRUTE FORCE 92/99
int largestRectangleArea(vector<int> &heights)
{
    int max_possible = *max_element(heights.begin(), heights.end());
    int area = 0;

    for (int height = 0; height <= max_possible; height++)
    {
        int maxOccurFinal = 0;
        int maxOccur = 0;
        for (int j = 0; j < heights.size(); j++)
        {
            if (heights[j] >= height)
            {
                maxOccur += 1;
            }
            else
            {
                maxOccurFinal = max(maxOccur, maxOccurFinal);
                maxOccur = 0;
            }
        }
        maxOccurFinal = max(maxOccur, maxOccurFinal);
        area = max(maxOccurFinal * height, area);
    }

    return area;
}
int main()
{
    vector<int> heights = {1};
    largestRectangleArea(heights);
    return 0;
}