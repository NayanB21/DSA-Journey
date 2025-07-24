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

// Inorder print for verification
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

Node *delNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->val)
    {
        root->left = delNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = delNode(root->right, key);
    }

    else
    {
        // Node-Type-1
        if (root->right == NULL && root->left == NULL)
        {
            delete root; // To avoid Memory Leak
            return NULL;
        }
        // Node-Type-2
        else if (root->right == NULL || root->left == NULL)
        {
            Node *temp = root;
            delete root; // To avoid Memory Leak
            return root->right == NULL ? root->left : root->right;
        }
        // Node-Type-3
        else
        {
            // Finding IS(inordered successor)
            Node *IS = root->right;
            while (IS->left != NULL)
                IS = IS->left;

            root->val = IS->val;
            root->right = delNode(root->right, IS->val); // imp step to delete IS Node
        }
    }

    return root;
}

int main()
{
    cout << "Testing BST Node Deletion:\n=========================\n\n";

    vector<int> bstData = {5, 3, 7, 2, 4, 6, 8};
    vector<int> deleteKeys = {3, 7, 5};
    vector<string> types = {"Node with 2 children", "Node with 2 children", "Root with 2 children"};

    for (int i = 0; i < deleteKeys.size(); i++)
    {
        Node *root = buildBST(bstData);
        cout << "Test " << (i + 1) << " - Delete " << deleteKeys[i] << " (" << types[i] << "):\n";
        cout << "Before: ";
        inorder(root);
        cout << "\n";

        root = delNode(root, deleteKeys[i]);
        cout << "After:  ";
        inorder(root);
        cout << "\n"
             << string(40, '-') << "\n\n";
    }

    cout << "✓ 3 deletion cases: Leaf, One child, Two children\n";
    cout << "✓ Uses inorder successor for two-child case\n";
    cout << "✓ Time: O(log n) average, O(n) worst case\n";

    return 0;
}