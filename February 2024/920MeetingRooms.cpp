#include <bits/stdc++.h>
using namespace std;

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};
// Comparator Class to compare 2 objects
class compare
{
public:
    // Comparator function
    bool operator()(const Interval &a, const Interval &b)
    {
        // Compare on basis of start time
        return a.start < b.start;
    }
};

bool overlap(Interval interval1, Interval interval2)
{
    return interval2.start < interval1.end;
}
bool canAttendMeetings(vector<Interval> intervals)
{
    if (intervals.size() == 0)
        return true;
    compare cmp;
    sort(intervals.begin(), intervals.end(), cmp);

    for (int i = 0; i < intervals.size() - 1; i++)
    {
        if (overlap(intervals[i], intervals[i + 1]))
            return false;
    }
    return true;
}
int main()
{

    cout << canAttendMeetings({{5, 8}, {6, 8}});
    return 0;
}