#include <iostream>
#include <string>
using namespace std;

int countBinarySubstrings(string s)
{
    int n = s.size();
    int counter = 0;
    int prevCount = 0;
    int currCount = 1;

    for (int i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1])
        {
            currCount++;
        }
        else
        {
            counter += min(prevCount, currCount);
            prevCount = currCount;
            currCount = 1;
        }
    }
    counter += min(prevCount, currCount); // Add the count of the last group
    return counter;
}

int main()
{
    cout << countBinarySubstrings("00110011");
    return 0;
}
