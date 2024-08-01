#include <bits/bits-stdc++.h>
using namespace std;

int countSeniors(vector<string> &details)
{
    int count = 0;
    for (int i = 0; i < details.size(); i++)
    {
        int age = ((details[i][11] - '0') * 10) + (details[i][12] - '0');
        if (age > 60)
            count++;
    }
    return count;
}

int main()
{
    return 0;
}