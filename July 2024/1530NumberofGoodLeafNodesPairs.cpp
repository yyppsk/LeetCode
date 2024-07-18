#include <bits/bits-stdc++.h>
#include <unordered_set>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void makeGraph(TreeNode *current, TreeNode *prev, unordered_map<TreeNode *, vector<TreeNode *>> &graph, unordered_set<TreeNode *> &leafNodes)
{
    if (current == nullptr)
    {
        return;
    }

    if (current->left == nullptr && current->right)
    {
        leafNodes.insert(current);
    }

    if (prev)
    {
        graph[prev].push_back(current);
        graph[current].push_back(prev);
    }

    makeGraph(current->left, current, graph, leafNodes);
    makeGraph(current->right, current, graph, leafNodes);
}

int countPairs(TreeNode *root, int distance)
{
    unordered_map<TreeNode *, vector<TreeNode *>> graph;
    unordered_set<TreeNode *> leafNodes;

    makeGraph(root, nullptr, graph, leafNodes);

    int count = 0;

    for (const auto &leaf : leafNodes)
    {
        queue<TreeNode *> bfs;
        unordered_set<TreeNode *> seen;

        bfs.push(leaf);
        seen.insert(leaf);

        for (int level = 0; level <= distance; level++)
        {
            int size = bfs.size();

            for (int j = 0; j < size; j++)
            {
                TreeNode *current = bfs.front();
                bfs.pop();

                if (current != leaf && leafNodes.count(current))
                {
                    count++;
                }

                for (const auto &neighbour : graph[current])
                {
                    if (!seen.count(neighbour))
                    {
                        bfs.push(neighbour);
                        seen.insert(neighbour);
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    return 0;
}