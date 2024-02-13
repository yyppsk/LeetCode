#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    bool divisorGame(int n)
    {
        return (n & 1) == 0;
    }
};
int main()
{
    return 0;
}