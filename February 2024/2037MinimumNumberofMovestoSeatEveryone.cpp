#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int moves = 0;

        for (int i = 0; i < seats.size(); i++)
        {
            moves += abs(seats[i] - students[i]);
        }
        return moves;
    }
};
int main()
{
    return 0;
}