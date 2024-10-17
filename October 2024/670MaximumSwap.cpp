#include <bits/bits-stdc++.h>
using namespace std;

int maximumSwap(int num)
{

    int max_number = -1, index = -1;
    int leftidx = -1;
    int rightidx = -1;

    string number = to_string(num);

    for (int i = number.size() - 1; i >= 0; --i)
    {
        if (number[i] > max_number)
        {
            max_number = number[i];
            index = i;
            continue;
        }

        if (number[i] < max_number)
        {
            leftidx = i;
            rightidx = index;
        }
    }

    if (leftidx == -1)
        return num;

    swap(number[leftidx], number[rightidx]);

    return stoi(number);
}
int main()
{
    return 0;
}