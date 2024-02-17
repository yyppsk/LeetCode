#include <bits/stdc++.h>
using namespace std;

// 67 TEST CASES GREEDY
int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    priority_queue<int> gaps;
    int i = 0;
    while (i < heights.size() - 1)
    {
        if (gaps.empty())
        {
            gaps.push(heights[i + 1] - heights[i]);
            cout << "Pushed " << gaps.top() << "\n";
            if (gaps.top() > 0 && ladders > 0)
            {
                ladders--;
                // use ladder
                cout << "Using ladders : Remaining " << ladders << "\n";
            }
        }
        else
        {
            int currentGap = (heights[i + 1] - heights[i]);
            if (currentGap <= 0)
            {
                cout << "Comparing " << (currentGap) << " with " << 0
                     << "\n";
                cout << "Skipping Negative Gap\n";
                cout << "Ladder : " << ladders << " Bricks : " << bricks << "\n";
                gaps.push(currentGap);
            }
            else if (currentGap < gaps.top() && bricks >= (currentGap))
            {
                cout << "Comparing " << (currentGap) << " with " << gaps.top()
                     << "\n";
                bricks -= currentGap;
                cout << "Using Bricks : Remaining " << bricks << "\n";
                gaps.push(currentGap);
            }
            else if (currentGap >= gaps.top() && ladders > 0)
            {
                cout << "Comparing " << (currentGap) << " with " << gaps.top()
                     << "\n";
                ladders--;

                cout << "Using ladders : Remaining " << ladders << "\n";
                gaps.push(currentGap);
            }
            else if (currentGap >= gaps.top() && bricks >= currentGap)
            {
                cout << "Comparing " << (currentGap) << " with " << gaps.top()
                     << "\n";
                bricks -= currentGap;
                cout << "Using Bricks : Remaining " << bricks << "\n";
                gaps.push(currentGap);
            }
            else
            {
                cout << "Comparing " << (currentGap) << " with " << gaps.top()
                     << "\n";
                return i;
            }
        }

        i++;
    }
    return i;
}

// Main Solution
class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int> pastBricksUsed;
        int i = 0;
        for (; i < n - 1; i++)
        {
            if (heights[i + 1] <= heights[i])
            {
                continue;
            }
            int gap = heights[i + 1] - heights[i];
            if (bricks >= gap)
            {
                bricks -= gap;
                pastBricksUsed.push(gap);
            }
            else if (ladders > 0)
            {

                if (!pastBricksUsed.empty())
                {

                    int maxPastBrickUsed = pastBricksUsed.top();
                    if (maxPastBrickUsed > gap)
                    {
                        bricks += maxPastBrickUsed;
                        pastBricksUsed.pop();
                        bricks -= gap;
                        pastBricksUsed.push(gap);
                    }
                }
                ladders--;
            }
            else
            {
                break;
            }
        }
        return i;
    }
};
int main()
{
    vector<int> heights = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    int bricks = 10, ladders = 2;
    cout << "\n\n A1: "
         << furthestBuilding(heights, bricks, ladders);
    heights = {4, 2, 7, 6, 9, 14, 12};
    bricks = 5, ladders = 1;
    cout << "\n\n A2: "
         << furthestBuilding(heights, bricks, ladders);
    heights = {14, 3, 19, 3};
    bricks = 17, ladders = 0;
    cout << "\n\n A3: "
         << furthestBuilding(heights, bricks, ladders);
    heights = {1, 2};
    bricks = 0, ladders = 0;
    cout << "\n\n A4: "
         << furthestBuilding(heights, bricks, ladders);

    heights = {7, 5, 13};
    bricks = 0;
    ladders = 0;
    cout << "\n\n A5: "
         << furthestBuilding(heights, bricks, ladders);
    return 0;
}