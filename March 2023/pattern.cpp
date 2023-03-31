#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
int main()
{
    long n = 29;
    long rem;
    long q = 0;
    printf("Div/Divi = Q : Remain\n");
    while (n > 0)
    {
        rem = n % 3;
        q = n / 3;
        printf("%d/3 =  %d   :   %d\n", n, q, rem);

        n = n / 3;
    }
    cout << log10(27) << " " << log10(3) << " : " << (log10(27) / log10(3)) / 1 << endl;
    return 0;
}