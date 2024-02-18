#include <bits/stdc++.h>
using namespace std;

int mostBooked(int n, vector<vector<int>> &meetings)
{
    sort(meetings.begin(), meetings.end());

    // time count
    vector<pair<long long, int>> endTimeOfRoom(n, {0, 0});

    for (vector<int> &meet : meetings)
    {
        int start = meet[0];
        int end = meet[1];
        bool found = false;

        long long EarlyEndRoomTime = LLONG_MAX;
        int EarlyEndRoom = 0;

        // Find the first available meeting room
        for (int currentRoom = 0; currentRoom < n; currentRoom++)
        {
            if (endTimeOfRoom[currentRoom].first <= start)
            {
                found = true;
                endTimeOfRoom[currentRoom].first = end;
                endTimeOfRoom[currentRoom].second++;
                break;
            }

            if (endTimeOfRoom[currentRoom].first < EarlyEndRoomTime)
            {
                EarlyEndRoom = currentRoom;
                EarlyEndRoomTime = endTimeOfRoom[currentRoom].first;
            }
        }

        if (!found)
        {
            endTimeOfRoom[EarlyEndRoom].first += (end - start);
            endTimeOfRoom[EarlyEndRoom].second++;
        }
    }

    int resultRoom = -1;
    int maxUse = 0;
    for (int room = 0; room < n; room++)
    {
        if (endTimeOfRoom[room].second > maxUse)
        {
            maxUse = endTimeOfRoom[room].second;
            resultRoom = room;
        }
    }

    return resultRoom;
}
int main()
{
    return 0;
}