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

void pathFinder(TreeNode *root, string curr, vector<string> &result)
{
    if (!root)
    {
        return;
    }
    int number = root->val;
    if (number >= 0 && number <= 9)
    {

        curr.push_back((root->val + '0'));
        curr += "->";
        cout << curr << " \n";
    }
    else
    {
        string str = to_string(number);
        curr += str;
        curr += "->";
    }

    if (!root->left && !root->right)
    {
        curr.pop_back();
        curr.pop_back();
        result.push_back(curr);
    }

    pathFinder(root->left, curr, result);
    pathFinder(root->right, curr, result);
    curr.pop_back();
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> result;
    pathFinder(root, "", result);
    return result;
}

int main()
{
    return 0;
}