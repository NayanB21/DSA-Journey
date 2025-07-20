#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &preOrder, int &idx)
{
    if (idx >= preOrder.size() || preOrder[idx] == -1)
    {
        idx++;
        return nullptr;
    }

    TreeNode *newNode = new TreeNode(preOrder[idx++]);
    newNode->left = buildTree(preOrder, idx);
    newNode->right = buildTree(preOrder, idx);

    return newNode;
}

TreeNode *findNode(TreeNode *root, int val)
{
    if (root == nullptr || root->val == val)
        return root;
    TreeNode *left = findNode(root->left, val);
    if (left)
        return left;
    return findNode(root->right, val);
}

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == NULL || root == p || root == q)
            return root;

        TreeNode *leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightLCA = lowestCommonAncestor(root->right, p, q);

        if (leftLCA != NULL && rightLCA != NULL)
            return root;
        else
            return leftLCA == NULL ? rightLCA : leftLCA;
    }
};

int main()
{
    Solution sol;
    cout << "Testing Lowest Common Ancestor of Binary Tree:\n\n";

    // Test Case 1: Standard binary tree
    cout << "Test Case 1: Standard binary tree\n";
    cout << "Tree structure: 3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1\n";
    vector<int> preOrder1 = {3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1};
    int idx1 = 0;
    TreeNode *root1 = buildTree(preOrder1, idx1);
    TreeNode *p1 = findNode(root1, 5);
    TreeNode *q1 = findNode(root1, 1);
    TreeNode *lca1 = sol.lowestCommonAncestor(root1, p1, q1);
    cout << "LCA of 5 and 1: " << (lca1 ? lca1->val : -1) << "\n\n";

    // Test Case 2: One node is ancestor of another
    cout << "Test Case 2: One node is ancestor of another\n";
    cout << "Tree structure: Same as above\n";
    TreeNode *p2 = findNode(root1, 5);
    TreeNode *q2 = findNode(root1, 4);
    TreeNode *lca2 = sol.lowestCommonAncestor(root1, p2, q2);
    cout << "LCA of 5 and 4: " << (lca2 ? lca2->val : -1) << "\n\n";

    // Test Case 3: Simple tree with close nodes
    cout << "Test Case 3: Simple tree\n";
    cout << "Tree structure: 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1\n";
    vector<int> preOrder3 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int idx3 = 0;
    TreeNode *root3 = buildTree(preOrder3, idx3);
    TreeNode *p3 = findNode(root3, 4);
    TreeNode *q3 = findNode(root3, 5);
    TreeNode *lca3 = sol.lowestCommonAncestor(root3, p3, q3);
    cout << "LCA of 4 and 5: " << (lca3 ? lca3->val : -1) << "\n\n";

    // Test Case 4: Left and right subtree nodes
    cout << "Test Case 4: Nodes in different subtrees\n";
    cout << "Tree structure: Same as Test Case 3\n";
    TreeNode *p4 = findNode(root3, 2);
    TreeNode *q4 = findNode(root3, 3);
    TreeNode *lca4 = sol.lowestCommonAncestor(root3, p4, q4);
    cout << "LCA of 2 and 3: " << (lca4 ? lca4->val : -1) << "\n\n";

    // Test Case 5: Single path tree
    cout << "Test Case 5: Single path tree\n";
    cout << "Tree structure: 1, 2, 3, -1, -1, -1, -1\n";
    vector<int> preOrder5 = {1, 2, 3, -1, -1, -1, -1};
    int idx5 = 0;
    TreeNode *root5 = buildTree(preOrder5, idx5);
    TreeNode *p5 = findNode(root5, 1);
    TreeNode *q5 = findNode(root5, 3);
    TreeNode *lca5 = sol.lowestCommonAncestor(root5, p5, q5);
    cout << "LCA of 1 and 3: " << (lca5 ? lca5->val : -1) << "\n\n";

    cout << "All test cases completed!\n";
    cout << "Note: LCA is the lowest node that has both p and q as descendants.\n";

    return 0;
}