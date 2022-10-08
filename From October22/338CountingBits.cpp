#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
vector<int> countBits(int divident)
{

    int divisor = 2;
    vector<int> res;
    int remainder;
    while (divident > 1)
    {
        remainder = divident % divisor;
        divident = divident / divisor;
        res.push_back(remainder);
    }
    res.push_back(1);
    reverse(res.begin(), res.end());
    for (auto i : res)
    {
        cout << i << " ";
    }
    return {};
}
int main()
{
    int n = 100;
    countBits(n);
    return 0;
}