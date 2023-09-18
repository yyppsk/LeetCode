#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    /*

    intution behind this algorithm is that I wanna make sure that, while I traverse the array I
    maintain some sort of summation, or certainly saying a prefix summation, why?
    suppose :
    An array :
    It has a sum S
    <-------S------>
    [0,1,2,3,4,5,6,7]
    <--S---><---0--->

    That is if a portion of array from [i--j] has sum S, and array from [i to K ] has sum S,
    then I can assure that summation from [k - j] has to be 0
    */
    long long prefixSum = 0;
    long long maximum = 0;
    unordered_map<long long, long long> sumTable;
    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];
        if (prefixSum == 0)
        {
            maximum = i + 1;
        }
        else
        {
            if (sumTable.find(prefixSum) != sumTable.end())
            {
                maximum = max(maximum, i - sumTable[prefixSum]);
            }
            else
            {
                sumTable[prefixSum] = i;
            }
        }
    }
    return maximum;
}
int main()
{
    return 0;
}