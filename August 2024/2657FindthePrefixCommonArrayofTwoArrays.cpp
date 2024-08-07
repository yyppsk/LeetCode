#include <bits/bits-stdc++.h>
using namespace std;

// Input: A = [1,3,2,4], B = [3,1,2,4]
//  Output: [0,2,3,4]

vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
    int arr[51] = {0};
    vector<int> result(A.size());
    int common = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (arr[A[i]] == 1)
        {
            common++;
        }
        arr[A[i]]++;

        if (arr[B[i]] == 1)
        {
            common++;
        }
        arr[B[i]]++;

        result[i] = common;
    }
    return result;
}
int main()
{
    vector<int> A = {1, 2, 3, 4, 5}, B = {5, 4, 3, 2, 1};
    findThePrefixCommonArray(A, B);
    return 0;
}
// c = 1
// A[0,0,1,]
//       i
//[1,2,3,4,5]

//[5,4,3,2,1]

//[0,0,1,3,5] req

//[0,1,2,2,2,1]