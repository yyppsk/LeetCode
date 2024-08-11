#include <bits/bits-stdc++.h>
using namespace std;

int finalPositionOfSnake(int n, vector<string> &commands)
{
    int startX = 0, startY = 0;

    unordered_map<string, pair<int, int>> delta = {
        {"UP", {-1, 0}}, {"DOWN", {1, 0}}, {"RIGHT", {0, 1}}, {"LEFT", {0, -1}}};

    for (int i = 0; i < commands.size(); i++)
    {
        string direction = commands[i];
        startX += delta[direction].first;
        startY += delta[direction].second;
    }

    return (startX * n) + startY;
}

int main()
{
    return 0;
}