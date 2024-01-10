#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    int alternateDigitSum(int n)
    {
        string number = to_string(n);

        int sum = 0;

        for (int i = 0; i < number.size(); i++)
        {
            int digit = number[i] - '0';
            if (i % 2 == 0)
            {
                sum += digit;
            }
            else
            {
                sum -= digit;
            }
        }
        return sum;
    }
};
int main()
{
    return 0;
}