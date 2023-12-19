#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> imageSmoother(vector<vector<int>> &img)
{
    vector<pair<int, int>> delta = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int n = img.size();
    int m = img[0].size();
    vector<vector<int>> result(n, vector<int>(m, 0));
    for (int i = 0; i < img.size(); i++)
    {
        for (int j = 0; j < img[0].size(); j++)
        {
            int currsum = 0, count = 0;
            // cout << "currsum = ";
            for (auto &pair : delta)
            {
                int row = pair.first + i;
                int col = pair.second + j;
                // cout << "(" << row << "," << s << ")" << endl;
                if (row >= 0 && col >= 0 && row < n && col < m)
                {
                    currsum += img[row][col];
                    count++;
                    // cout << img[row][col] << "+"   << " ";
                }
            }
            // cout << " = " << currsum << endl;
            //  cout << "This one's : " << floor(currsum / count) << endl;
            result[i][j] = floor(currsum / count);
        }
    }
    // for (int i = 0; i < img.size(); i++)
    // {
    //     for (int j = 0; j < img[0].size(); j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return result;
}
int main()
{
    vector<vector<int>> img = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
    imageSmoother(img);
    return 0;
}