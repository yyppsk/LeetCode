#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> bills)
{
    int ten = 0, five = 0;
    for (int i = 0; i < bills.size(); i++)
    {

        int currentPayment = bills[i];

        if (bills[i] == 5)
        {
            five++;
        }
        else if (bills[i] == 10)
        {
            ten++;
        }

        cout << "i : " << i
             << " Tens: " << ten
             << " five: " << five
             << "\n";

        if (currentPayment == 10)
        {

            if (five < 1)
            {
                return false;
            }
            else
            {
                five--;
            }
        }

        if (currentPayment == 20)
        {
            if (ten >= 1 && five >= 1)
            {
                ten--;
                five--;
            }
            else if (five >= 3)
            {
                five -= 3;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}
int main()
{
    cout << lemonadeChange({5, 5, 5, 20});
    return 0;
}