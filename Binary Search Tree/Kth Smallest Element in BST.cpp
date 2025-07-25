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
    void helper(TreeNode *root, int k, int &ans, vector<int> &vec)
    {
        if (root == NULL)
            return;

        helper(root->left, k, ans, vec);
        vec.push_back(root->val);
        if (vec.size() == k)
            ans = vec[k - 1];

        helper(root->right, k, ans, vec);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> vec;
        int ans;
        helper(root, k, ans, vec);
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << "Testing Kth Smallest Element in BST:\n===================================\n\n";

    vector<int> bstData = {3, 1, 4, 2};
    TreeNode *root = buildBST(bstData);

    vector<int> kValues = {1, 2, 3, 4};
    vector<int> expected = {1, 2, 3, 4};

    cout << "BST: [3,1,4,2] (inorder: 1,2,3,4)\n\n";

    for (int i = 0; i < kValues.size(); i++)
    {
        int result = sol.kthSmallest(root, kValues[i]);
        cout << "k=" << kValues[i] << ": " << result
             << " (Expected: " << expected[i] << ")\n";
    }

    cout << "\n✓ Uses inorder traversal to find kth smallest element\n";
    cout << "✓ Time: O(n), Space: O(n) for vector + O(h) recursion\n";

    return 0;
}