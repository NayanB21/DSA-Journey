#include <iostream>
#include <vector>
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

// Manual tree builder for test cases
TreeNode *buildTree(int type)
{
    if (type == 1)
    { // Valid BST
        TreeNode *root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(4);
        root->right->left = new TreeNode(7);
        root->right->right = new TreeNode(9);
        return root;
    }
    if (type == 2)
    { // Invalid BST
        TreeNode *root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->right = new TreeNode(8);
        root->right->left = new TreeNode(4); // 4 < 5, invalid
        return root;
    }
    if (type == 3)
    { // Single node
        return new TreeNode(1);
    }
    if (type == 4)
    { // Duplicate values
        TreeNode *root = new TreeNode(2);
        root->left = new TreeNode(2);
        return root;
    }
    return nullptr;
}

class Solution
{
public:
    void inorderedTraversal(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;

        inorderedTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderedTraversal(root->right, inorder);
    }

    bool isValidBST(TreeNode *root)
    {
        vector<int> inorder;
        inorderedTraversal(root, inorder);

        // checking for strictly increasing order
        int n = inorder.size();
        for (int i = 1; i < n; i++)
        {
            if (inorder[i] <= inorder[i - 1])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    cout << "Testing BST Validation (Method 1 - Inorder):\n===========================================\n\n";

    vector<int> testTypes = {1, 2, 3, 4};
    vector<bool> expected = {true, false, true, false};
    vector<string> names = {"Valid BST", "Invalid BST", "Single node", "Duplicate values"};

    for (int i = 0; i < testTypes.size(); i++)
    {
        TreeNode *root = buildTree(testTypes[i]);
        bool result = sol.isValidBST(root);
        cout << "Test " << (i + 1) << " (" << names[i] << "): "
             << (result ? "Valid" : "Invalid")
             << " (Expected: " << (expected[i] ? "Valid" : "Invalid") << ")\n";
    }

    cout << "\n✓ Method 1: Uses inorder traversal + strictly increasing check\n";
    cout << "✓ Time: O(n), Space: O(n) for inorder array + O(h) recursion\n";

    return 0;
}