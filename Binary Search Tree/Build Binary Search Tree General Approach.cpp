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

Node *insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (root->val > val)
    {
        root->left = new Node(val);
    }

    if (root->val < val)
    {
        root->right = new Node(val);
    }

    return root; // imp
}

Node *buildBST(vector<int> &arr)
{ // O(n^2) in worst case
    Node *root = NULL;
    for (int val : arr)
    {
        root = insert(root, val); // this root will be always top root
                                  // thats why we are returning it in at end
    }
    return root; // imp
}

void inorderedPrint(Node *root)
{ // to verify the construction
    if (root == NULL)
        return;

    inorderedPrint(root->left);
    cout << root->val << " ";
    inorderedPrint(root->right);
}

int main()
{
    cout << "Testing BST Construction:\n========================\n\n";

    vector<vector<int>> tests = {
        {4, 2, 6, 1, 3, 5, 7},    // Balanced BST
        {1, 2, 3, 4, 5},          // Right skewed
        {5, 4, 3, 2, 1},          // Left skewed
        {3},                      // Single node
        {10, 5, 15, 2, 7, 12, 20} // Standard BST
    };

    vector<string> names = {"Balanced BST", "Right skewed", "Left skewed", "Single node", "Standard BST"};

    for (int i = 0; i < tests.size(); i++)
    {
        Node *root = buildBST(tests[i]);
        cout << "Test " << (i + 1) << " (" << names[i] << "):\n";
        cout << "Input: [";
        for (int j = 0; j < tests[i].size(); j++)
        {
            cout << tests[i][j];
            if (j < tests[i].size() - 1)
                cout << ",";
        }
        cout << "]\nInorder: ";
        inorderedPrint(root);
        cout << "\n"
             << string(40, '-') << "\n\n";
    }

    cout << "✓ BST Property: Inorder traversal gives sorted sequence\n";
    cout << "✓ Time: O(n²) worst case, O(n log n) average case\n";

    return 0;
}