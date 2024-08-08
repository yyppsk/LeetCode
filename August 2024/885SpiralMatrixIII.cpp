#include <bits/bits-stdc++.h>
using namespace std;

class SolutionNaive
{

public:
    set<pair<int, int>> vis;
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart, vector<vector<int>> &sp)
    {
        int currX = rStart, currY = cStart;
        int k = 1;
        vector<vector<int>> result;
        result.push_back({currX, currY});

        vis.erase({currX, currY});
        while (!vis.empty())
        {
            cout << "K";
            // std::cout << "Right \n";
            // right
            int steps = 1;
            while (steps <= k)
            {
                currY += 1;

                if (currX < rows && currY < cols && currX >= 0 && currY >= 0)
                {
                    // std::cout << currX << " " << currY << "\n";
                    result.push_back({currX, currY});
                    vis.erase({currX, currY});
                }
                steps += 1;
            }

            // std::cout << "Down \n";

            // Down
            steps = 1;
            while (steps <= k)
            {

                currX += 1;

                if (currX < rows && currY < cols && currX >= 0 && currY >= 0)
                {
                    // std::cout << currX << " " << currY << "\n";
                    result.push_back({currX, currY});
                    vis.erase({currX, currY});
                }
                steps += 1;
            }

            k++;

            // std::cout << "LEFT \n";

            // LEFT
            steps = 1;
            while (steps <= k)
            {

                currY -= 1;

                if (currX < rows && currY < cols && currX >= 0 && currY >= 0)
                {
                    // std::cout << currX << " " << currY << "\n";
                    result.push_back({currX, currY});
                    vis.erase({currX, currY});
                }
                steps += 1;
            }

            // std::cout << "UP \n";

            // UP
            steps = 1;
            while (steps <= k)
            {

                currX -= 1;

                if (currX < rows && currY < cols && currX >= 0 && currY >= 0)
                {
                    // std::cout << currX << " " << currY << "\n";
                    result.push_back({currX, currY});
                    vis.erase({currX, currY});
                }

                steps += 1;
            }

            k += 1;
        }

        return result;
    }
};

class SolutionBetter
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart)
    {
        vector<vector<int>> sp(rows, vector<int>(cols, 0));
        int currX = rStart, currY = cStart;
        int k = 1;
        int requiredPairs = rows * cols;
        vector<vector<int>> result;

        result.push_back({currX, currY});

        int pairCount = 1;
        while (pairCount != requiredPairs)
        {
            int steps = 1;
            while (steps <= k)
            {
                currY += 1;

                if (currX < rows && currY < cols && currX >= 0 && currY >= 0)
                {
                    result.push_back({currX, currY});
                    pairCount += 1;
                }
                steps += 1;
            }
            steps = 1;
            while (steps <= k)
            {

                currX += 1;

                if (currX < rows && currY < cols && currX >= 0 && currY >= 0)
                {

                    result.push_back({currX, currY});
                    pairCount += 1;
                }
                steps += 1;
            }

            k++;
            steps = 1;
            while (steps <= k)
            {

                currY -= 1;

                if (currX < rows && currY < cols && currX >= 0 && currY >= 0)
                {
                    result.push_back({currX, currY});
                    pairCount += 1;
                }
                steps += 1;
            }

            steps = 1;
            while (steps <= k)
            {

                currX -= 1;

                if (currX < rows && currY < cols && currX >= 0 && currY >= 0)
                {
                    result.push_back({currX, currY});
                    pairCount += 1;
                }

                steps += 1;
            }

            k += 1;
        }

        return result;
    }
};

// O(Rows∗Cols)
class SolutionOptimal
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart)
    {

        int currX = rStart, currY = cStart;
        int k = 1;
        int requiredPairs = rows * cols;

        vector<vector<int>> result;

        result.push_back({currX, currY});

        int pairCount = 1;

        while (pairCount != requiredPairs)
        {

            // Walk Right
            int steps = 1;

            while (steps <= k)
            {
                currY += 1;

                if (currX < rows && currY < cols && currX >= 0 && currY >= 0)
                {
                    result.push_back({currX, currY});
                    pairCount += 1;
                }

                steps += 1;
            }

            // Walk Down

            steps = 1;
            while (steps <= k)
            {

                currX += 1;

                if (currX < rows && currY < cols && currX >= 0 && currY >= 0)
                {

                    result.push_back({currX, currY});
                    pairCount += 1;
                }
                steps += 1;
            }

            // Walk left
            k++;
            steps = 1;
            while (steps <= k)
            {

                currY -= 1;

                if (currX < rows && currY < cols && currX >= 0 && currY >= 0)
                {
                    result.push_back({currX, currY});
                    pairCount += 1;
                }
                steps += 1;
            }

            // Walk Up
            steps = 1;
            while (steps <= k)
            {

                currX -= 1;

                if (currX < rows && currY < cols && currX >= 0 && currY >= 0)
                {
                    result.push_back({currX, currY});
                    pairCount += 1;
                }

                steps += 1;
            }

            k += 1;
        }

        return result;
    }
};
int main()
{
    const int minRange = 1, maxRange = 20;
    SolutionOptimal sol;
    sol.spiralMatrixIII(5, 6, 1, 4);

    return 0;
}