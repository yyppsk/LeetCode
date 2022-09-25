#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q,y,x;
    cin>>Q;
    set<int> ans;
    for ( int i = 0; i < Q; i++){
         cin>>y>>x;
         if (y == 1)
            ans.insert(x);
        else if (y == 2)
            ans.erase(x);
        else if(y==3){
            set<int>::iterator itr = ans.find(x);
            if(itr == ans.end())
            {
                cout<<"No"<<endl;
            }
            else{
            cout<<"Yes"<<endl;
        }
            
    }
    
}
return 0;
}



