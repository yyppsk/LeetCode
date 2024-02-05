#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
int garbageCollection(vector<string> garbage, vector<int> travel)
{
    int Pindex = 0, Mindex = 0, Gindex = 0;
    int totalTime = 0;

    for (int i = 0; i < garbage.size(); i++)
    {
        for (int j = 0; j < garbage[i].size(); j++)
        {
            if (garbage[i][j] == 'P')
            {
                Pindex = i;
            }
            else if (garbage[i][j] == 'G')
            {
                Gindex = i;
            }
            else
            {
                Mindex = i;
            }
            totalTime++;
        }
    }
    for (int i = 1; i < travel.size(); i++)
    {
        travel[i] += travel[i - 1];
    }
    totalTime += Pindex > 0 ? travel[Pindex - 1] : 0;
    totalTime += Gindex > 0 ? travel[Gindex - 1] : 0;
    totalTime += Mindex > 0 ? travel[Mindex - 1] : 0;

    return totalTime;
}

int main()
{ // 6,10
    cout << "Res\n";
    cout << garbageCollection({"MMM", "PGM", "GP"}, {3, 10}) << endl;
    cout << garbageCollection({"G", "P", "GP", "GG"}, {2, 4, 3});
    return 0;
}