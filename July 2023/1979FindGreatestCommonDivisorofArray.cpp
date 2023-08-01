#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int gcd(int smallest, int largest)
{
    int element = largest;
    while (element)
    {
        if ((smallest % element == 0) && (largest % element == 0))
        {
            return element;
        }
        element--;
    }
    return 0;
}
int findGCD(vector<int> &nums)
{
    // Hit and Trial
    int smallest = INT_MAX, largest = INT_MIN;
    for (const auto &ele : nums)
    {
        if (ele > largest)
            largest = ele;
        if (ele < smallest)
            smallest = ele;
    }
    return gcd(smallest, largest);
}
int main()
{
    return 0;
}