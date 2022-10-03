#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool bs(int target, vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        // printf("Finding if %d is in range(%d,%d)\n", target, start, end);
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return true;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return false;
}
int findKthPositive(vector<int> &arr, int k)
{
    int check = 0;
    for (int i = 1; i <= arr[arr.size() - 1] + k; i++)
    {
        cout << "Is " << i << " present " << bs(i, arr) << endl;
        if (bs(i, arr) == 0)
            ++check;
        if (check == k)
            return i;
    }
    return 0;
}
int main()
{
    // Hard test case [2,24,25,26,27,32,42,45,54,90] 415
    vector<int> arr = {2, 3, 4, 7, 11};
    vector<int> arr2 = {1, 2, 3, 4};
    int k = 5;
    cout << findKthPositive(arr, k);
    return 0;
}
/*

Question here demands us to find the missing numbers in the given array. Suppose if the given array is :
{ 1 , 2 , 4, 5 , 6 , 8 } , K = 2
Then pretty much we can observe that missing numbers can be in inclusive range (When I say inclusive, I mean containing both ends start to end { 3,7...... N) Where N can be infinite if we talk about all natural numbers missing.

So Obviously we are never gonna traverse infinitely, are we? So here we have K, that comes to our rescue. The question demands 'Kth' missing element from us so we know how long we have to have our missing number's list. Right?

So the idea is to Start searching for all numbers from 1 - last element given in array ( Why? Because array is sorted and we need to search at only that point.)
{ 1 , 2 , 4, 5 , 6 , 8 }, Here obviosly our range of search should be inclusive [1 to 8], not beyond that.

for( i = 0; i < 8 + K ; i++)

Wondering why + K?
Ex: arr = { 1 , 2 , 3 ,4}, k = 2.
Our missing numbers will be {4,5,6,7,8.....N] We ar interested in 2nd number which would be 5 in our case. But we observe if we only run our loop till last element of array then we will be bounded to i = 0 to i < 4 and we might not missing number 4 & 5.
Using a clever idea we add + k to extend minimum requirement of our range.

I used simple binary search to locate if element is present in our range or not, if it does then I increase the counter.
When counter reaches to K. Means we are on our required missing number. Uncomment my print statement to have a visual output.
*/