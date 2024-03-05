#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> intervalIntersection(vector<vector<int>> firstList, vector<vector<int>> secondList)
{
    vector<vector<int>> result;

    int first = 0, second = 0;

    while (first < firstList.size() && second < secondList.size())
    {
        int FirstStart = firstList[first][0], FirstEnd = firstList[first][1];
        int SecondStart = secondList[second][0], SecondEnd = secondList[second][1];

        cout << "First Start = " << FirstStart << " : FirstEnd = " << FirstEnd << "\n";
        cout << "Second Start = " << SecondStart << " : SecondEnd = " << SecondEnd << "\n";

        if ((FirstStart <= SecondEnd) && (FirstEnd >= SecondStart))
        {
            result.push_back({max(FirstStart, SecondStart),
                              min(FirstEnd, SecondEnd)});
            cout << "Pushed " << max(FirstStart, SecondStart) << ":" << min(FirstEnd, SecondEnd) << "\n";
        }
        if (SecondEnd > FirstEnd)
        {
            first++;
        }
        else
        {
            second++;
        }
    }

    return result;
}
int main()
{
    intervalIntersection({{0, 2}, {5, 10}, {13, 23}, {24, 25}}, {{1, 5}, {8, 12}, {15, 24}, {25, 26}});
    return 0;
}