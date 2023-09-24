#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    // () parenthesis
    // [] square
    // {} curly braces
    vector<int> students(5, 15); // Initializer array type
    vector<vector<int>> students2D =
        {
            // 0  1  2  3
            // c1 c2 c3 c4
            {1, 2, 3, 4}, // r1 0
            {1, 2, 4, 9}, // r2 1
            {1, 2, 4, 5}, // r3 2
            {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    int row = students2D.size(); // 3
    // students2D[0][0] = 1
    // students2D[1][2] = 4
    // students2D[2][0] = 1
    // students2D[1][3] = 9

    // how to init a 2d vector using predefined values
    // initial value
    vector<vector<int>> predefinedValues(5, vector<int>(5));
    int value = 0;
    for (int i = 0; i < predefinedValues.size(); i++)
    {
        for (int j = 0; j < predefinedValues[i].size(); j++)
        {
            predefinedValues[i][j] = ++value;
            cout << predefinedValues[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}