#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++, end--;
    }
}

int main()
{
    int num[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> num[i];
        cout << "the array is" << num[i] << " ";
    }
    reverse(num, 10);
    cout << "the reversed array" << num << " ";
}