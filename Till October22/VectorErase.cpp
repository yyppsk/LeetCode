#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; 
    cin>>N;
    vector<int> nums(N);
    for(auto& i : nums){
        cin>>i;
    }
    int x;
    cin>>x;
    int a,b;
    cin>>a>>b;
    nums.erase (nums.begin()+(x-1));
    nums.erase(nums.begin()+a-1 , nums.begin()+b-1);
    cout << nums.size() << endl;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        cout<<*it<<" ";
    }
    return 0;
}
