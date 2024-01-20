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
    string addBinary(string a, string b)
    {
        string s = "";
        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i] - '0';
            if (j >= 0)
                sum += b[j] - '0';
            s.push_back((sum % 2) + '0');
            carry = (sum / 2);
            i--, j--;
        }
        if (carry != 0)
        {
            s.push_back(carry + '0');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    return 0;
}