#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if ((p != NULL && q == NULL) || q != NULL && p == NULL)
            return false;
        else if (p == NULL && q == NULL)
            return true;

        bool left = isSameTree(p->left, q->left) && (p->val == q->val);
        bool right = isSameTree(p->right, q->right) && (p->val == q->val);
        bool root = p->val == q->val;

        return left && right && root;
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL)
            return false;
        if (isSameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main()
{
    Solution sol;
    cout << "Testing Subtree Comparison:\n\n";

    // Test Case 1: Valid subtree
    cout << "Test Case 1: Valid subtree\n";
    cout << "Main tree: [3,4,5,1,2] and Subtree: [4,1,2]\n";
    vector<int> preOrder1 = {3, 4, 1, -1, -1, 2, -1, -1, 5, -1, -1};
    vector<int> preOrder2 = {4, 1, -1, -1, 2, -1, -1};
    int idx1 = 0, idx2 = 0;
    TreeNode *root1 = buildTree(preOrder1, idx1);
    TreeNode *subRoot1 = buildTree(preOrder2, idx2);
    cout << "Result: " << (sol.isSubtree(root1, subRoot1) ? "Is Subtree" : "Not Subtree") << "\n\n";

    // Test Case 2: Not a subtree (different structure)
    cout << "Test Case 2: Not a subtree (different structure)\n";
    cout << "Main tree: [3,4,5,1,2,null,null,null,null,0] and Subtree: [4,1,2]\n";
    vector<int> preOrder3 = {3, 4, 1, -1, -1, 2, 0, -1, -1, -1, 5, -1, -1};
    vector<int> preOrder4 = {4, 1, -1, -1, 2, -1, -1};
    int idx3 = 0, idx4 = 0;
    TreeNode *root2 = buildTree(preOrder3, idx3);
    TreeNode *subRoot2 = buildTree(preOrder4, idx4);
    cout << "Result: " << (sol.isSubtree(root2, subRoot2) ? "Is Subtree" : "Not Subtree") << "\n\n";

    // Test Case 3: Single node subtree
    cout << "Test Case 3: Single node subtree\n";
    cout << "Main tree: [1,2,3] and Subtree: [2]\n";
    vector<int> preOrder5 = {1, 2, -1, -1, 3, -1, -1};
    vector<int> preOrder6 = {2, -1, -1};
    int idx5 = 0, idx6 = 0;
    TreeNode *root3 = buildTree(preOrder5, idx5);
    TreeNode *subRoot3 = buildTree(preOrder6, idx6);
    cout << "Result: " << (sol.isSubtree(root3, subRoot3) ? "Is Subtree" : "Not Subtree") << "\n\n";

    // Test Case 4: Same trees
    cout << "Test Case 4: Same trees\n";
    cout << "Main tree: [1,2,3] and Subtree: [1,2,3]\n";
    vector<int> preOrder7 = {1, 2, -1, -1, 3, -1, -1};
    vector<int> preOrder8 = {1, 2, -1, -1, 3, -1, -1};
    int idx7 = 0, idx8 = 0;
    TreeNode *root4 = buildTree(preOrder7, idx7);
    TreeNode *subRoot4 = buildTree(preOrder8, idx8);
    cout << "Result: " << (sol.isSubtree(root4, subRoot4) ? "Is Subtree" : "Not Subtree") << "\n\n";

    // Test Case 5: Empty subtree in non-empty tree
    cout << "Test Case 5: Larger tree with subtree at leaf level\n";
    cout << "Main tree: [1,2,3,4,5] and Subtree: [5]\n";
    vector<int> preOrder9 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    vector<int> preOrder10 = {5, -1, -1};
    int idx9 = 0, idx10 = 0;
    TreeNode *root5 = buildTree(preOrder9, idx9);
    TreeNode *subRoot5 = buildTree(preOrder10, idx10);
    cout << "Result: " << (sol.isSubtree(root5, subRoot5) ? "Is Subtree" : "Not Subtree") << "\n\n";

    cout << "All test cases completed!\n";

    return 0;
}