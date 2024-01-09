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
    void traverse(Node *root, vector<int> &vc)
    {
        if (root == NULL)
            return;
        for (auto x : root->children)
        {
            traverse(x, vc);
        }
        vc.push_back(root->val);
    }
    vector<int> postorder(Node *root)
    {
        if (root == NULL)
            return {};
        vector<int> vc;
        traverse(root, vc);
        return vc;
    }
};
int main()
{
    return 0;
}