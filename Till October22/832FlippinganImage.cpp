#include <iostream>
#include <vector>
#include <algorithm>

#include <string>
using namespace std;
int main()
{
    vector<vector<int>> arr = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    int k = arr[0].size() - 1;
    int f = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int k = arr[i].size() - 1;
        int f = 0;
        while (f < k)
        {
            swap((arr[i][f]), (arr[i][k]));
            f++;
            k--;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            arr[i][j] = !arr[i][j];
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}