#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
5 int main()
{
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;
    cout << numRescueBoats(people, limit);
    return 0;
}