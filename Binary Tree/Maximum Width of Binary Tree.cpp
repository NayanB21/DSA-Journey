#include <iostream>
#include <queue>
#include <algorithm>
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

// General function to create tree from array (uses -1 for null)
TreeNode *createTree(vector<int> &arr, int i = 0)
{
    if (i >= arr.size() || arr[i] == -1)
        return nullptr;
    TreeNode *root = new TreeNode(arr[i]);
    root->left = createTree(arr, 2 * i + 1);
    root->right = createTree(arr, 2 * i + 2);
    return root;
}

// Simple recursive inorder print
void printTree(TreeNode *root)
{
    if (!root)
        return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int ans = 1;
        unsigned long long temp = 1;
        queue<pair<TreeNode *, unsigned long long>> q; // we cant do q.push_back() but can do q.back(),yesssss!!!!
        q.push({root, 0});

        while (!q.empty())
        {
            temp = q.back().second - q.front().second + 1;
            ans = max(ans, (int)temp);

            int n = q.size();
            for (int i = 0; i < n; i++)
            {

                pair<TreeNode *, unsigned long long> curr = q.front();
                q.pop();

                if (curr.first->left != NULL)
                    q.push({curr.first->left, 2 * curr.second + 1});
                if (curr.first->right != NULL)
                    q.push({curr.first->right, 2 * curr.second + 2});
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    cout << "Testing Maximum Width of Binary Tree:\n";
    cout << "====================================\n\n";

    // Test Case 1: Standard binary tree
    cout << "Test Case 1: Standard binary tree\n";
    cout << "Tree structure:\n    1\n   / \\\n  3   2\n / \\   \\\n5   3   9\n";
    vector<int> nodes1 = {1, 3, 2, 5, 3, -1, 9};
    TreeNode *root1 = createTree(nodes1);
    cout << "Inorder: ";
    printTree(root1);
    cout << endl;
    cout << "Maximum width: " << sol.widthOfBinaryTree(root1) << " (Expected: 4)\n";
    cout << string(50, '-') << "\n\n";

    // Test Case 2: Single node
    cout << "Test Case 2: Single node\n";
    cout << "Tree structure: 1\n";
    vector<int> nodes2 = {1};
    TreeNode *root2 = createTree(nodes2);
    cout << "Inorder: ";
    printTree(root2);
    cout << endl;
    cout << "Maximum width: " << sol.widthOfBinaryTree(root2) << " (Expected: 1)\n";
    cout << string(50, '-') << "\n\n";

    // Test Case 3: Left skewed tree
    cout << "Test Case 3: Left skewed tree\n";
    cout << "Tree structure:\n1\n/\n2\n/\n3\n";
    vector<int> nodes3 = {1, 2, -1, 3};
    TreeNode *root3 = createTree(nodes3);
    cout << "Inorder: ";
    printTree(root3);
    cout << endl;
    cout << "Maximum width: " << sol.widthOfBinaryTree(root3) << " (Expected: 1)\n";
    cout << string(50, '-') << "\n\n";

    // Test Case 4: Tree with large gaps
    cout << "Test Case 4: Tree with large gaps\n";
    cout << "Tree structure:\n    1\n   / \\\n  3   2\n /     \\\n5       9\n       /\n      6\n";
    vector<int> nodes4 = {1, 3, 2, 5, -1, -1, 9, -1, -1, -1, -1, -1, -1, 6};
    TreeNode *root4 = createTree(nodes4);
    cout << "Inorder: ";
    printTree(root4);
    cout << endl;
    cout << "Maximum width: " << sol.widthOfBinaryTree(root4) << " (Expected: 8)\n";
    cout << string(50, '-') << "\n\n";

    // Test Case 5: Complete binary tree
    cout << "Test Case 5: Complete binary tree\n";
    cout << "Tree structure:\n      1\n    /   \\\n   2     3\n  / \\   / \\\n 4   5 6   7\n";
    vector<int> nodes5 = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root5 = createTree(nodes5);
    cout << "Inorder: ";
    printTree(root5);
    cout << endl;
    cout << "Maximum width: " << sol.widthOfBinaryTree(root5) << " (Expected: 4)\n";
    cout << string(50, '-') << "\n\n";

    cout << "All test cases completed!\n";
    cout << "✓ Algorithm: Level-order traversal with node indexing\n";
    cout << "✓ Width = rightmost_index - leftmost_index + 1 at each level\n";
    cout << "✓ Time Complexity: O(n), Space Complexity: O(w) where w is max width\n";
    cout << "✓ Uses unsigned long long to handle large indices and prevent overflow\n";
