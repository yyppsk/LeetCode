#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void addRecursively(string &num1, int p1, string &num2, int p2, int carry, string &ans)
{
    if (p1 < 0 && p2 < 0)
    {
        if (carry != 0)
        {
            ans.push_back(carry + '0');
        }
        return;
    }

    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';

    int currentSum = n1 + n2 + carry;
    int digit = currentSum % 10;
    carry = currentSum / 10;
    ans.push_back(digit + '0');

    // RC
    addRecursively(num1, p1 - 1, num2, p2 - 1, carry, ans);
}
string addStrings(string num1, string num2)
{
    string ans = "";
    addRecursively(num1, num1.size() - 1, num2, num2.size() - 1, 0, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    cout << addStrings("1", "1");
    return 0;
}