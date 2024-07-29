#include <bits/bits-stdc++.h>
using namespace std;
int numTeamsN2(vector<int> &rating)
{
    int pairs = 0;
    for (int i = 0; i < rating.size(); i++)
    {
        for (int j = i + 1; j < rating.size(); j++)
        {
            for (int k = j + 1; k < rating.size(); k++)
            {

                if ((rating[i] < rating[j] && rating[j] < rating[k]) || (rating[i] > rating[j] && rating[j] > rating[k]))
                {
                    pairs++;
                }
            }
        }
    }
    return pairs;
}

int numTeams(vector<int> &rating)
{
    int pairs = 0;

    for (int j = 1; j < rating.size() - 1; j++)
    {
        int countSmallerLeft = 0;
        int countLargerLeft = 0;
        int countSmallerRight = 0;
        int countLargerRight = 0;

        for (int i = 0; i < j; i++)
        {
            if (rating[i] < rating[j])
                countSmallerLeft++;
            else if (rating[i] > rating[j])
            {
                countLargerLeft++;
            }
        }

        for (int i = j + 1; i < rating.size(); i++)
        {
            if (rating[j] < rating[i])
                countLargerRight++;
            else if (rating[j] > rating[i])
            {
                countSmallerRight++;
            }
        }

        pairs += (countLargerLeft * countSmallerRight) + (countSmallerLeft * countLargerRight);
    }
    return pairs;
}
int main()
{
    vector<int> rating = {2, 5, 3, 4, 1};
    cout << numTeams(rating);
    return 0;
}