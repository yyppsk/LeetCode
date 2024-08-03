#include <bits/bits-stdc++.h>
using namespace std;
string truncateSentence(string input, int k)
{
    std::stringstream ss(input);
    vector<std::string> words;
    string word;
    string answer = "";
    while (k--)
    {
        ss >> word;
        answer += word;
        answer += " ";
    }

    return answer;
}
int main()
{
    string s = "Hello how are you Contestant";
    int k = 4;
    cout << truncateSentence(s, k) << "\n";
    s = "What is the solution to this problem";
    k = 4;
    cout << truncateSentence(s, k) << "\n";
    s = "chopper is not a tanuki";
    k = 5;
    cout << truncateSentence(s, k) << "\n";
    return 0;
}