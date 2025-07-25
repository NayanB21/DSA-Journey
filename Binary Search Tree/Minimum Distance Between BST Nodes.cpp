#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
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

class Solution
{
public:
    void helper(TreeNode *root, int &ans, vector<int> &vec)
    { // It is highly prefered to use helper function than using global variables inside class
        if (root == NULL)
            return;

        helper(root->left, ans, vec);
        if (!vec.empty())
            ans = min(root->val - vec.back(), ans);

        vec.push_back(root->val);
        helper(root->right, ans, vec);
    }

    int minDiffInBST(TreeNode *root)
    {
        vector<int> vec;
        int ans = INT_MAX;
        helper(root, ans, vec);
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << "Testing Minimum Distance Between BST Nodes:\n==========================================\n\n";

    vector<vector<int>> tests = {
        {4, 2, 6, 1, 3},         // Min diff: 1
        {1, 3},                  // Min diff: 2
        {27, 34, 58, 4, 10, 24}, // Min diff: 6
        {90, 69, 49, 89, 52}     // Min diff: 1
    };

    vector<int> expected = {1, 2, 6, 1};
    vector<string> names = {"Standard BST", "Two nodes", "Larger BST", "Close values"};

    for (int i = 0; i < tests.size(); i++)
    {
        TreeNode *root = buildBST(tests[i]);
        int result = sol.minDiffInBST(root);
        cout << "Test " << (i + 1) << " (" << names[i] << "): "
             << result << " (Expected: " << expected[i] << ")\n";
    }

    cout << "\n✓ Uses inorder traversal to find min difference between adjacent nodes\n";
    cout << "✓ Time: O(n), Space: O(n) for vector + O(h) recursion\n";

    return 0;
}