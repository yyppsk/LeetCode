#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
class Solution
{
public:
    void pre(Node *root, vector<int> &result)
    {
        if (root == nullptr)
            return;
        result.push_back(root->val);

        for (auto child : root->children)
        {
            pre(child, result);
        }
    }
    vector<int> preorder(Node *root)
    {
        vector<int> result;
        pre(root, result);
        return result;
    }
};
int main()
{
    return 0;
}