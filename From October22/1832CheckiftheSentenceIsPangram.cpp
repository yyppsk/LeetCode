#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool checkIfPangram(string sentence)
{
    vector<int> arr(27, -1);
    arr[0] = 0;
    for (int i = 0; i < sentence.size(); i++)
    {
        // cout << "Checking " << sentence[i] << endl;
        switch (sentence[i])
        {
        case 'a':
            if (arr[1] == -1)
            {
                arr[1] = 1;
            }
            break;
        case 'b':
            if (arr[2] == -1)
            {
                arr[2] = 1;
            }
            break;
        case 'c':
            if (arr[3] == -1)
            {
                arr[3] = 1;
            }
            break;
        case 'd':
            if (arr[4] == -1)
            {
                arr[4] = 1;
            }
            break;
        case 'e':
            if (arr[5] == -1)
            {
                arr[5] = 1;
            }
            break;
        case 'f':
            if (arr[6] == -1)
            {
                arr[6] = 1;
            }
            break;
        case 'g':
            if (arr[7] == -1)
            {
                arr[7] = 1;
            }
            break;
        case 'h':
            if (arr[8] == -1)
            {
                arr[8] = 1;
            }
            break;
        case 'i':
            if (arr[9] == -1)
            {
                arr[9] = 1;
            }
            break;
        case 'j':
            if (arr[10] == -1)
            {
                arr[10] = 1;
            }
            break;
        case 'k':
            if (arr[11] == -1)
            {
                arr[11] = 1;
            }
            break;
        case 'l':
            if (arr[12] == -1)
            {
                arr[12] = 1;
            }
            break;
        case 'm':
            if (arr[13] == -1)
            {
                arr[13] = 1;
            }
            break;
        case 'n':
            if (arr[14] == -1)
            {
                arr[14] = 1;
            }
            break;
        case 'o':
            if (arr[15] == -1)
            {
                arr[15] = 1;
            }
            break;
        case 'p':
            if (arr[16] == -1)
            {
                arr[16] = 1;
            }
            break;
        case 'q':
            if (arr[17] == -1)
            {
                arr[17] = 1;
            }
            break;
        case 'r':
            if (arr[18] == -1)
            {
                arr[18] = 1;
            }
            break;
        case 's':
            if (arr[19] == -1)
            {
                arr[19] = 1;
            }
            break;
        case 't':
            if (arr[20] == -1)
            {
                arr[20] = 1;
            }
            break;
        case 'u':
            if (arr[21] == -1)
            {
                arr[21] = 1;
            }
            break;
        case 'v':
            if (arr[22] == -1)
            {
                arr[22] = 1;
            }
            break;
        case 'w':
            if (arr[23] == -1)
            {
                arr[23] = 1;
            }
            break;
        case 'x':
            if (arr[24] == -1)
            {
                arr[24] = 1;
            }
            break;
        case 'y':
            if (arr[25] == -1)
            {
                arr[25] = 1;
            }
            break;
        case 'z':
            if (arr[26] == -1)
            {
                arr[26] = 1;
            }
            break;
        }
    }
    /*for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    */
    int sum = 0;
    sum = accumulate(arr.begin(), arr.end(), sum);
    if (sum == 26)
    {
        return true;
    }
    else
        return false;
}
int main()
{
    string sentence = "abcdefghijklimnopqrstuvwdjfhdskfdgfkadjkasdkxyz";
    cout << checkIfPangram(sentence);
    return 0;
}