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

// Minimal helper: create tree from level-order array
TreeNode *build(vector<int> &a, int i = 0)
{
    return (i >= a.size() || a[i] == -1) ? nullptr : new TreeNode(a[i], build(a, 2 * i + 1), build(a, 2 * i + 2));
}

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *curr = root;
        TreeNode *IP = root;

        // MORRIS INORDERED TRAVERSAL ALGORITHM
        // Based on Inorder Predecessor(IP):-IP of a node in a binary tree is the previous node in inorder traversal.

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                ans.push_back(curr->val); // insert
                curr = curr->right;       // backtracking with IP
            }

            else
            {

                // find IP of curr node
                IP = curr->left;
                while (IP->right != NULL && IP->right != curr)
                {
                    IP = IP->right;
                }

                if (IP->right == NULL)
                { // create THREAD;
                    IP->right = curr;
                    curr = curr->left;
                }
                else
                { // already THREAD is there(curr->right==curr),so delete it otherwise our original BT will get deformed;

                    IP->right = NULL;
                    ans.push_back(curr->val); // insert
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    cout << "Testing Morris Inorder Traversal:\n=================================\n\n";

    vector<vector<int>> tests = {
        {1, -1, 2, -1, -1, 3}, // [1,3,2]
        {1, 2, 3, 4, 5, 6, 7}, // [4,2,5,1,6,3,7]
        {1},                   // [1]
        {1, 2, -1, 3},         // [3,2,1]
        {1, -1, 2}             // [1,2]
    };

    vector<string> expected = {"[1,3,2]", "[4,2,5,1,6,3,7]", "[1]", "[3,2,1]", "[1,2]"};
    vector<string> names = {"Right skewed", "Complete tree", "Single node", "Left skewed", "Simple right"};

    for (int i = 0; i < tests.size(); i++)
    {
        TreeNode *root = build(tests[i]);
        vector<int> result = sol.inorderTraversal(root);

        cout << "Test " << (i + 1) << " (" << names[i] << "): [";
        for (int j = 0; j < result.size(); j++)
        {
            cout << result[j];
            if (j < result.size() - 1)
                cout << ",";
        }
        cout << "] (Expected: " << expected[i] << ")\n";
    }

    cout << "\n✓ Morris Algorithm: O(1) space, O(n) time using threading\n";
    cout << "✓ No recursion stack needed - uses inorder predecessor threading\n";

    return 0;
}