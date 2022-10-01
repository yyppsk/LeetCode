#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
      int c;
      cin>>c;
      //for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
      //for (auto it = v.begin(); it != v.end(); ++it)
      vector<int> vectmain(c);
    for(auto& i : vectmain){
        cin>>i;
    }
    /*
    for (auto it = vectmain.begin(); it != vectmain.end(); ++it)
    {
        cout<<*it<<" ";
    }
    */
    sort(vectmain.begin(),vectmain.end());
    for (auto it = vectmain.begin(); it != vectmain.end(); ++it)
    {
        cout<<*it<<" ";
    }
    return 0;
}
