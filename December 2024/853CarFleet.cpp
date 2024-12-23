#include <bits/bits-stdc++.h>
using namespace std;
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    int n = position.size();
    vector<pair<int, double>> carPosTime;

    for (int i = 0; i < n; i++)
    {
        carPosTime.emplace_back(position[i],
                                (double)(target - position[i]) / speed[i]);
    }

    sort(carPosTime.begin(), carPosTime.end(),
         [](const pair<int, double> &a, const pair<int, double> &b)
         {
             return a.first > b.first;
         });

    int totalFleet = 0;
    double previousTime = 0;

    for (auto &car : carPosTime)
    {
        if (car.second > previousTime)
        {
            totalFleet++;
            previousTime = car.second;
        }
    }

    return totalFleet;
}
int main()
{
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3}, speed = {2, 4, 1, 1, 3};
    carFleet(target, position, speed);
    return 0;
}