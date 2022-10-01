//1679 O(n), Space : O(1)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(), nums.end());
        int front = 0, end = nums.size()-1;
        int count = 0;
        while(front < end){
            if(nums[front] + nums[end] == k){
                count++;
                front++;end--;
            }
            else if(nums[front]+nums[end] < k){
                front++;
            }
            else
                end--;
        }
        return count;
    }
};