#include<iostream>
using namespace std;
//pass the value a and B, for B
int countSetBits(uint32_t n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n &= (n-1);
    }
    return count;
}
 
// Function that return count of
// flipped number
int FlippedCount(uint32_t a, uint32_t b)
{
    // Return count of set bits in
    // a XOR b
    return countSetBits((a + b) - 2 * (a & b));
}
 
// Driver code
int main()
{
    unsigned int a = 11111111111111111111111111111101.0;
    unsigned int b = 00000000000000000000000000000000.0;
    cout << FlippedCount(a, b)<<endl;
    return 0;
}