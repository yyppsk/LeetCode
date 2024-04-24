#include <bits/stdc++.h>
using namespace std;
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to construct the binary tree
TreeNode *constructTree()
{
    TreeNode *root = new TreeNode(0); // Root node
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    return root;
}

// Function to print the binary tree (pre-order traversal)
void printTree(TreeNode *root)
{
    if (!root)
        return;
    cout << char((root->val + 97)) << " ";
    printTree(root->left);

    printTree(root->right);
}

string sm = "~";

void find(TreeNode *root, string curr)
{
    if (!root)
        return;
    curr.push_back(char(root->val + 97));

    if (!root->left && !root->right)
    {
        string temp = curr;
        cout << curr << endl;
    }

    find(root->left, curr);
    find(root->right, curr);
}

string smallestFromLeaf(TreeNode *root)
{

    find(root, "");
    return "";
}
int main()
{
    TreeNode *root = constructTree();

    cout << "Constructed binary tree:" << endl;
    // printTree(root);
    smallestFromLeaf(root);
    cout << endl;

    return 0;
}