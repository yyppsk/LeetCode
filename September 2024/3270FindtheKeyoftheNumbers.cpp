#include <bits/bits-stdc++.h>
using namespace std;

string lenOne(string num)
{
    string bkp = num;
    num = "000" + bkp;
    return num;
}
string lenTwo(string num)
{

    string bkp = num;
    num = "00" + bkp;
    return num;
}
string lenThree(string num)
{
    string bkp = num;
    num = "0" + bkp;
    return num;
}

int generateKey(int num1, int num2, int num3)
{
    vector<string> numbers = {to_string(num1), to_string(num2), to_string(num3)};

    string resBuilder = "";
    int result = 0;
    for (int i = 0; i <= 2; i++)
    {
        switch (numbers[i].length())
        {
        case 1:
            numbers[i] = lenOne(numbers[i]);
            break;
        case 2:
            numbers[i] = lenTwo(numbers[i]);
            break;
        case 3:
            numbers[i] = lenThree(numbers[i]);
            break;
        default:
            break;
        }
    }

    for (int i = 0; i <= 4; i++)
    {
        int currentMin = INT_MAX;
        for (int j = 0; j <= 2; j++)
        {
            currentMin = min(numbers[j][i] - '0', currentMin);
        }

        resBuilder.push_back(currentMin + '0');
    }

    return stoi(resBuilder);
}
int main()
{
    generateKey(1, 10, 1000);
    return 0;
}