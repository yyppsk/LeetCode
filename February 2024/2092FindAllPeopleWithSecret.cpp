#include <bits/stdc++.h>
using namespace std;

class Solution_Better
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (vector<int> &meet : meetings)
        {
            int person1 = meet[0];
            int person2 = meet[1];
            int time = meet[2];

            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }

        vector<int> timeOfSecret(n, INT_MAX);

        // time when person got to know secret at time T
        queue<pair<int, int>> q;
        timeOfSecret[0] = 0;
        timeOfSecret[firstPerson] = 0;

        q.push({0, 0});
        q.push({firstPerson, 0});

        while (!q.empty())
        {
            auto [person, time] = q.front();
            q.pop();

            for (auto &neigh : adj[person])
            {
                int neighbour_person = neigh.first;
                int newMeetingTime = neigh.second;

                if (newMeetingTime >= time && timeOfSecret[neighbour_person] > newMeetingTime)
                {
                    timeOfSecret[neighbour_person] = newMeetingTime;
                    q.push({neighbour_person, newMeetingTime});
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (timeOfSecret[i] != INT_MAX)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

class Solution_Approach_DFS
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        map<int, vector<pair<int, int>>> timeMeetings;
        for (vector<int> &meeting : meetings)
        {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];

            timeMeetings[time].push_back({person1, person2});
        }
        vector<bool> knowsSecret(n, false);
        knowsSecret[0] = true;
        knowsSecret[firstPerson] = true;

        for (auto &it : timeMeetings)
        {
            int t = it.first;
            vector<pair<int, int>> meets = it.second;

            unordered_map<int, vector<int>> adj;
            // a - > {b,c,d}

            queue<int> q;
            unordered_set<int> alreadyAdded;

            for (auto &[person1, person2] : meets)
            {
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);

                if (knowsSecret[person1] == true && alreadyAdded.find(person1) == alreadyAdded.end())
                {
                    q.push(person1);
                    // start bfs from this
                    alreadyAdded.insert(person1);

                    // to secure not adding this person again
                }

                if (knowsSecret[person2] == true && alreadyAdded.find(person2) == alreadyAdded.end())
                {
                    q.push(person2);
                    // start bfs from this
                    alreadyAdded.insert(person2);

                    // to secure not adding this person again
                }
            }

            while (!q.empty())
            {
                int person = q.front();
                q.pop();
                for (auto &nextPerson : adj[person])
                {
                    if (knowsSecret[nextPerson] == false)
                    {
                        knowsSecret[nextPerson] = true;
                        q.push(nextPerson);
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (knowsSecret[i] == true)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

class ninteyPercentCases
{

    bool compareTime(const vector<int> &a, const vector<int> &b)
    {
        if (a[2] == b[2])
        {
            if (a[1] == b[1])
            {
                return a[0] < b[0]; // Sort by first element if second and third elements are equal
            }
            return a[1] < b[1]; // Sort by second element if third elements are equal
        }
        return a[2] < b[2]; // Otherwise, sort by third element
    }
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        unordered_set<int> IKnowSecret;
        IKnowSecret.insert(0);
        IKnowSecret.insert(firstPerson);

        sort(meetings.begin(), meetings.end(), compareTime);

        vector<int> result;
        result.push_back(0);
        result.push_back(firstPerson);
        for (int i = 0; i < meetings.size(); i++)
        {
            int x = meetings[i][0];
            int y = meetings[i][1];
            int time = meetings[i][2];

            if (IKnowSecret.find(x) != IKnowSecret.end())
            {
                // X knows it and X must share it to Y
                if (IKnowSecret.find(y) == IKnowSecret.end())
                {
                    IKnowSecret.insert(y);
                    result.push_back(y);
                }
            }
            if (IKnowSecret.find(y) != IKnowSecret.end())
            {
                // Y knows it and X must share it to X
                if (IKnowSecret.find(x) == IKnowSecret.end())
                {
                    IKnowSecret.insert(x);
                    result.push_back(x);
                }
            }
        }

        for (int num : result)
        {
            std::cout << num << " ";
        }
        return result;
    }
};
int main()
{
    return 0;
}