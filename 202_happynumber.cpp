#include <iostream>
#include <set>
using namespace std;
bool isHappy(int n)
{
    if (n == 1)
        return true;
    else
    {   set<int> s;
        int sum = 0;
        do
        {   
            s.insert(n);
            if (n == 0)
            {
                n = sum;
                sum = 0;
            }
            printf("Here, sum = sum+(n%10)^2 => sum(%d) = %d + %d\n", sum + (n % 10) * (n % 10), sum, (n % 10) * (n % 10));
            sum = sum + (n % 10) * (n % 10); // 81 + 0
            printf("Here, n = n / 10 => n(%d) = %d / 10\n", n / 10, n);
            n = n / 10; // 8
            printf("Here, n = n / 10 => n(%d) = %d / 10\n", n / 10, n);
            for(auto i: s){
            cout<<i<<" ";
        }
            if (n == 1)
                return true;
            else if(s.find(n)!=s.end()){
                return false;
            }

        } while (sum != 1);
        return 0;
    }
}
int main()
{
    int a = 7;
    printf("%d", isHappy(a));
    return 0;
}