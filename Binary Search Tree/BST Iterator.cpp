#include <iostream>
#include <stack>
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

class BSTIterator
{
public:
    stack<TreeNode *> s;
    void storeLeft(TreeNode *root)
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode *root)
    {
        storeLeft(root);
    }

    int next()
    {
        TreeNode *ans = s.top();
        s.pop();
        storeLeft(ans->right);
        return ans->val;
    }

    bool hasNext()
    {
        return s.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    cout << "Testing BST Iterator:\n====================\n\n";

    vector<int> bstData = {7, 3, 15, 9, 20};
    TreeNode *root = buildBST(bstData);

    BSTIterator *iterator = new BSTIterator(root);

    cout << "BST: [7,3,15,9,20]\n";
    cout << "Inorder traversal using iterator:\n";

    while (iterator->hasNext())
    {
        cout << iterator->next() << " ";
    }
    cout << "\nExpected: 3 7 9 15 20\n\n";

    cout << "✓ Implements controlled inorder traversal using stack\n";
    cout << "✓ Time: O(1) amortized for next(), Space: O(h) for stack\n";
    cout << "✓ Only stores path to leftmost unprocessed node\n";

    return 0;
}