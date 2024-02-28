#include <bits/stdc++.h>
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
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> result;

        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty())
        {
            double sum = 0;
            int size = q.size();
            // processing current Level
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                sum += node->val;
            }

            result.push_back((double)sum / (double)size);
        }
        return result;
    }
};
int main()
{
    return 0;
}