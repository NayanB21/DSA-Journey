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

// Simple BST builder
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

bool search(Node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->val == key)
        return true;

    if (root->val > key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main()
{
    cout << "Testing BST Search:\n==================\n\n";

    vector<int> bstData = {4, 2, 6, 1, 3, 5, 7};
    Node *root = buildBST(bstData);

    vector<int> searchKeys = {3, 8, 1, 10, 6, 0, 4};
    vector<bool> expected = {true, false, true, false, true, false, true};

    cout << "BST: [4,2,6,1,3,5,7]\n\n";

    for (int i = 0; i < searchKeys.size(); i++)
    {
        bool result = search(root, searchKeys[i]);
        cout << "Search " << searchKeys[i] << ": " << (result ? "Found" : "Not Found")
             << " (Expected: " << (expected[i] ? "Found" : "Not Found") << ")\n";
    }

    cout << "\n✓ Time: O(log n) average, O(n) worst case\n";
    cout << "✓ Space: O(log n) recursion stack\n";

    return 0;
}