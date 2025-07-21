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

void printPreorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(TreeNode *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

class Solution
{
public:
    int search(vector<int> &inorder, int left, int right, int val)
    {
        for (int i = left; i <= right; i++)
        {
            if (inorder[i] == val)
                return i;
        }
        return -1; // just to encounter syntax error
    }

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &preIdx, int left, int right)
    {
        if (left > right)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preIdx]);

        int inIdx = search(inorder, left, right, preorder[preIdx]);

        preIdx++; // we can make preIdx global var also,its way to avoid global var

        root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int preIdx = 0; // we can make preIdx global var also,its way to avoid global var
        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};

int main()
{
    Solution sol;
    cout << "Testing Binary Tree Construction from Preorder and Inorder:\n\n";

    // Test Case 1: Standard binary tree
    cout << "Test Case 1: Standard binary tree\n";
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    cout << "Input Preorder: ";
    for (int x : preorder1)
        cout << x << " ";
    cout << "\nInput Inorder:  ";
    for (int x : inorder1)
        cout << x << " ";
    TreeNode *root1 = sol.buildTree(preorder1, inorder1);
    cout << "\nBuilt Tree Preorder: ";
    printPreorder(root1);
    cout << "\nBuilt Tree Inorder:  ";
    printInorder(root1);
    cout << "\n\n";

    // Test Case 2: Single node
    cout << "Test Case 2: Single node\n";
    vector<int> preorder2 = {5};
    vector<int> inorder2 = {5};
    cout << "Input Preorder: ";
    for (int x : preorder2)
        cout << x << " ";
    cout << "\nInput Inorder:  ";
    for (int x : inorder2)
        cout << x << " ";
    TreeNode *root2 = sol.buildTree(preorder2, inorder2);
    cout << "\nBuilt Tree Preorder: ";
    printPreorder(root2);
    cout << "\nBuilt Tree Inorder:  ";
    printInorder(root2);
    cout << "\n\n";

    // Test Case 3: Left skewed tree
    cout << "Test Case 3: Left skewed tree\n";
    vector<int> preorder3 = {1, 2, 3};
    vector<int> inorder3 = {3, 2, 1};
    cout << "Input Preorder: ";
    for (int x : preorder3)
        cout << x << " ";
    cout << "\nInput Inorder:  ";
    for (int x : inorder3)
        cout << x << " ";
    TreeNode *root3 = sol.buildTree(preorder3, inorder3);
    cout << "\nBuilt Tree Preorder: ";
    printPreorder(root3);
    cout << "\nBuilt Tree Inorder:  ";
    printInorder(root3);
    cout << "\n\n";

    // Test Case 4: Right skewed tree
    cout << "Test Case 4: Right skewed tree\n";
    vector<int> preorder4 = {1, 2, 3};
    vector<int> inorder4 = {1, 2, 3};
    cout << "Input Preorder: ";
    for (int x : preorder4)
        cout << x << " ";
    cout << "\nInput Inorder:  ";
    for (int x : inorder4)
        cout << x << " ";
    TreeNode *root4 = sol.buildTree(preorder4, inorder4);
    cout << "\nBuilt Tree Preorder: ";
    printPreorder(root4);
    cout << "\nBuilt Tree Inorder:  ";
    printInorder(root4);
    cout << "\n\n";

    // Test Case 5: Larger balanced tree
    cout << "Test Case 5: Larger balanced tree\n";
    vector<int> preorder5 = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder5 = {4, 2, 5, 1, 6, 3, 7};
    cout << "Input Preorder: ";
    for (int x : preorder5)
        cout << x << " ";
    cout << "\nInput Inorder:  ";
    for (int x : inorder5)
        cout << x << " ";
    TreeNode *root5 = sol.buildTree(preorder5, inorder5);
    cout << "\nBuilt Tree Preorder: ";
    printPreorder(root5);
    cout << "\nBuilt Tree Inorder:  ";
    printInorder(root5);
    cout << "\n\n";

    cout << "All test cases completed!\n";
    cout << "Note: Tree construction uses preorder for root selection and inorder for left/right subtree division.\n";

    return 0;
}