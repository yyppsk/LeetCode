#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printTree(TreeNode *root)
{
    // pre
    if (root == nullptr)
        return;

    printTree(root->left);
    printTree(root->right);
    cout << root->val << " ";
}
void bfs(TreeNode *root, int val, int depth)
{
    queue<TreeNode *> q;
    q.push(root);
    int level = 1;

    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            auto current = q.front();
            q.pop();
            if (level == (depth - 1))
            {
                TreeNode *templeft = new TreeNode(val);
                templeft->left = current->left;
                current->left = templeft;

                TreeNode *tempright = new TreeNode(val);
                tempright->right = current->right;
                current->right = tempright;
            }
            cout << current->val << " ";
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
        level++;
        std::cout << "\n"; // Print a new line to indicate level change
    }
}
TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    if (depth == 1)
    {
        TreeNode *temp = new TreeNode(val);
        temp->left = root;
        root = temp;
    }
    bfs(root, val, depth);
    return root;
}

int main()
{
    // Creating nodes
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);

    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);

    // Printing the tree
    std::cout << "Tree Diagram:\n";
    addOneRow(root, 1, 2);

    // Cleaning up memory (not necessary in this example, but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
