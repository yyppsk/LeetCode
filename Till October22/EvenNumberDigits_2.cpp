#include<iostream>
#include<vector>
using namespace std;
int findNumbers(vector<int>& nums) {
        int ctl = 0,temp = 0,max=0;
        for(int i = 0; i < nums.size(); i++){
            temp = nums[i];
            //cout<<"\nTemp and nums = "<<temp<<" "<<nums[i];
            do{
                temp = temp/10;
                ctl++;
                cout<<"\nchange temp and ctl = "<<temp<<" "<<ctl;
            }
            while(temp > 0);
            if(ctl % 2 == 0)
                max++;
            ctl = 0;
        }
        return max;
    } 
int main()
{   int f=0;
    vector<int> nums = {12,345,2,6,7896,111,234,103,473,121344,7453};
    f = findNumbers(nums);
    cout<<"\nf="<<f;
    return 0;
}
