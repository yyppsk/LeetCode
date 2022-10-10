#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
int numRescueBoats(vector<int> &people, int limit)
{
    // trying to find possible pairs
    int front = 0, end = people.size() - 1;
    int count = 0;
    sort(people.begin(), people.end());
    while (front <= end)
    {
        if ((people[front] + people[end]) <= limit)
        {
            front++;
            end--;
            count++;
        }
        else
        {
            end--;
            count++;
        }
    }
    return count;
}
int numRescueBoats2(vector<int> &people, int limit)
{
    int boat = 0;
    unordered_map<int, int> map;
    for (auto i : people)
    {
        map[i]++;
    }
    for (auto i : people)
    {
        for (auto i : map)
        {
            cout << i.first << ":" << i.second << endl;
        }
        if (map.find(limit - i) != map.end() && (map.at(limit - i) != 0))
        {
            --map[limit - i];
            boat++;
        }
    }
    return boat;
}
int main()
{
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;
    cout << numRescueBoats2(people, limit);
    return 0;
}