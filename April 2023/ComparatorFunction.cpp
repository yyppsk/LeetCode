#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// #define lpr pair<long long int, long long int>
#define S second
#define F first
bool comparefn(pair<long long int, long long int> a, pair<long long int, long long int> b)
{
    if (a.S != b.S)
        return a.F <= b.F;
    return false;
}
int main()
{
    vector<lpr> a;
    sort(a.begin(), a.end(), comparefn);
    for (auto i : a)
    {
        cout << i << " ";
    }
    return 0;
}