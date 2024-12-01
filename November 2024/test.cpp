#include <bits/stdc++.h>
using namespace std;

// Mockup of the getResponse API for demonstration
enum Response
{
    HOTTER, // Moving closer to the target
    COLDER, // Moving farther from the target
    SAME,   // Same distance as before
    EXACT   // Target found
};

// Global variables to simulate the grid and store the target's location
vector<vector<char>> grid;
int targetRow, targetCol;
int prevRow = -1, prevCol = -1; // Previous position of the query

// Helper function to calculate Manhattan distance
int calculateDistance(int row, int col)
{
    return abs(row - targetRow) + abs(col - targetCol);
}

// Implementation of the getResponse API
Response getResponse(int row, int col)
{
    // Check for out-of-bounds
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
    {
        throw out_of_range("Out of bounds");
    }

    // Check if the target is found
    if (row == targetRow && col == targetCol)
    {
        return EXACT;
    }

    // Calculate the Manhattan distance from the target
    int currentDistance = calculateDistance(row, col);
    int previousDistance = prevRow == -1 ? INT_MAX : calculateDistance(prevRow, prevCol);

    // Update the previous position
    prevRow = row;
    prevCol = col;

    // Determine the response
    if (currentDistance < previousDistance)
    {
        return HOTTER;
    }
    else if (currentDistance > previousDistance)
    {
        return COLDER;
    }
    else
    {
        return SAME;
    }
}

// Function to find the boundaries and locate the target object
int getBoundary(bool isRow)
{
    int low = 0, high = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        try
        {
            getResponse(isRow ? mid : 0, isRow ? 0 : mid);
            low = mid + 1;
        }
        catch (const out_of_range &)
        {
            high = mid - 1;
        }
    }
    return high;
}

// OPTIMAL WAY
//  Function to find the row or column of the object
int findRowOrColumn(bool isRow, int start, int end)
{
    int low = start, high = end;
    getResponse(0, 0);
    while (low <= high)
    {
        Response res;
        int mid = low + (high - low) / 2;
        cout << "Low " << low << " : mid -- " << mid << " high -- " << high << "\n";
        if (isRow)
            res = getResponse(mid, 0);
        else
            res = getResponse(0, mid);

        switch (res)
        {
        case Response::EXACT:
        {
            cout << "EXACT \n";
            return low;
        }
        case Response::SAME:
        {
            cout << "SAME \n";
            int result;
            if (isRow)
            {
                cout << "IS ROW\n";

                if (getResponse(high, 0) == HOTTER || getResponse(high, 0) == EXACT)
                {
                    cout << "HIGH \n";
                    result = high;
                }
                else if (getResponse(mid, 0) == HOTTER || getResponse(mid, 0) == EXACT)
                {
                    cout << "MID \n";
                    result = mid;
                }
                else if (getResponse(low, 0) == HOTTER || getResponse(low, 0) == EXACT)
                {
                    cout << "LOW \n";
                    result = low;
                }
            }
            else
            {
                cout << "IS COL\n";

                if (getResponse(0, high) == HOTTER || getResponse(0, high) == EXACT)
                {
                    cout << "HIGH \n";
                    result = high;
                }
                else if (getResponse(0, mid) == HOTTER || getResponse(0, mid) == EXACT)
                {
                    cout << "MID \n";
                    result = mid;
                }
                else if (getResponse(0, low) == HOTTER || getResponse(0, low) == EXACT)
                {
                    cout << "LOW \n";
                    result = low;
                }
            }
            return result;
        }
        case Response::HOTTER:
        {

            cout << "HOTTER \n";
            low = mid;
            break;
        }
        case Response::COLDER:
        {

            cout << "COLDER \n";
            high = mid;
            break;
        }
        }
    }
    return -1;
}

vector<int> getObject()
{
    int n = getBoundary(true);
    int m = getBoundary(false);

    cout << n << " " << m << "\n";
    cout << "ROW \n";
    prevRow = -1; // Reset previous position for a new grid
    prevCol = -1;
    int objectRow = findRowOrColumn(true, 0, n);

    cout << "Col \n";
    prevRow = -1; // Reset previous position for a new grid
    prevCol = -1;
    int objectColumn = findRowOrColumn(false, 0, m);

    return {objectRow, objectColumn};
}

// BRUTE GET OBJECT
vector<int> getObject_brute()
{
    int n = getBoundary(true);
    int m = getBoundary(false);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (getResponse(i, j) == EXACT)
            {
                return {i, j};
            }
        }
    }

    return {};
}

// black box
int main()
{
    // Example 1
    grid = {
        {'o', 'o', 'o'},
        {'o', 'o', 'o'},
        {'x', 'o', 'o'}};

    targetRow = 2, targetCol = 0;

    vector<int> result = getObject();
    cout << "Target found at: [" << result[0] << ", " << result[1] << "]" << endl;

    // Example 2
    grid = {
        {'o', 'o', 'o', 'o', 'o'},
        {'o', 'o', 'o', 'o', 'o'},
        {'o', 'o', 'o', 'o', 'o'},
        {'o', 'o', 'o', 'o', 'o'},
        {'o', 'o', 'o', 'x', 'o'},
        {'o', 'o', 'o', 'o', 'o'}};
    targetRow = 0, targetCol = 3;

    prevRow = -1; // Reset previous position for a new grid
    prevCol = -1;

    result = getObject();
    cout << "Target found at: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
