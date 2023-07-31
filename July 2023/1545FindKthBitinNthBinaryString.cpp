#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void invert(string &previous)
{
    int left = 0;
    int right = previous.length() - 1;

    while (left < right)
    {
        // Flip the bits (assuming the input string contains only '0' and '1')
        previous[left] = '0' + ('1' - previous[left]);
        previous[right] = '0' + ('1' - previous[right]);
        left++;
        right--;
    }

    // In case of an odd-length string, flip the middle character if necessary
    if (left == right)
    {
        previous[left] = '0' + ('1' - previous[left]);
    }
}
void reverse(string &rev)
{
    int start = 0, end = rev.size() - 1;
    while (start <= end)
    {
        swap(rev[start], rev[end]);
        start++, end--;
    }
}
char findKthBit(int n, int k)
{
    // how should I generate the first n sequence
    char first = '0';
    string sequence = "";
    sequence.push_back(first);
    for (int i = 2; i <= n; i++)
    {
        string previous = sequence;
        invert(previous);
        reverse(previous);
        sequence.push_back('1');
        sequence += previous;
    }
    return sequence[k - 1];
}
int main()
{
    cout << findKthBit(4, 11);
    return 0;
}