#include <bits/stdc++.h>
using namespace std;
int bagOfTokensScore(vector<int> tokens, int power)
{
    sort(tokens.begin(), tokens.end());
    int start = 0, end = tokens.size() - 1;

    int score = 0;
    while (start <= end)
    {
        if (tokens[start] <= power)
        {
            power -= tokens[start];
            score++;
            start++;
        }
        else if (tokens[end] > power)
        {
            if (start == end)
            {
                break;
            }

            if (score >= 1)
            {
                power += tokens[end];
                score--;
                end--;
            }
            break;
        }
    }

    return score;
}
int main()
{
    cout << bagOfTokensScore({100, 100, 100, 100}, 100);
    return 0;
}