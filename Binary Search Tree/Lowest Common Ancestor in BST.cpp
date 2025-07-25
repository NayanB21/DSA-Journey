#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BST builder
TreeNode *insert(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

TreeNode *buildBST(vector<int> &arr)
{
    TreeNode *root = nullptr;
    for (int val : arr)
        root = insert(root, val);
    return root;
}

// Find node with given value
TreeNode *findNode(TreeNode *root, int val)
{
    if (!root || root->val == val)
        return root;
    return (val < root->val) ? findNode(root->left, val) : findNode(root->right, val);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        else if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        else
        {
            return root;
        }
    }
};

int main()
{
    Solution sol;
    cout << "Testing Lowest Common Ancestor in BST:\n=====================================\n\n";

    vector<int> bstData = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    TreeNode *root = buildBST(bstData);

    vector<vector<int>> testPairs = {{2, 8}, {2, 4}, {0, 5}, {7, 9}};
    vector<int> expected = {6, 2, 2, 8};
    vector<string> names = {"Different subtrees", "Parent-child", "Cousins", "Same subtree"};

    cout << "BST: [6,2,8,0,4,7,9,3,5]\n\n";

    for (int i = 0; i < testPairs.size(); i++)
    {
        TreeNode *p = findNode(root, testPairs[i][0]);
        TreeNode *q = findNode(root, testPairs[i][1]);
        TreeNode *lca = sol.lowestCommonAncestor(root, p, q);

        cout << "LCA(" << testPairs[i][0] << "," << testPairs[i][1] << "): "
             << lca->val << " (Expected: " << expected[i] << ") - " << names[i] << "\n";
    }

    cout << "\n✓ Uses BST property: if p and q on different sides, root is LCA\n";
    cout << "✓ Time: O(h), Space: O(h) recursion where h = height\n";

    return 0;
}