#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int maxi = -1;
void subsequence(int idx, vector<int> &current, vector<int> &nums, unordered_set<float> &st)
{
    if (idx >= nums.size())
    {
        if (!current.empty() && current.size() > 1) // Only print non-empty subsequences
        {
            int size = current.size();
            maxi = max(maxi, size);

            for (auto const &ele : current)
            {
                cout << ele << " ";
            }
            cout << "\n";
        }
        return;
    }
    cout << "Current number " << nums[idx] << "\n";
    long long square = static_cast<long long>(nums[idx]) * nums[idx];
    float root = sqrt(nums[idx]);

    bool canAdd = false;
    if (current.empty())
    {
        canAdd = true;
    }
    else if (st.find(nums[idx]) == st.end() && (st.find(square) != st.end() || st.find(root) != st.end()))
    {
        cout << "SQ : " << square << " -- SQROOT :" << root << "\n";
        canAdd = true;
    }

    if (canAdd)
    {
        current.push_back(nums[idx]);
        st.insert(nums[idx]);
        cout << "Added " << nums[idx] << "\n";
        subsequence(idx + 1, current, nums, st);
        current.pop_back();
        st.erase(nums[idx]);
    }

    subsequence(idx + 1, current, nums, st);
}

int longestSquareStreak(vector<int> &nums)
{
    unordered_set<float> st;
    vector<int> curr;
    subsequence(0, curr, nums, st);
}

int main()
{
    vector<int> nums = {2, 4, 4, 2};
    longestSquareStreak(nums);
    return 0;
}
