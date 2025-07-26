#include <iostream>
#include <vector>
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

// Create corrupted BST for testing
TreeNode *createCorruptedBST(int type)
{
    if (type == 1)
    { // Adjacent nodes swapped
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(3);  // Should be 2
        root->right = new TreeNode(2); // Should be 3
        return root;
    }
    if (type == 2)
    { // Non-adjacent nodes swapped
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(1);
        root->right = new TreeNode(4);
        root->right->left = new TreeNode(2); // Should be at left subtree somewhere
        return root;
    }
    return nullptr;
}

// Print inorder for verification
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
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = NULL;

    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        if (prev && prev->val > root->val)
        {
            if (first == NULL)
                first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        inorder(root);
        swap(first->val, second->val);
    }
};

int main()
{
    cout << "Testing Recover BST (Method 1 - Recursive Inorder):\n==================================================\n\n";

    vector<int> testTypes = {1, 2};
    vector<string> expected = {"[1,2,3]", "[1,2,3,4]"};
    vector<string> names = {"Adjacent swap", "Non-adjacent swap"};

    for (int i = 0; i < testTypes.size(); i++)
    {
        Solution sol; // Create new instance to reset pointers
        TreeNode *root = createCorruptedBST(testTypes[i]);

        cout << "Test " << (i + 1) << " (" << names[i] << "):\n";
        cout << "Before: ";
        printInorder(root);
        cout << "\n";

        sol.recoverTree(root);
        cout << "After:  ";
        printInorder(root);
        cout << " (Expected: " << expected[i] << ")\n";
        cout << string(40, '-') << "\n\n";
    }

    cout << "✓ Finds two swapped nodes using inorder traversal violation\n";
    cout << "✓ Time: O(n), Space: O(h) recursion stack\n";

    return 0;
}