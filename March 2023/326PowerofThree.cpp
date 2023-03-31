#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isPowerOfThree(int n)
{
    int rem = 0;
    int q = 0;
    while (n > 0)
    {
        rem = n % 3;
        n = n / 3;
        if (n == 1)
            if (rem == 0)
                return 1;
    }
    return 1;
}
int main()
{ // 45 -> 15 -> 5 -> 2
    // 27 9 0
    cout << isPowerOfThree(26);
    cout << endl;
    cout << isPowerOfThree(27);
    cout << endl;
    cout << isPowerOfThree(28);
    cout << endl;
    cout << isPowerOfThree(29);
    return 0;
}