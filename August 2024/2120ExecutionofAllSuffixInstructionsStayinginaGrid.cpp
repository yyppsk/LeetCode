#include <bits/bits-stdc++.h>
using namespace std;
vector<int> executeInstructions(int n, vector<int> &startPos, string s)
{
    unordered_map<char, pair<int, int>> delta;

    delta['U'] = {-1, 0}; // Up
    delta['L'] = {0, -1}; // Left
    delta['R'] = {0, 1};  // Right
    delta['D'] = {1, 0};  // Down
    vector<int> result(s.length());
    for (int instruction = 0; instruction < s.length(); instruction++)
    {
        int x = startPos[0], y = startPos[1];
        int stepCount = 0;
        for (int pos = instruction; pos < s.length(); pos++)
        {
            x += delta[s[pos]].first;
            y += delta[s[pos]].second;
            cout << "When x = " << x << " and y = " << y << "\n";
            if (x >= 0 && y >= 0 && x < n && y < n)
            {
                cout << "Step is countd \n";
                stepCount += 1;
            }
            else
            {
                break;
            }
        }

        result[instruction] = stepCount;
    }

    return result;
}

int main()
{
    int n = 3;
    vector<int> start = {0, 1};
    string s = "RRDDLU";
    executeInstructions(n, start, s);

    return 0;
}