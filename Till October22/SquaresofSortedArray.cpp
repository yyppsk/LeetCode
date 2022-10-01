#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) {
    int n;
    n = nums[0];
    vector<int> sqrs;
	for (auto it = nums.begin(); it != nums.end(); ++it){
        sqrs.push_back(*it * *it);
    }
    for (auto it = sqrs.begin(); it != sqrs.end(); ++it)
    {
        cout<<*it<<" ";
    }
}
int main() {
    vector<int> abc= {-4,-1,0,3,10};
    (sortedSquares(abc));
    return 0;
}