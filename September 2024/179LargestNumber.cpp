#include <bits/bits-stdc++.h>
using namespace std;

string largestNumber(vector<int> &nums)
{
    vector<string> numbers;

    for (const auto &ele : nums)
    {
        numbers.push_back(to_string(ele));
    }

    sort(numbers.begin(), numbers.end(), [](string &a, string &b)
         { return a + b > b + a; });
    if (numbers[0] == "0")
        return "0";
    string res = "";

    for (const auto &ele : numbers)
    {
        res += ele;
    }

    return res;
}
int main()
{
    return 0;
}