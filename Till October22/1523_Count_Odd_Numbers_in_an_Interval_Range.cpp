#include <iostream>
using namespace std;
/*
Approach: Total numbers in the range will be (R – L + 1) i.e. N.


If N is even then the count of both odd and even numbers will be N/2.
If N is odd,
If L or R is odd, then the count of odd number will be N/2 + 1 and even numbers = N – countofOdd.
Else, count of odd numbers will be N/2 and even numbers = N – countofOdd.
Below is the implementation of the above approach:
*/
int countOdds(int low, int high)
{
    int N = high - low + 1;
    if (N % 2 == 0)
    {
        return N / 2;
    }
    else if (low % 2 != 0 || high % 2 != 0)
    {
        return N / 2 + 1;
    }
    else
        return N / 2;
}
int main()
{
    cout << countOdds(3, 7);
    return 0;
}