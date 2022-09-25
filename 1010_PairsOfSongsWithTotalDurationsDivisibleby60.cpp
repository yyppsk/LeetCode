#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
void numPairsDivisibleBy60(vector<int> &time, int k)
{
    unordered_map<int, int> map;
    for (int i : time)
    {
        int rem = i % k;
        if ()
    }
}
int main()
{
    vector<int> time = {30, 20, 150, 100, 40};
    int k = 60;
    numPairsDivisibleBy60(time, k);
    return 0;
}