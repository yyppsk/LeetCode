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
class Solution
{
public:
    TreeNode *balancer(int left, int right, vector<int> &traversal)
    {
        if (left > right)
        {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(traversal[mid]);

        root->left = balancer(left, mid - 1, traversal);
        root->right = balancer(mid + 1, right, traversal);

        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &traversal)
    {
        return balancer(0, traversal.size() - 1, traversal);
    }
};
int main()
{
    return 0;
}