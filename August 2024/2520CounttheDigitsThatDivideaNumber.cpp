#include <bits/bits-stdc++.h>
using namespace std;
int countDigits(int num)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int copy = num;

    int cnt = 0;
    while (copy > 0)
    {
        int digit = copy % 10;
        copy /= 10;
        if ((num % digit) == 0)
            cnt++;
    }
    return cnt;
}
int main()
{
    cout << countDigits(1248);
    return 0;
}