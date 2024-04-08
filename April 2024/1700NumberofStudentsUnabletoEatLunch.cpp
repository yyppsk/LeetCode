#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int studentOne = 0, studentZero = 0;
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == 1)
            {
                studentOne++;
            }
            else
            {
                studentZero++;
            }
        }

        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (sandwiches[i] == 1)
            {
                if (studentOne > 0)
                {
                    studentOne--;
                }
                else
                    break;
            }
            else
            {
                if (studentZero > 0)
                {
                    studentZero--;
                }
                else
                    break;
            }
        }

        return studentOne + studentZero;
    }
};
int main()
{
    return 0;
}