/*
class Solution {
public:
    int count = 0;
    int max = 0;
    int findMaxConsecutiveOnes(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                if (count > max){
                    max = count;
                }
                count = 0;
            }
            if(nums[i] == 1)
            {
                count++;
                if (count > max){
                    max = count;
                }
                
            }
            
        }
        
        return max; 
    }
};
*/