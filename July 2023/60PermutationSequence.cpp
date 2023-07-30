#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string getPermutation(int n, int k)
{
    vector<int> numbers;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n); // last nth number
    string ans = "";
    k = k - 1;
    while (true)
    {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0)
            break;
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}
int main()
{
    return 0;
}