#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int guess(int target)
{
    int pick = 0;
    if (target > pick)
        return -1;
    if (target < pick)
        return 1;
    if (target == pick)
        return 0;
};
int guessNumber(int n)
{
    int start = 1;
    int end = n;
    int target = start + (end - start) / 2;
    if (guess(target) == 0)
        return target;
    while (start <= end)
    {

        if (guess(target) == 0)
            return target;

        if (guess(target) == -1)
            end = target - 1;

        if (guess(target) == 1)
            start = target + 1;
        target = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    return 0;
}