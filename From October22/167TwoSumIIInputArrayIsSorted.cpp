#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++)
    {
        int start = i + 1;
        int end = numbers.size() - 1;
        while (start <= end)
        {
            cout << "Y";
            int mid = start + (end - start) / 2;
            if (numbers[mid] == target - numbers[i])
            {
                answer.push_back(i + 1);
                answer.push_back(mid + 1);
                cout << answer[0] << " " << answer[1] << endl;
                return answer;
            }
            else if (numbers[mid] > target - numbers[i])
            {
                end = mid - 1;
            }
            else
            {
                start = start + 1;
            }
        }
    }
    return {-1, -1};
}
int main()
{
    vector<int> arr = {12, 13, 23, 28, 43, 44, 59, 60, 61, 68, 70, 86, 88, 92, 124, 125, 136, 168, 173, 173, 180, 199, 212, 221, 227, 230, 277, 282, 306, 314, 316, 321, 325, 328, 336, 337, 363, 365, 368, 370, 370, 371, 375, 384, 387, 394, 400, 404, 414, 422, 422, 427, 430, 435, 457, 493, 506, 527, 531, 538, 541, 546, 568, 583, 585, 587, 650, 652, 677, 691, 730, 737, 740, 751, 755, 764, 778, 783, 785, 789, 794, 803, 809, 815, 847, 858, 863, 863, 874, 887, 896, 916, 920, 926, 927, 930, 933, 957, 981, 997};
    int t = 542;
    twoSum(arr, t);
    return 0;
}