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

// Inorder print for verification
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

class Solution
{
public:
    TreeNode *helper(vector<int> &nums, int st, int end)
    {
        if (st > end)
            return NULL;
        int mid = (st + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = helper(nums, st, mid - 1);
        root->right = helper(nums, mid + 1, end);

        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};

int main()
{
    Solution sol;
    cout << "Testing Sorted Array to BST:\n============================\n\n";

    vector<vector<int>> tests = {
        {-10, -3, 0, 5, 9},    // Balanced BST
        {1, 3},                // Simple case
        {1, 2, 3, 4, 5, 6, 7}, // Larger array
        {5},                   // Single element
        {1, 2, 3, 4}           // Even length
    };

    vector<string> names = {"Standard array", "Two elements", "Seven elements", "Single element", "Even length"};

    for (int i = 0; i < tests.size(); i++)
    {
        TreeNode *root = sol.sortedArrayToBST(tests[i]);
        cout << "Test " << (i + 1) << " (" << names[i] << "):\n";
        cout << "Input:   [";
        for (int j = 0; j < tests[i].size(); j++)
        {
            cout << tests[i][j];
            if (j < tests[i].size() - 1)
                cout << ",";
        }
        cout << "]\nInorder: ";
        inorder(root);
        cout << "\n"
             << string(40, '-') << "\n\n";
    }

    cout << "✓ Creates height-balanced BST from sorted array\n";
    cout << "✓ Time: O(n), Space: O(log n) recursion stack\n";

    return 0;
}