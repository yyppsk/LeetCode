#include <bits/bits-stdc++.h>
using namespace std;
int getXORSum(vector<int> &arr1, vector<int> &arr2)
{
    int xorA = 0, xorB = 0;

    for (int &ele : arr1)
    {
        xorA ^= ele;
    }
    for (int &ele : arr2)
    {
        xorB ^= ele;
    }

    // A ^ B ^ C ....& .. A ^ X ^ Y
    //  A & (B^C^X^Y)

    return xorA & xorB;
}
int main()
{
    return 0;
}