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

bool pathFind(TreeNode *lca, int target, string &path)
{
    if (lca == nullptr)
    {
        return false;
    }

    if (lca->val == target)
    {
        return true;
    }

    path.push_back('L');
    bool LeftPathExist = pathFind(lca->left, target, path);

    if (LeftPathExist)
    {
        return true;
    }

    path.pop_back();

    path.push_back('R');
    bool RightPathExist = pathFind(lca->right, target, path);

    if (RightPathExist)
    {
        return true;
    }

    path.pop_back();

    return false;
}

string getDirections(TreeNode *root, int startValue, int destValue)
{

    string rootToDest = "";
    string rootToSrc = "";

    pathFind(root, startValue, rootToSrc);
    pathFind(root, destValue, rootToDest);

    int ptr = 0;
    while (ptr < rootToSrc.length() && ptr < rootToDest.length() && rootToSrc[ptr] == rootToDest[ptr])
    {
        ptr++;
    }

    string result = "";

    for (int i = 0; i < rootToSrc.length() - ptr; i++)
    {
        result.push_back('U');
    }

    for (int i = ptr; i < rootToDest.length(); i++)
    {
        result.push_back(rootToDest[i]);
    }

    return result;
}

int main()
{
    return 0;
}