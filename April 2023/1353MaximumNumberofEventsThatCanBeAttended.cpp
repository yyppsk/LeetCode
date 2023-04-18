#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int maxEvents(vector<vector<int>> &events)
{
    
}
int main()
{
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}};
    int Output = 3;
    if (maxEvents(events) == Output)
        cout << "Correct";
    else
        cout << "Incorrect";
    return 0;
}