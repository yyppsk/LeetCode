#include <bits/bits-stdc++.h>
using namespace std;
int countCompleteDayPairs(vector<int> &hours)
{
    int complete = 0;

    for (int i = 0; i < hours.size(); i++)
    {
        for (int j = i + 1; j < hours.size(); j++)
        {
            if ((hours[i] + hours[j]) % 24 == 0)
                complete++;
        }
    }
    return complete;
}

int main()
{
    return 0;
}