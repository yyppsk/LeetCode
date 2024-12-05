#include <bits/bits-stdc++.h>
using namespace std;
bool canChange(string start, string target)
{
    int i = 0, j = 0;
    int n = start.length();

    while (i < n && j < n)
    {
        while (i < n && start[i] == '_')
            i++;
        while (j < n && target[j] == '_')
            j++;

        if (i == n && j == n)
            return true;

        if (i == n || j == n)
            return false;

        if (start[i] != target[j])
            return false;

        if (start[i] == 'R' && j < i)
            return false;

        if (start[i] == 'L' && i < j)
            return false;

        i++;
        j++;
    }

    while (i < n && start[i] == '_')
        i++;
    while (j < n && target[j] == '_')
        j++;

    return i == n && j == n;
}
int main()
{
    string start = "_L__R__R_", target = "L______RR";
    cout << canChange(start, target);
    return 0;
}