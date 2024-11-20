#include <bits/bits-stdc++.h>
using namespace std;
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
int main()
{
    vector<int> arr = {5, 7, 1, 4};
    int k = 3;
    decrypt(arr, k);
    return 0;
}