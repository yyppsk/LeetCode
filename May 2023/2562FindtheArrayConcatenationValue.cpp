#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
string convert(long long a, long long b)
{
    stringstream ss;
    ss << a << b;
    string result = ss.str();
    return result;
}
long long fast_atoi(const string &str)
{
    long long val = 0;
    for (char c : str)
    {
        if (c >= '0' && c <= '9')
        {
            val = val * 10 + (c - '0');
        }
    }
    return val;
}

long long findTheArrayConcVal(vector<int> &nums)
{
    long long sum = 0;
    int start = 0, end = nums.size() - 1;
    int oddthing = nums.size();
    while (start <= end)
    {
        long long first = nums[start];
        if (start == (oddthing / 2))
        {
            stringstream ss;
            ss << first;
            string rs = ss.str();
            sum += fast_atoi(rs);
            return sum;
        }
        long long last = nums[end];
        cout << "F: " << first << " last : " << last << endl;
        string calc = convert(first, last);
        cout << "Calc : " << calc << endl;
        sum += fast_atoi(calc);
        cout << "Sum : " << sum << endl;
        start++, end--;
    }

    return sum;
}
int main()
{
    vector<int> nums = {5, 14, 13, 8, 12};
    cout << findTheArrayConcVal(nums);
    return 0;
}