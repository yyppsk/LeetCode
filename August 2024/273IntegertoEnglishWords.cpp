#include <bits/bits-stdc++.h>
using namespace std;
string numberToWords(int num)
{
    unordered_map<char, vector<string>> conversionScale =
        {{0, {"Zero"}}, {1, {"One", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}}, {2, {"Two", "Twenty"}}, {3, {"Three", "Thirty"}}, {4, {"Four", "Forty"}}, {5, {"Five", "Fifty"}}, {6, {"Six", "Sixty"}}, {7, {"Seven", "Seventy"}}, {8, {"Eight", "Eighty"}}, {9, {"Nine", "Ninety"}}, {10, {"Ten", "Hundred"}}};

    string number = to_string(num);
    int i = 0;

    string answer = "";
    if (number.size() - i == 10)
    {
        cout << conversionScale[number[i] - '0'][0] << " ";
        cout << "Billion ";

        // Next three are gonna be for 100 Million
        // if not zero
        if (number[i + 1] != '0')
        {
            cout << conversionScale[number[i + 1] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Tens of million
        if (number[i + 2] != '0')
        {
            cout << conversionScale[number[i + 2] - '0'][1] << " ";
        }
        if (number[i + 3] != '0')
        {
            cout << conversionScale[number[i + 3] - '0'][0] << " ";
            cout << "Million ";
        }

        // HUNDRED THOUSAND
        if (number[i + 4] != '0')
        {
            cout << conversionScale[number[i + 4] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Eleven twelve to Nineteen case
        if (number[i + 5] == '1')
        {
            cout << conversionScale[number[i + 5] - '0'][number[i + 6] - '0' + 1] << " ";
            cout << "Thousand ";
        }
        else
        {
            cout << conversionScale[number[i + 5] - '0'][1] << " ";
            if (number[i + 6] == '0')
            {
                cout << "Thousand ";
            }
        }

        // Thousand
        if (number[i + 7] != '0' && number[i + 5] != '1')
        {
            cout << conversionScale[number[i + 7] - '0'][0] << " ";
            cout << "Thousand ";
        }
        // HUNDREDS
        if (number[i + 7] != '0')
        {
            cout << conversionScale[number[i + 7] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Tens

        if (number[i + 8] != '0')
        {
            cout << conversionScale[number[i + 8] - '0'][1] << " ";
        }

        // Ones

        if (number[i + 9] != '0')
        {
            cout << conversionScale[number[i + 9] - '0'][0] << " ";
        }
    }
    else if (number.size() - i == 9)
    { // Next three are gonna be for 100 Million
        // if not zero
        if (number[i] != '0')
        {
            cout << conversionScale[number[i] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Tens of million
        if (number[i + 1] != '0')
        {
            cout << conversionScale[number[i + 1] - '0'][1] << " ";
        }
        if (number[i + 2] != '0')
        {
            cout << conversionScale[number[i + 2] - '0'][0] << " ";
            cout << "Million ";
        }

        // HUNDRED THOUSAND
        if (number[i + 3] != '0')
        {
            cout << conversionScale[number[i + 3] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Eleven twelve to Nineteen case
        if (number[i + 4] == '1')
        {
            cout << conversionScale[number[i + 4] - '0'][number[i + 5] - '0' + 1] << " ";
            cout << "Thousand ";
        }
        else
        {
            cout << conversionScale[number[i + 4] - '0'][1] << " ";
            if (number[i + 5] == '0')
            {
                cout << "Thousand ";
            }
        }

        // Thousand
        if (number[i + 5] != '0')
        {
            cout << conversionScale[number[i + 5] - '0'][0] << " ";
            cout << "Thousand ";
        }

        // HUNDREDS
        if (number[i + 6] != '0')
        {
            cout << conversionScale[number[i + 6] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Tens

        if (number[i + 7] != '0')
        {
            cout << conversionScale[number[i + 7] - '0'][1] << " ";
        }

        // Ones

        if (number[i + 8] != '0')
        {
            cout << conversionScale[number[i + 8] - '0'][0] << " ";
        }
    }
    else if (number.size() - i == 8)
    {
        // Next two are gonna be for 10 Million
        // if not zero
        // Tens of million
        if (number[i] != '0')
        {
            cout << conversionScale[number[i] - '0'][1] << " ";
        }
        if (number[i + 1] != '0')
        {
            cout << conversionScale[number[i + 1] - '0'][0] << " ";
            cout << "Million ";
        }

        // HUNDRED THOUSAND
        if (number[i + 2] != '0')
        {
            cout << conversionScale[number[i + 2] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Eleven twelve to Nineteen case
        if (number[i + 3] == '1')
        {
            cout << conversionScale[number[i + 3] - '0'][number[i + 4] - '0' + 1] << " ";
            cout << "Thousand ";
        }
        else
        {
            cout << conversionScale[number[i + 3] - '0'][1] << " ";
            if (number[i + 4] == '0')
            {
                cout << "Thousand ";
            }
        }

        // Thousand
        if (number[i + 5] != '0' && number[i + 3] != '1')
        {
            cout << conversionScale[number[i + 5] - '0'][0] << " ";
            cout << "Thousand ";
        }

        // HUNDREDS
        if (number[i + 5] != '0')
        {
            cout << conversionScale[number[i + 5] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Tens

        if (number[i + 6] != '0')
        {
            cout << conversionScale[number[i + 6] - '0'][1] << " ";
        }

        // Ones

        if (number[i + 7] != '0')
        {
            cout << conversionScale[number[i + 7] - '0'][0] << " ";
        }
    }
    else if (number.size() - i == 7)
    {
        // Next one are gonna be for 1 Million
        // if not zero
        // Ones of million
        if (number[i] != '0')
        {
            cout << conversionScale[number[i] - '0'][0] << " ";
            cout << "Million ";
        }

        // HUNDRED THOUSAND
        if (number[i + 1] != '0')
        {
            cout << conversionScale[number[i + 1] - '0'][0] << " ";
            cout << "Hundred ";
        }

        // Eleven twelve to Nineteen case
        if (number[i + 2] == '1')
        {
            cout << conversionScale[number[i + 2] - '0'][number[i + 3] - '0' + 1] << " ";
        }
        else if (number[i + 2] != '0')
        {
            cout << conversionScale[number[i + 2] - '0'][1] << " ";
        }
        // Thousand

        if (number[i + 1] != '0' && number[i + 2] == '0' && number[i + 3] == '0')
        {
            cout << "Thousand ";
        }
        else if (number[i + 1] != '0' && number[i + 2] != '0' && number[i + 3] == '0')
        {
            cout << "Thousand ";
        }
        else
        {
            cout << conversionScale[number[i + 3] - '0'][0] << " ";
            cout << "Thousand ";
        }

        // HUNDREDS
        if (number[i + 4] != '0')
        {
            cout << conversionScale[number[i + 4] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Tens

        if (number[i + 5] != '0')
        {
            cout << conversionScale[number[i + 5] - '0'][1] << " ";
        }

        // Ones

        if (number[i + 6] != '0')
        {
            cout << conversionScale[number[i + 6] - '0'][0] << " ";
        }
    }
    else if (number.size() - i == 6)
    {

        // HUNDRED THOUSAND
        if (number[i] != '0')
        {
            cout << conversionScale[number[i] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Eleven twelve to Nineteen case
        if (number[i + 1] == '1')
        {
            cout << conversionScale[number[i + 1] - '0'][number[i + 2] - '0' + 1] << " ";
            cout << "Thousand ";
        }
        else if (number[i + 1] != '0')
        {
            // Twenty to Ninty
            cout << conversionScale[number[i + 1] - '0'][1] << " ";
            if (number[i + 2] == '0')
            {
                cout << "Thousand ";
            }
        }

        // Thousand
        if (number[i + 1] == '0' && number[i + 2] == '0')
        {
            cout << "Thousand ";
        }
        else if (number[i + 2] != '0' && number[i + 1] != '1')
        {
            cout << conversionScale[number[i + 2] - '0'][0] << " ";
            cout << "Thousand ";
        }

        // HUNDREDS
        if (number[i + 3] != '0')
        {
            cout << conversionScale[number[i + 3] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Tens

        if (number[i + 4] != '0')
        {
            cout << conversionScale[number[i + 4] - '0'][1] << " ";
        }

        // Ones

        if (number[i + 5] != '0')
        {
            cout << conversionScale[number[i + 5] - '0'][0] << " ";
        }
    }

    else if (number.size() - i == 5)
    {

        // Eleven twelve to Nineteen case
        if (number[i] == '1')
        {
            cout << conversionScale[number[i] - '0'][number[i + 1] - '0' + 1] << " ";
            cout << "Thousand ";
        }
        else if (number[i] != '0')
        {
            cout << conversionScale[number[i] - '0'][1] << " ";
            if (number[i + 1] == '0')
            {
                cout << "Thousand ";
            }
        }

        // Thousand
        if (number[i + 1] != '0' && number[i] >= '0')
        {
            cout << conversionScale[number[i + 1] - '0'][0] << " ";
            cout << "Thousand ";
        }

        // HUNDREDS
        if (number[i + 2] != '0')
        {
            cout << conversionScale[number[i + 2] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Tens

        if (number[i + 3] != '0')
        {
            cout << conversionScale[number[i + 3] - '0'][1] << " ";
        }

        // Ones

        if (number[i + 4] != '0')
        {
            cout << conversionScale[number[i + 4] - '0'][0] << " ";
        }
    }
    else if (number.size() - i == 4)
    {
        // Thousand
        if (number[i] != '0')
        {
            cout << conversionScale[number[i] - '0'][0] << " ";
            cout << "Thousand ";
        }

        // HUNDREDS
        if (number[i + 1] != '0')
        {
            cout << conversionScale[number[i + 1] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Tens

        if (number[i + 2] != '0')
        {
            cout << conversionScale[number[i + 2] - '0'][1] << " ";
        }

        // Ones

        if (number[i + 3] != '0')
        {
            cout << conversionScale[number[i + 3] - '0'][0] << " ";
        }
    }

    else if (number.size() - i == 3)
    {
        // HUNDREDS
        if (number[i] != '0')
        {
            cout << conversionScale[number[i] - '0'][0] << " ";
            cout << "Hundred ";
        }
        // Tens

        if (number[i + 1] != '0')
        {
            cout << conversionScale[number[i + 1] - '0'][1] << " ";
        }

        // Ones

        if (number[i + 2] != '0')
        {
            cout << conversionScale[number[i + 2] - '0'][0] << " ";
        }
    }

    else if (number.size() - i == 2)
    {

        // Tens

        if (number[i] != '0')
        {
            cout << conversionScale[number[i] - '0'][1] << " ";
        }

        // Ones

        if (number[i + 1] != '0')
        {
            cout << conversionScale[number[i + 1] - '0'][0] << " ";
        }
    }

    else if (number.size() - i == 1)
    {

        // Ones

        if (number[i] = '0')
        {
            cout << conversionScale[number[i] - '0'][0] << " ";
        }
    }
}

class Solution2
{
public:
    vector<pair<int, string>> numberToWordsMap = {
        {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

    string numberToWords(int num)
    {
        if (num == 0)
        {
            return "Zero";
        }

        for (auto &[value, word] : numberToWordsMap)
        {
            // Check if the number is greater than or equal to the current unit
            if (num >= value)
            {
                // Convert the quotient to words if the current unit is 100 or greater
                string prefix = (num >= 100) ? numberToWords(num / value) + " " : "";

                // Get the word for the current unit
                string unit = word;

                // Convert the remainder to words if it's not zero
                string suffix = (num % value == 0) ? "" : " " + numberToWords(num % value);

                return prefix + unit + suffix;
            }
        }

        return "";
    }
};

unordered_map<int, string> belowTen = {{0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};
unordered_map<int, string> belowTwenty = {{10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}};
unordered_map<int, string> belowHundred = {{1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}};

// 147483647

string findWord(int num)
{
    if (num < 10)
    {
        return belowTen[num];
    }

    if (num < 20)
    {
        return belowTwenty[num];
    }

    if (num < 100)
    {
        return belowHundred[num / 10] + ((num % 10 != 0) ? " " + belowTen[num % 10] : "");
    }
    if (num < 1000)
    { // 245
        return findWord(num / 100) + " Hundred" + ((num % 100 != 0) ? " " + findWord(num % 100) : "");
    }

    if (num < 1000000)
    {
        return findWord(num / 1000) + " Thousand" + ((num % 1000 != 0) ? " " + findWord(num % 1000) : "");
    }

    if (num < 1000000000)
    {
        return findWord(num / 1000000) + " Million" + ((num % 1000000 != 0) ? " " + findWord(num % 1000000) : "");
    }

    return findWord(num / 1000000000) + " Billion" + ((num % 1000000000 != 0) ? " " + findWord(num % 1000000000) : "");
}

string numberToWords3(int num)
{
    if (num == 0)
        return "Zero";
    return findWord(num);
}
int main()
{
    int num = 11000001;
    cout << numberToWords(num);
    return 0;
}