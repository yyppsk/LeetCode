// CPP program to demonstrate implementation of
// erase function in unordered_map.
#include <unordered_map>
#include <iostream>
using namespace std;

int main()
{

    int N = 3;
    // odd line pr 1
    // even pr 0
    /*
    int c = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << c++
                 << " ";
        }
        cout << endl;
    }
    */
    int c = 65;
    /*
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%C ", c++);
        }
        cout << endl;
    }
    */
    /*
     for (int i = 0; i < N; i++)
     {
         for (int j = 0; j <= i; j++)
         {
             printf("%C ", j + c);
         }
         c = 65;
         cout << endl;
     }
     */
    /*
    for (int i = N; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%C ", j + c);
        }
        cout << endl;
    }
    */
    /*
     for (int i = 0; i < N; i++)
     {
         for (int j = 0; j <= i; j++)
         {
             printf("%C ", c + i);
         }
         cout << endl;
     }
     */
    int f = 64;
    int counter = 0;
    // A = 65,B 66 ,C67 D68 E69
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%C ", (f + N) - counter);
            counter++;
        }
        counter = 0;
        f = 64;
        cout << endl;
    }
    return 0;
}
