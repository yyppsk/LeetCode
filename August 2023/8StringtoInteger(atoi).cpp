#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        int number = 0, sign = 1;
        // 1 is positive -1 is neg
        int i = 0;
        while (s[i] == ' ')
            i++;
        if (i < s.size() && (s[i] == '-' || s[i] == '+'))
        {
            sign = s[i] == '+' ? 1 : -1;
            ++i;
        }
        while (i < s.size() && isdigit(s[i]))
        {
            if (number > INT_MAX / 10 || (number == INT_MAX / 10 && s[i] > '7'))
                return sign == -1 ? INT_MIN : INT_MAX;
            number = number * 10 + (s[i] - '0');
            ++i;
        }
        return number * sign;
    }
};
int main()
{
    return 0;
}