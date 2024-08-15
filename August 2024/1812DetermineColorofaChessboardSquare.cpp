#include <bits/bits-stdc++.h>
using namespace std;

bool squareIsWhite(string coordinates)
{
    unordered_map<char, char> bottom = {
        {'a', 'b'},
        {'b', 'w'},
        {'c', 'b'},
        {'d', 'w'},
        {'e', 'b'},
        {'f', 'w'},
        {'g', 'b'},
        {'h', 'w'},
    };
    if (((coordinates[1] - '0') % 2 == 0) && bottom[coordinates[0]] == 'b')
    {
        return true;
    }
    else if (((coordinates[1] - '0') % 2 == 1) && bottom[coordinates[0]] == 'w')
    {
        return true;
    }

    return false;
}
int main()
{
    squareIsWhite("h3");
    return 0;
}