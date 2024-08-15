#include <bits/bits-stdc++.h>
using namespace std;
int findDelayedArrivalTime(int arrivalTime, int delayedTime)
{
    int time = 0;
    time += arrivalTime;
    time += delayedTime;
    time = (time % 24);

    return time;
}
int main()
{
    return 0;
}