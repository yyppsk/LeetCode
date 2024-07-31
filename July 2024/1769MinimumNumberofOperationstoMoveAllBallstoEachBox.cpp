#include <bits/bits-stdc++.h>
using namespace std;

vector<int> minOperations(string boxes)
{
    vector<int> positions;
    vector<int> result(boxes.size());
    for (int i = 0; i < boxes.size(); i++)
    {
        if (boxes[i] == '1')
        {
            positions.push_back(i);
        }
    }

    for (int i = 0; i < boxes.length(); i++)
    {
        int totalOperationsForI = 0;
        for (int j = 0; j < positions.size(); j++)
        {
            totalOperationsForI += abs(positions[j] - i);
        }

        result[i] = totalOperationsForI;
    }

    return result;
}

int main()
{
    string boxes = "110";
    minOperations(boxes);
    return 0;
}