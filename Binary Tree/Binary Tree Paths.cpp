#include <iostream>
#include <vector>
#include <string>
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
    void solve(TreeNode *root, vector<string> &ans, string s)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(s);
            return;
        }

        if (root->left != nullptr)
            solve(root->left, ans, s + "->" + to_string(root->left->val));
        if (root->right != nullptr)
            solve(root->right, ans, s + "->" + to_string(root->right->val));

        //this both if statements are very much required as if we do it directly
        //and check cond for return on top it got wrong as if left is NULL
        //it returns right part will not be performed and vice-versa

    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string a = to_string(root->val);
        solve(root, ans, a);
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << "Testing Binary Tree Paths:\n\n";

    // Test Case 1: Standard binary tree
    cout << "Test Case 1: Standard binary tree\n";
    cout << "Tree structure: 1, 2, -1, 5, -1, -1, 3, -1, -1\n";
    vector<int> preOrder1 = {1, 2, -1, 5, -1, -1, 3, -1, -1};
    int idx1 = 0;
    TreeNode *root1 = buildTree(preOrder1, idx1);
    vector<string> paths1 = sol.binaryTreePaths(root1);
    cout << "All root-to-leaf paths:\n";
    for (const string &path : paths1)
    {
        cout << path << "\n";
    }
    cout << "\n";

    // Test Case 2: Single node
    cout << "Test Case 2: Single node\n";
    cout << "Tree structure: 5, -1, -1\n";
    vector<int> preOrder2 = {5, -1, -1};
    int idx2 = 0;
    TreeNode *root2 = buildTree(preOrder2, idx2);
    vector<string> paths2 = sol.binaryTreePaths(root2);
    cout << "All root-to-leaf paths:\n";
    for (const string &path : paths2)
    {
        cout << path << "\n";
    }
    cout << "\n";

    // Test Case 3: Left skewed tree
    cout << "Test Case 3: Left skewed tree\n";
    cout << "Tree structure: 1, 2, 3, -1, -1, -1, -1\n";
    vector<int> preOrder3 = {1, 2, 3, -1, -1, -1, -1};
    int idx3 = 0;
    TreeNode *root3 = buildTree(preOrder3, idx3);
    vector<string> paths3 = sol.binaryTreePaths(root3);
    cout << "All root-to-leaf paths:\n";
    for (const string &path : paths3)
    {
        cout << path << "\n";
    }
    cout << "\n";

    // Test Case 4: Perfect binary tree
    cout << "Test Case 4: Perfect binary tree\n";
    cout << "Tree structure: 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1\n";
    vector<int> preOrder4 = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int idx4 = 0;
    TreeNode *root4 = buildTree(preOrder4, idx4);
    vector<string> paths4 = sol.binaryTreePaths(root4);
    cout << "All root-to-leaf paths:\n";
    for (const string &path : paths4)
    {
        cout << path << "\n";
    }
    cout << "\n";

    // Test Case 5: Right skewed tree
    cout << "Test Case 5: Right skewed tree\n";
    cout << "Tree structure: 1, -1, 2, -1, 3, -1, -1\n";
    vector<int> preOrder5 = {1, -1, 2, -1, 3, -1, -1};
    int idx5 = 0;
    TreeNode *root5 = buildTree(preOrder5, idx5);
    vector<string> paths5 = sol.binaryTreePaths(root5);
    cout << "All root-to-leaf paths:\n";
    for (const string &path : paths5)
    {
        cout << path << "\n";
    }
    cout << "\n";

    cout << "All test cases completed!\n";
    cout << "Note: Shows all paths from root to leaf nodes in string format.\n";

    return 0;
}