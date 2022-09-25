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
    int Q,type,marks;
    string name;
    cin>>Q;
    map<string,int> markSheet;
    for ( int i = 0; i < Q; i++){
         cin>>type;
         if(type == 1){
            cin>>name;
            cin>>marks;
            markSheet[name] += marks;
         }
        else if (type == 2){
            cin>>name;
            markSheet.erase(name);
        }
        
        else if(type==3){
            cin>>name;
            cout<<markSheet[name]<<endl;
        }
            
    }
    return 0;
}




