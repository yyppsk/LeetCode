#include<iostream>
#include<vector>
using namespace std;
int digits(int a){
        int count{1};
        while(a/10>0){
            a/=10;
            count++;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int ans{};
        for(auto &sel:nums){
            if(digits(sel)%2==0)++ans;
        }
        return ans;
    }
int main()
{   int f=0;
    vector<int> nums = {12,345,2,6,7896,111,234,103,473,121344,7453};
    f = findNumbers(nums);
    cout<<"\nf="<<f;
    return 0;
}
