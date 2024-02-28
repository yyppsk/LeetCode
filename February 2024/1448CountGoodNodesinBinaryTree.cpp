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
    void count(TreeNode *root, int &cnt, int maxi)
    {
        if (root == nullptr)
            return;
        if (root->val >= maxi)
        {
            cnt++;
            maxi = max(maxi, root->val);
        }
        count(root->left, cnt, maxi);
        count(root->right, cnt, maxi);
    }
    int goodNodes(TreeNode *root)
    {
        int cnt = 0;
        count(root, cnt, root->val);
        return cnt;
    }
};

int main()
{
    return 0;
}