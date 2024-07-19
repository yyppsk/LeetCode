#include <bits/bits-stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;

        int maxLevel = 0;
        queue<Node *> bfsq;
        bfsq.push(root);

        while (!bfsq.empty())
        {
            int levelSize = bfsq.size();
            maxLevel++;

            for (int i = 0; i < levelSize; i++)
            {
                auto current = bfsq.front();

                bfsq.pop();
                for (const auto &neighbour : current->children)
                {
                    if (neighbour)
                        bfsq.push(neighbour);
                }
            }
        }
        return maxLevel;
    }
};
int main()
{
    return 0;
}