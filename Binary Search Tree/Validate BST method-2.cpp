#include <iostream>
#include <vector>
#include <climits>
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
    { // Edge case with INT_MIN
        TreeNode *root = new TreeNode(INT_MIN);
        return root;
    }
    return nullptr;
}

class Solution
{
public:
    bool helper(TreeNode *root, long long min, long long max)
    { // imp
        if (root == NULL)
            return true;
        if (root->val <= min || root->val >= max)
            return false;
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }

    bool isValidBST(TreeNode *root)
    {
        return helper(root, LLONG_MIN, LLONG_MAX); // imp
    }
};

int main()
{
    Solution sol;
    cout << "Testing BST Validation (Method 2 - Range):\n=========================================\n\n";

    vector<int> testTypes = {1, 2, 3};
    vector<bool> expected = {true, false, true};
    vector<string> names = {"Valid BST", "Invalid BST", "Edge case INT_MIN"};

    for (int i = 0; i < testTypes.size(); i++)
    {
        TreeNode *root = buildTree(testTypes[i]);
        bool result = sol.isValidBST(root);
        cout << "Test " << (i + 1) << " (" << names[i] << "): "
             << (result ? "Valid" : "Invalid")
             << " (Expected: " << (expected[i] ? "Valid" : "Invalid") << ")\n";
    }

    cout << "\n✓ Method 2: Uses range bounds (min, max) for validation\n";
    cout << "✓ Time: O(n), Space: O(h) recursion stack only\n";
    cout << "✓ More space efficient than inorder method\n";

    return 0;
}