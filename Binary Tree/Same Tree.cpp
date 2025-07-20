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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if ((p != NULL && q == NULL) || q != NULL && p == NULL)
            return false;
        else if (p == NULL && q == NULL)
            return true;//or we can do it in one if statement
                        //if(p==NULL||q==NULL)return p==q;

        bool left = isSameTree(p->left, q->left) && (p->val == q->val);
        bool right = isSameTree(p->right, q->right) && (p->val == q->val);
        bool root = p->val == q->val;

        return left && right && root;
    }
};

int main()
{
    Solution sol;
    cout << "Testing Same Tree Comparison:\n\n";

    // Test Case 1: Identical trees
    cout << "Test Case 1: Identical trees\n";
    cout << "Tree 1: [1,2,3] and Tree 2: [1,2,3]\n";
    vector<int> preOrder1 = {1, 2, -1, -1, 3, -1, -1};
    vector<int> preOrder2 = {1, 2, -1, -1, 3, -1, -1};
    int idx1 = 0, idx2 = 0;
    TreeNode *tree1 = buildTree(preOrder1, idx1);
    TreeNode *tree2 = buildTree(preOrder2, idx2);
    cout << "Result: " << (sol.isSameTree(tree1, tree2) ? "Same" : "Different") << "\n\n";

    // Test Case 2: Different structure
    cout << "Test Case 2: Different structure\n";
    cout << "Tree 1: [1,2] and Tree 2: [1,-1,2]\n";
    vector<int> preOrder3 = {1, 2, -1, -1, -1};
    vector<int> preOrder4 = {1, -1, 2, -1, -1};
    int idx3 = 0, idx4 = 0;
    TreeNode *tree3 = buildTree(preOrder3, idx3);
    TreeNode *tree4 = buildTree(preOrder4, idx4);
    cout << "Result: " << (sol.isSameTree(tree3, tree4) ? "Same" : "Different") << "\n\n";

    // Test Case 3: Different values
    cout << "Test Case 3: Different values\n";
    cout << "Tree 1: [1,2,1] and Tree 2: [1,1,2]\n";
    vector<int> preOrder5 = {1, 2, -1, -1, 1, -1, -1};
    vector<int> preOrder6 = {1, 1, -1, -1, 2, -1, -1};
    int idx5 = 0, idx6 = 0;
    TreeNode *tree5 = buildTree(preOrder5, idx5);
    TreeNode *tree6 = buildTree(preOrder6, idx6);
    cout << "Result: " << (sol.isSameTree(tree5, tree6) ? "Same" : "Different") << "\n\n";

    // Test Case 4: Both null trees
    cout << "Test Case 4: Both null trees\n";
    cout << "Tree 1: null and Tree 2: null\n";
    cout << "Result: " << (sol.isSameTree(nullptr, nullptr) ? "Same" : "Different") << "\n\n";

    // Test Case 5: One null, one non-null
    cout << "Test Case 5: One null, one non-null\n";
    cout << "Tree 1: [1] and Tree 2: null\n";
    vector<int> preOrder7 = {1, -1, -1};
    int idx7 = 0;
    TreeNode *tree7 = buildTree(preOrder7, idx7);
    cout << "Result: " << (sol.isSameTree(tree7, nullptr) ? "Same" : "Different") << "\n\n";

    cout << "All test cases completed!\n";

    return 0;
}