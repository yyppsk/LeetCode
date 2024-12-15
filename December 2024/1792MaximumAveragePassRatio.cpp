#include <bits/bits-stdc++.h>
using namespace std;
double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
{
    int size = classes.size();
    vector<double> ratios(size);

    for (int i = 0; i < size; i++)
    {
        ratios[i] = (double)classes[i][0] / (double)classes[i][1];
    }

    while (extraStudents--)
    {
        vector<double> betterRatios(size);

        for (int i = 0; i < size; i++)
        {
            betterRatios[i] = ((double)classes[i][0] + 1) / ((double)classes[i][1] + 1);
        }

        double bestChange = 0.0;
        int idx = 0;

        for (int i = 0; i < size; i++)
        {
            double change = (double)betterRatios[i] - (double)ratios[i];
            if (bestChange < change)
            {
                bestChange = change;
                idx = i;
            }
        }

        ratios[idx] = betterRatios[idx];
        classes[idx][0] += 1;
        classes[idx][1] += 1;
    }

    double answer = 0.0;
    for (int i = 0; i < size; i++)
    {
        answer += ratios[i];
    }

    return answer / size;
}
int main()
{
    return 0;
}