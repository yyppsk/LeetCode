#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cd = arr[1] - arr[0];
        bool checker;
        for(int i = 1; i < arr.size(); i++){
            printf("\narr[%d](%d) - arr[%d](%d) = %d",i,arr[i],i-1,arr[i-1],arr[i]-arr[i-1]);
            if((arr[i] - arr[i-1]) == cd){
                checker = true;
            }
            else{
                checker = false;
                return checker;
            }
        }
        cout<<endl;
        return checker;
    }
int main()
{   vector<int> vec = {1,10,10,10,19};
    cout<<canMakeArithmeticProgression(vec);
    return 0;
}