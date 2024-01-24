#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

int pseudoPalindromicPaths(TreeNode *root)
{
    vector<int> treepath;
    int result = 0;
    pathFinder(root, treepath, result);
    return result;
}

void pathFinder(TreeNode *root, vector<int> treepath, int &result)
{
    if (root == nullptr)
    {
        return;
    }
    treepath.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr)
    {
        if (isPseudoPalindromic(treepath))
        {
            result++;
        }
        return;
    }

    pathFinder(root->left, treepath, result);
    pathFinder(root->right, treepath, result);
}

bool isPseudoPalindromic(const vector<int> &treepath)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < treepath.size(); i++)
    {
        freq[treepath[i]]++;
    }

    int oddFreqCount = 0;
    for (auto &ele : freq)
    {
        if (ele.second % 2 != 0)
        {
            oddFreqCount++;
        }
        if (oddFreqCount > 1)
        {
            return false;
        }
    }

    return true;
}

class Solution
{
public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        unordered_map<int, int> freq;
        int result = 0;
        pathFinder(root, freq, result);
        return result;
    }

private:
    void pathFinder(TreeNode *root, unordered_map<int, int> &freq, int &result)
    {
        if (root == nullptr)
        {
            return;
        }

        freq[root->val]++;
        // Check if it's a leaf node
        if (root->left == nullptr && root->right == nullptr)
        {
            if (isPseudoPalindromic(freq))
            {
                result++;
            }
        }

        pathFinder(root->left, freq, result);
        pathFinder(root->right, freq, result);
        freq[root->val]--; // Backtrack
    }

    bool isPseudoPalindromic(const unordered_map<int, int> &freq)
    {
        int oddFreqCount = 0;
        for (const auto &ele : freq)
        {
            if (ele.second % 2 != 0)
            {
                oddFreqCount++;
            }
            if (oddFreqCount > 1)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}