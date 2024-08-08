#include <bits/bits-stdc++.h>
using namespace std;
int minimumChairs(string s)
{
    int people = 0;
    int chairs = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'E')
        {
            people++;
            chairs = max(people, chairs);
        }
        else if (s[i] == 'L')
        {

            people--;
            chairs = max(people, chairs);
        }
    }
    return chairs;
}

int main()
{
    return 0;
}