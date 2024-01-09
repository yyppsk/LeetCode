#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
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
    int result = 0;
    pair<int, int> iterative(TreeNode *root)
    {
        if (!root)
        {
            return {0, 0};
        }
        pair<int, int> left = iterative(root->left);
        pair<int, int> right = iterative(root->right);
        int totalSum = left.first + right.first + root->val;
        int totalCount = left.second + right.second + 1;
        int avg = totalCount / totalCount;
        if (avg == root->val)
        {
            result++;
        }
        return {totalSum, totalCount};
    }
    void preorder(TreeNode *root, vector<TreeNode *> &traversal)
    {
        if (root == nullptr)
        {
            return;
        }
        traversal.push_back(root);
        preorder(root->left, traversal);
        preorder(root->right, traversal);
    }
    void postorder(TreeNode *root, int &count, int &sum)
    {
        if (root == nullptr)
        {
            return;
        }
        postorder(root->left, count, sum);
        postorder(root->right, count, sum);
        sum += root->val;
        count++;
    }
    int averageOfSubtree(TreeNode *root)
    {
        int mainsum = 0;
        vector<TreeNode *> traversal;
        preorder(root, traversal);

        for (auto &node : traversal)
        {
            int count = 0, sum = 0;
            postorder(node, count, sum);
            if (node->val == (sum / count))
                mainsum++;
        }
        return mainsum;
    }
};
int main()
{
    return 0;
}