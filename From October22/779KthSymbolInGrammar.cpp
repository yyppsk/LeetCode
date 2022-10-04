#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void solve()
{
}
int main()
{
    int n = 6;
    string str = "0";
    vector<string> arr;
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(str);
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
        {
            str[i] = '01';
        }
    }
    for (auto i : arr)
    {
        cout << i << endl;
    }
    return 0;
}