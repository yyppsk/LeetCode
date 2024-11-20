#include <bits/bits-stdc++.h>
using namespace std;

// Brute force
vector<int> decrypt(vector<int> &code, int k)
{
    int N = code.size();
    vector<int> result(N, 0);

    if (k == 0)
    {
        return result;
    }

    if (k > 0)
    {
        for (int i = 0; i < N; i++)
        {
            int sum = 0;

            for (int j = i + 1; j <= i + k; j++)
            {
                sum += code[j % N];
            }
            result[i] = sum;
        }
    }
    else
    {

        k = -k;
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i - 1; j >= i - k; j--)
            {
                sum += code[(j + N) % N];
            }
            result[i] = sum;
        }
    }
    return result;
}

// Optimal

vector<int> decryptSlidingWindow(vector<int> &code, int k)
{
    int N = code.size();
    vector<int> result(N, 0);

    if (k == 0)
    {
        return result;
    }

    int i, j, windowSum = 0;
    if (k < 0)
    {
        i = N - abs(k), j = N - 1;
    }
    else
    {
        i = 1, j = k;
    }

    for (int ptr = i; ptr <= j; ptr++)
    {
        windowSum += code[ptr];
    }

    for (int k = 0; k < N; k++)
    {
        result[k] = windowSum;
        windowSum -= code[i % N];
        i++;

        j++;
        windowSum += code[(j) % N];
    }
    return result;
}

int main()
{
    vector<int> arr = {5, 7, 1, 4};
    int k = 3;
    decrypt(arr, k);
    return 0;
}