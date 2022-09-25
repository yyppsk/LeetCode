#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void romanToInt(string s)
{
    unordered_map<int, char> symbol;
    symbol['I'] = 1;
    symbol['V'] = 5;
    symbol['X'] = 10;
    symbol['L'] = 50;
    symbol['C'] = 100;
    symbol['D'] = 500;
    symbol['M'] = 1000;
    cout << symbol['L'] << endl;
    cout << symbol['V'] << endl;
    cout << symbol['I'] << endl;
    cout << symbol['I'] << endl;
    cout << symbol['L'] << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] << " ";
    }
}
int main()
{
    string s = "LVIII";
    romanToInt(s);

    return 0;
}