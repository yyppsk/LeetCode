#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void findStuff(vector<string> &result, vector<string> &mappingStuff, string output, string digits, int index)
{
    // if index goes out of the bounds
    if (index >= digits.length())
    {
        result.push_back(output);
        return;
    }
    // include exclude stuff
    int digit = digits[index] - '0';
    string traversalStuff = mappingStuff[digit];
    for (int i = 0; i < traversalStuff.size(); i++)
    {
        char ch = traversalStuff[i];
        output.push_back(ch);
        findStuff(result, mappingStuff, output, digits, index + 1);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.size() <= 0)
        return {};
    vector<string> result;
    vector<string> mappingStuff = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    string output = "";
    findStuff(result, mappingStuff, output, digits, 0);
    return result;
}
int main()
{
    return 0;
}