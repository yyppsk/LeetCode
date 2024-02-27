#include <bits/stdc++.h>
using namespace std;

class BruteForce
{
    // 61 TEST Cases

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        unordered_set<int> visited;
        visited.insert(0);
        unordered_set<int> keys;
        keys.insert(0);
        vector<pair<int, vector<int>>> standBy;
        for (int room = 0; room < rooms.size(); room++)
        {

            if (keys.find(room) != keys.end())
            {
                // visiting a room

                visited.insert(room);
                for (int j = 0; j < rooms[room].size(); j++)
                {
                    // picking all keys
                    keys.insert(rooms[room][j]);
                }
            }
            else
            {
                cout << room << " Room nahi hai \n";
                standBy.push_back({room, rooms[room]});
            }
        }

        for (const auto &pair : standBy)
        {
            cout << "Room: " << pair.first << ", Elements in the second vector: ";
            for (int element : pair.second)
            {
                cout << element << " ";
            }
            cout << endl;
        }
        cout << "\n";

        for (auto ele : keys)
        {
            cout << ele << " ";
        }
        cout << "\n";
        for (int i = 0; i < standBy.size(); i++)
        {
            if (keys.find(standBy[i].first) != keys.end())
            {
                visited.insert(standBy[i].first);
                for (int j = 0; j < standBy[i].second.size(); j++)
                {
                    keys.insert(standBy[i].second[j]);
                }
            }
        }

        for (auto ele : visited)
        {
            cout << ele << " ";
        }
        cout << "\n";
        if (visited.size() == rooms.size())
            return true;
        return false;
    }
};

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    vector<int> adj[n];

    for (int room = 0; room < rooms.size(); room++)
    {
        for (int key = 0; key < rooms[room].size(); key++)
        {
            adj[room].push_back(rooms[room][key]);
        }
    }

    queue<int> q;
    unordered_set<int> vis;

    q.push(0);

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        vis.insert(currentNode);

        for (auto &neigh : adj[currentNode])
        {
            if (vis.find(neigh) == vis.end())
            {
                vis.insert(neigh);
                q.push(neigh);
            }
        }
    }

    // for (int room = 0; room < rooms.size(); room++)
    // {
    //     cout << room << " : ";
    //     for (int key = 0; key < rooms[room].size(); key++)
    //     {
    //         cout << adj[room][key] << " ";
    //     }
    //     cout << "\n";
    // }
    for (auto &ele : vis)
    {
        cout << ele << " ";
    }
    cout << "\n";
    if (vis.size() == rooms.size())
        return true;
    return false;
}
int main()
{
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    cout << canVisitAllRooms(rooms);

    rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};

    return 0;
}