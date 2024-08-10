#include <bits/bits-stdc++.h>
using namespace std;
class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int totalStepsGoingBackForth = 0, can = capacity;
        for (int i = 0; i < plants.size(); ++i)
        {
            if (can < plants[i])
            {
                totalStepsGoingBackForth += i * 2;
                can = capacity;
            }
            can -= plants[i];
        }
        return totalStepsGoingBackForth + plants.size();
    }
};
int main()
{
    return 0;
}