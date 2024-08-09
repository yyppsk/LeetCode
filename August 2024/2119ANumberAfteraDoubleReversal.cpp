#include <bits/bits-stdc++.h>
using namespace std;
bool isSameAfterReversals(int num)
{
    string number = to_string(num);
    reverse(number.begin(), number.end());
    int numberReversedOnce = stoi(number);
    string number2 = to_string(numberReversedOnce);
    reverse(number2.begin(), number2.end());

    int numberReversedTwice = stoi(number2);

    if (numberReversedTwice == num)
        return true;
    return false;
}
int main()
{
    return 0;
}