#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void shortlist(vector<bool> &directory, int start, int size)
{
    for (int factor = start; factor <= size; factor = start + factor)
    {
        directory[factor] = true;
    }
}
int sumOfMultiples(int n)
{
    vector<bool> directory(n + 1, 0);
    shortlist(directory, 3, n);
    shortlist(directory, 7, n);
    shortlist(directory, 5, n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (directory[i])
            sum += i;
    }
    return sum;
}
int main()
{
    cout << sumOfMultiples(10);
    return 0;
}