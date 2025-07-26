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
    void recoverTree(TreeNode *root)
    {
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        TreeNode *prev = NULL;
        TreeNode *curr = root;

        while (curr != NULL)
        { // as it goes upto extreme right(=last element of inorder).

            if (curr->left == NULL)
            { // base-case where now we have to go right(if right exists its ok if not its backtracking!!!)

                if (prev && prev->val > curr->val)
                { // root-work
                    if (first == NULL)
                        first = prev;
                    second = curr;
                }

                prev = curr;
                curr = curr->right; // backtrack
            }

            else
            {
                // first of all find IP
                TreeNode *IP = curr->left;
                while (IP->right != NULL && IP->right != curr)
                    IP = IP->right; // vvimp

                if (IP->right == NULL)
                { // create thread
                    IP->right = curr;
                    curr = curr->left;
                }
                else
                { // root-work and thread delete
                    if (prev && prev->val > curr->val)
                    { // root-work
                        if (first == NULL)
                            first = prev;
                        second = curr;
                    }

                    prev = curr;
                    IP->right = NULL; // delete thread to maintain structure of BST
                                      // vvimp(you can delete thread firstly and then do backtrack like this bcz this thread is already used one as you came up by that thread only and now find IP (to go down) as that thead only)
                    curr = curr->right; // backtrack
                }
            }
        }

        swap(first->val, second->val);
    }
};

int main()
{
    cout << "Testing Recover BST (Method 2 - Morris Inorder):\n===============================================\n\n";

    vector<int> testTypes = {1, 2};
    vector<string> expected = {"[1,2,3]", "[1,2,3,4]"};
    vector<string> names = {"Adjacent swap", "Non-adjacent swap"};

    for (int i = 0; i < testTypes.size(); i++)
    {
        Solution sol;
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

    cout << "✓ Morris Algorithm: O(1) space complexity using threading\n";
    cout << "✓ Time: O(n), Space: O(1) - no recursion stack needed\n";

    return 0;
}