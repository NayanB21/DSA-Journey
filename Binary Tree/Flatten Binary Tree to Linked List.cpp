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

// Tree builder without ternary
TreeNode *build(vector<int> &a, int i = 0)
{
    if (i >= a.size() || a[i] == -1)
        return nullptr;
    TreeNode *root = new TreeNode(a[i]);
    root->left = build(a, 2 * i + 1);
    root->right = build(a, 2 * i + 2);
    return root;
}

// Print flattened tree (right chain only)
void printFlattened(TreeNode *root)
{
    cout << "[";
    while (root)
    {
        cout << root->val;
        if (root->right)
            cout << ",";
        root = root->right;
    }
    cout << "]";
}

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            return;

        if (root->left != NULL)
            flatten(root->left);

        if (root->right != NULL)
            flatten(root->right);

        TreeNode *sLeft = root->left;
        TreeNode *sRight = root->right;
        TreeNode *helper = root->left;
        while (helper != NULL && helper->right != NULL)
            helper = helper->right; // helper!=NULL as on backtracking from right helper/root->left can be NULL

        if (root->left != NULL)
        {
            root->right = sLeft;
            root->left = NULL;
            if (helper != NULL)
            {
                helper->right = sRight;
                helper->left = NULL;
            }
        }
    }
};

int main()
{
    Solution sol;
    cout << "Testing Flatten Binary Tree to Linked List:\n==========================================\n\n";

    vector<vector<int>> tests = {
        {1, 2, 5, 3, 4, -1, 6}, // [1,2,3,4,5,6]
        {1, 2, 3},              // [1,2,3]
        {1},                    // [1]
        {1, 2, -1, 3},          // [1,2,3]
        {1, -1, 2, -1, -1, 3}   // [1,2,3]
    };

    vector<string> expected = {"[1,2,3,4,5,6]", "[1,2,3]", "[1]", "[1,2,3]", "[1,2,3]"};
    vector<string> names = {"Standard tree", "Simple tree", "Single node", "Left skewed", "Right skewed"};

    for (int i = 0; i < tests.size(); i++)
    {
        TreeNode *root = build(tests[i]);
        sol.flatten(root);

        cout << "Test " << (i + 1) << " (" << names[i] << "): ";
        printFlattened(root);
        cout << " (Expected: " << expected[i] << ")\n";
    }

    cout << "\n✓ Algorithm: Post-order traversal with right chain linking\n";
    cout << "✓ Flattens tree to right-skewed linked list in preorder sequence\n";

    return 0;
}