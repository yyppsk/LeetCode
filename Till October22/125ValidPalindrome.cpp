#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <string>
using namespace std;
bool isPalindrome(string s)
{
    /*
    int front = 0;
    int end = s.size() - 1;
    while (front <= end)
    {
        // printf("Checker: %c is Alphabet(%d) Number(%d)\nChecker: %c is Alphabet(%d) Number(%d)\n", s[front], isalpha(s[front]), isdigit(s[front]), s[end], isalpha(s[end]), isdigit(s[end]));
        if ((isalpha(s[front]) || isdigit(s[front])) && (isalpha(s[end]) || isdigit(s[end])))
        {
            if (tolower(s[front]) != tolower(s[end]))
                return 0;
            printf("IF: Comparing %c with %c :\n", tolower(s[front]), tolower(s[end]));
            front++;
            end--;
        }
        else
        {
            printf("ELSE: Comparing %c with %c :\n", tolower(s[front]), tolower(s[end]));
            if (!isalpha(s[front]))
                front++;
            if (!isalpha(s[end]))
                end--;
        }
    }
    return 1;
    */
    int left = 0;
    int right = s.size() - 1;
    while (left < right)
    {
        if (!isalnum(s[left]))
            left++;
        else if (!isalnum(s[right]))
            right--;
        else if (tolower(s[left]) != tolower(s[right]))
            return false;
        else
        {
            left++;
            right--;
        }
    }
    return true;
}
int main()
{
    string s = "n,.,.,.,.,,..,..4124242i214141t14235423i.../../.N";
    string s2 = "8V8K;G;K;V;";
    cout << isPalindrome(s2);
    return 0;
}