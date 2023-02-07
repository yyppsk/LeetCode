#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
int main()
{
    vector<int> dig = {1, 2, 3};
    string b = "";
    for (auto i : dig)
    {
        b.push_back(i);
    }
    cout << b << endl;
    return 0;
}