#include <iostream>
#include <queue>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;
        queue<Node *> q;
        q.push(root);

        Node *prev = NULL;

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *curr = q.front();
                if (prev)
                {
                    prev->next = curr;
                }

                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);

                prev = curr;
                q.pop();
            }
            prev->next = NULL;
            prev = NULL;
        }
        return root;
    }
};

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
        level = level->left; // Move to next level
    }
}

int main()
{
    Solution sol;
    cout << "Testing Populate Next Right Pointers (Method 1 - Level Order):\n==============================================================\n\n";

    Node *root = createPerfectTree();
    cout << "Before connecting:\n";
    cout << "      1\n    /   \\\n   2     3\n  / \\   / \\\n 4   5 6   7\n\n";

    sol.connect(root);

    cout << "After connecting (next pointers):\n";
    printNextPointers(root);
    cout << "\nExpected: 1 | 2->3 | 4->5->6->7 |\n\n";

    cout << "✓ Uses level order traversal with queue\n";
    cout << "✓ Time: O(n), Space: O(w) where w is max width\n";

    return 0;
}