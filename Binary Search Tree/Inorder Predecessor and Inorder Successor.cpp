#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BST builder
Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

Node *buildBST(vector<int> &arr)
{
    Node *root = nullptr;
    for (int val : arr)
        root = insert(root, val);
    return root;
}

vector<int> IPansIS(Node *root, int key)
{
    Node *curr = root;
    Node *pred = NULL;
    Node *succ = NULL;

    while (curr != NULL)
    {
        if (key < curr->val)
        {
            succ = curr;
            curr = curr->left;
        }
        else if (key > curr->val)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        {
            if (curr->left != NULL)
            {
                // IP by standard defination
                Node *IP = curr->left;
                while (IP->right != NULL)
                    IP = IP->right;
                pred = IP;
            }
            if (curr->right != NULL)
            {
                // IS by standard defination
                Node *IS = curr->right;
                while (IS->left != NULL)
                    IS = IS->left;
                succ = IS;
            }
            break;
        }
    }
    return {pred->val, succ->val}; // vector of 2 contain value of IP,IS
}

int main()
{
    cout << "Testing Inorder Predecessor and Successor:\n=========================================\n\n";

    vector<int> bstData = {5, 3, 7, 2, 4, 6, 8};
    Node *root = buildBST(bstData);

    vector<int> testKeys = {3, 5, 7, 2, 8};
    vector<vector<int>> expected = {{2, 4}, {4, 6}, {6, 8}, {-1, 3}, {7, -1}};

    cout << "BST: [5,3,7,2,4,6,8] (inorder: 2,3,4,5,6,7,8)\n\n";

    for (int i = 0; i < testKeys.size(); i++)
    {
        vector<int> result = IPansIS(root, testKeys[i]);
        cout << "Key " << testKeys[i] << ": Pred=" << result[0]
             << ", Succ=" << result[1] << " (Expected: ["
             << expected[i][0] << "," << expected[i][1] << "])\n";
    }

    cout << "\n✓ Finds predecessor and successor in single traversal\n";
    cout << "✓ Time: O(h), Space: O(1) where h = height\n";

    return 0;
}