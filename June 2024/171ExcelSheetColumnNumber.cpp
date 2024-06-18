#include <bits/bits-stdc++.h>
using namespace std;
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int sum = 0;
        for (int i = 0; i < columnTitle.length(); i++)
            sum = sum * 26 + (columnTitle[i] - 'A' + 1);
        return sum;
    }
};
int main()
{
    return 0;
}