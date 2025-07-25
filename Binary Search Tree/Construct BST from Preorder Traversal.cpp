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
    int idx = 0;
    TreeNode *helper(vector<int> &preorder, int min, int max)
    {
        if (idx >= preorder.size())
            return NULL;
        int val = preorder[idx]; // vvimp-1st val then root
        if (val <= min || val >= max)
            return NULL;

        idx++;
        TreeNode *root = new TreeNode(val); // vvimp-1st val then root

        root->left = helper(preorder, min, root->val);  // CAUTION:cant pass idx+1,as it will pass its copy and the whole order becomes untidy;
        root->right = helper(preorder, root->val, max); // CAUTION:cant pass idx+1,as it will pass its copy and the whole order becomes untidy;

        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return helper(preorder, INT_MIN, INT_MAX);
    }
};

int main()
{
    Solution sol;
    cout << "Testing BST from Preorder Traversal:\n===================================\n\n";

    vector<vector<int>> tests = {
        {8, 5, 1, 7, 10, 12}, // Standard BST
        {1, 3},               // Simple case
        {4, 2},               // Left child only
        {1, 2, 3},            // Right skewed
        {5}                   // Single node
    };

    vector<string> expected = {"[1,5,7,8,10,12]", "[1,3]", "[2,4]", "[1,2,3]", "[5]"};
    vector<string> names = {"Standard BST", "Simple case", "Left child", "Right skewed", "Single node"};

    for (int i = 0; i < tests.size(); i++)
    {
        sol.idx = 0; // Reset index for each test
        TreeNode *root = sol.bstFromPreorder(tests[i]);

        cout << "Test " << (i + 1) << " (" << names[i] << "):\n";
        cout << "Preorder: [";
        for (int j = 0; j < tests[i].size(); j++)
        {
            cout << tests[i][j];
            if (j < tests[i].size() - 1)
                cout << ",";
        }
        cout << "]\nInorder:  [";
        inorder(root);
        cout << "] (Expected: " << expected[i] << ")\n";
        cout << string(40, '-') << "\n\n";
    }

    cout << "✓ Uses range bounds to construct BST from preorder\n";
    cout << "✓ Time: O(n), Space: O(h) recursion stack\n";

    return 0;
}