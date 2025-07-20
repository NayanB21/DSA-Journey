#include <iostream>
#include <vector>
#include <algorithm>
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
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        return max(height(root->left), height(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int a = height(root->left) + height(root->right);
        int b = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(a, b);
    }
};

int main()
{
    Solution sol;
    cout << "Testing Diameter of Binary Tree (Method 1):\n\n";

    // Test Case 1: Simple tree [1,2,3,4,5]
    cout << "Test Case 1: Tree [1,2,3,4,5]\n";
    cout << "Tree structure: 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1\n";
    vector<int> preOrder1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int idx1 = 0;
    TreeNode *root1 = buildTree(preOrder1, idx1);
    cout << "Diameter: " << sol.diameterOfBinaryTree(root1) << "\n\n";

    // Test Case 2: Single node
    cout << "Test Case 2: Single node [1]\n";
    vector<int> preOrder2 = {1, -1, -1};
    int idx2 = 0;
    TreeNode *root2 = buildTree(preOrder2, idx2);
    cout << "Diameter: " << sol.diameterOfBinaryTree(root2) << "\n\n";

    // Test Case 3: Left skewed tree
    cout << "Test Case 3: Left skewed tree [1,2,3,4]\n";
    vector<int> preOrder3 = {1, 2, 3, 4, -1, -1, -1, -1, -1};
    int idx3 = 0;
    TreeNode *root3 = buildTree(preOrder3, idx3);
    cout << "Diameter: " << sol.diameterOfBinaryTree(root3) << "\n\n";

    // Test Case 4: Right skewed tree
    cout << "Test Case 4: Right skewed tree [1,null,2,null,3,null,4]\n";
    vector<int> preOrder4 = {1, -1, 2, -1, 3, -1, 4, -1, -1};
    int idx4 = 0;
    TreeNode *root4 = buildTree(preOrder4, idx4);
    cout << "Diameter: " << sol.diameterOfBinaryTree(root4) << "\n\n";

    // Test Case 5: Balanced tree with larger diameter
    cout << "Test Case 5: Balanced tree [1,2,3,4,5,6,7]\n";
    vector<int> preOrder5 = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int idx5 = 0;
    TreeNode *root5 = buildTree(preOrder5, idx5);
    cout << "Diameter: " << sol.diameterOfBinaryTree(root5) << "\n\n";

    cout << "All test cases completed!\n";
    cout << "Note: This is O(n²) method. Diameter = longest path between any two nodes.\n";

    return 0;
}