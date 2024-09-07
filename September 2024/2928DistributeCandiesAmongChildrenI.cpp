#include <bits/bits-stdc++.h>
using namespace std;
int distributeCandies(int n, int limit)
{
    int way = 0;
    for (int i = 0; i <= limit; i++)
    {
        for (int j = 0; j <= limit; j++)
        {
            for (int k = 0; k <= limit; k++)
            {
                if (i + j + k == n)
                {
                    way++;
                }
            }
        }
    }

    return way;
}
int main()
{
    return 0;
}