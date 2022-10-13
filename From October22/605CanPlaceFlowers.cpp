#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool canPlaceFlowers2(vector<int> &flowerbed, int n)
{
    int count = 0;

    for (int i = 0; i < flowerbed.size(); i++)
    {
        if (flowerbed[i] == 0)
        {
            int prev = (i == 0 || flowerbed[i - 1] == 0) ? 0 : 1;
            int next = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) ? 0 : 1;

            if (prev == 0 && next == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }
    }
    return count >= n;
}
bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    if (flowerbed.size() == 1)
        if (flowerbed[0])
            return true;
    int count = 0;
    int j = 0;
    for (int i = 0; i < flowerbed.size(); i++)
    {
        if (i == 0)
        {
            // printf("Checking %d[%d]\n", flowerbed[i], i);
            if (flowerbed[i] == 0)
            {
                if (flowerbed[i] == 0)
                {
                    count++;
                    flowerbed[i] = 1;
                }
            }
        }
        else
        {
            // printf("Checking %d[%d] and %d[%d] and %d[%d]\n", flowerbed[i - 1], i - 1, flowerbed[i], i, flowerbed[i + 1], i + 1);
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {

                count++;
                flowerbed[i] = 1;
            }
        }
        // printf("Used %d flowers\nFlowerBed ->", count);
        /*
        for (auto i : flowerbed)
        {
            cout << i << " ";
        }
        cout << endl;
        */
    }
    return count == n;
}
int main()
{
    vector<int> flowerbed = {1, 0, 0, 0, 1, 0, 0};
    int n = 2;
    cout << canPlaceFlowers(flowerbed, n);
    return 0;
}