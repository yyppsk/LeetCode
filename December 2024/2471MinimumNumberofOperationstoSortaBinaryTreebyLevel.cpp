#include <bits/bits-stdc++.h>
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

int findSwaps(vector<int> &original)
{
    int n = original.size();
    vector<int> target = original;
    sort(target.begin(), target.end());

    unordered_map<int, int> OriginalPosition;

    for (int i = 0; i < n; i++)
    {
        OriginalPosition[original[i]] = i;
    }

    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        if (original[i] != target[i])
        {
            int position_Of_Target_In_Original = OriginalPosition[target[i]];
            OriginalPosition[original[i]] = position_Of_Target_In_Original; // og ko udhar le jana pdega
            swap(original[i], original[position_Of_Target_In_Original]);
            swaps += 1;
        }
    }

    return swaps;
}

int minimumOperations(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    int totalSwaps = 0;

    while (!q.empty())
    {
        int level = q.size();
        vector<int> currentLevel(level);

        for (int i = 0; i < level; i++)
        {
            auto current = q.front();
            q.pop();
            currentLevel[i] = current->val;
            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }

        totalSwaps += findSwaps(currentLevel);
    }

    return totalSwaps;
}

int main()
{
    return 0;
}