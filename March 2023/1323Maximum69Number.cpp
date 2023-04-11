#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
int maximum69Number(int num)
{
    int n2 = num;
    int counter = 0;
    int rem = 0;
    int forever = num;
    int curr = INT_MIN;
    while (n2)
    {

        rem = n2 % 10;
        n2 /= 10;
        if (rem == 9)
        {
            if (counter == 0)
                forever = forever - 3;
            else
                forever -= (pow(10, counter) * 3);
        }
        else
        {
            if (counter == 0)
                forever = forever + 3;
            else
                forever += (pow(10, counter) * 3);
        }
        counter++;
        curr = max(forever, num);
        cout << forever << endl;
        forever = num;
    }
    return curr;
}
int main()
{
    int num = 9969;
    // 99,999,9
    cout << maximum69Number(num);
    return 0;
}