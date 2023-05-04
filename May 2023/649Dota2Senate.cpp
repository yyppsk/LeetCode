#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
string predictPartyVictory(string senate)
{
    /*Naive approach 72/80
    int r = 0, d = 0;
    for (auto i : senate)
    {
        if (i == 'R')
            r++;
        else
            d++;
    }
    if (r > d)
        return "Radiant";
    else if (r < d)
        return "Dire";
    else if (r == d)
        if (senate[0] == 'R')
            return "Radiant";
        else
            return "Dire";
    return "";
    */
    // Queue Approach
    deque<int> qd, qr;
    int n = senate.size();
    int index = 0;
    for (auto ch : senate)
    {
        if (ch == 'R')
        {
            qr.push_back(index);
        }
        else
        {
            qd.push_back(index);
        }
        ++index;
    }
    while (!qd.empty() && !qr.empty())
    {
        int didx, ridx;
        didx = qd.front();
        ridx = qr.front();
        if (didx < ridx)
        {
            qd.pop_front();
            qr.pop_front();
            qd.push_back(didx + n);
        }
        else
        {
            qr.pop_front();
            qd.pop_front();
            qr.push_back(ridx + n);
        }
    }
    if (qd.size() > qr.size())
    {
        return "Dire";
    }
    else
    {
        return "Radiant";
    }

    return "";
}
int main()
{
    cout << predictPartyVictory("RD");
    return 0;
}