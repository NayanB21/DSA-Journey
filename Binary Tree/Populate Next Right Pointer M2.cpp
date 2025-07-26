#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// Create perfect binary tree for testing
Node *createPerfectTree()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

// Print next pointers level by level
void printNextPointers(Node *root)
{
    if (!root)
        return;
    Node *level = root;
    while (level)
    {
        Node *curr = level;
        while (curr)
        {
            cout << curr->val;
            if (curr->next)
                cout << "->";
            curr = curr->next;
        }
        cout << " | ";
        level = level->left;
    }
}

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root || !root->left)
            return root;

        // Connect left to right
        root->left->next = root->right;

        // connect right to next subtree's left
        if (root->next)
        {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

int main()
{
    Solution sol;
    cout << "Testing Populate Next Right Pointers (Method 2 - O(1) Space):\n=============================================================\n\n";

    Node *root = createPerfectTree();
    cout << "Before connecting:\n";
    cout << "      1\n    /   \\\n   2     3\n  / \\   / \\\n 4   5 6   7\n\n";

    sol.connect(root);

    cout << "After connecting (next pointers):\n";
    printNextPointers(root);
    cout << "\nExpected: 1 | 2->3 | 4->5->6->7 |\n\n";

    cout << "✓ Uses existing next pointers to connect children\n";
    cout << "✓ Time: O(n), Space: O(1) - no queue needed\n";
    cout << "✓ Works only for perfect binary trees\n";

    return 0;
}