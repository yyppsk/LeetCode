#include <bits/bits-stdc++.h>
using namespace std;

std::string intToBinary(int num)
{
    std::string binary = "";
    for (int i = 31; i >= 0; i--)
    {
        binary += (num & (1 << i)) ? '1' : '0';
    }
    size_t pos = binary.find_first_not_of('0');
    return (pos == std::string::npos) ? "0" : binary.substr(pos);
}
string convertDateToBinary(string date)
{
    std::stringstream obj(date);
    std::string pointer;
    string result = "";
    while (std::getline(obj, pointer, '-'))
    {
        result += intToBinary(stoi(pointer));
        result += "-";
    }
    result.pop_back();
    return result;
}
int main()
{
    convertDateToBinary("2080-02-29");
    return 0;
}