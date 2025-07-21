#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int value)
    {
        val = value;
        left = right = nullptr;
    }
};

Node *buildTree(vector<int> &preOrder, int &idx)
{
    if (idx >= preOrder.size() || preOrder[idx] == -1)
    {
        idx++;
        return nullptr;
    }

    Node *newNode = new Node(preOrder[idx++]);
    newNode->left = buildTree(preOrder, idx);
    newNode->right = buildTree(preOrder, idx);

    return newNode;
}

void printInorder(Node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int sumTree(Node *root)
{
    if (root == NULL)
        return 0;

    int sum = sumTree(root->left) + sumTree(root->right);

    root->val += sum;

    return root->val;
}

int main()
{
    cout << "Testing Transform to Sum Tree:\n\n";

    // Test Case 1: Simple binary tree
    cout << "Test Case 1: Simple binary tree\n";
    cout << "Original tree: 10, 2, 1, -1, -1, 4, -1, -1, 6, -1, -1\n";
    vector<int> preOrder1 = {10, 2, 1, -1, -1, 4, -1, -1, 6, -1, -1};
    int idx1 = 0;
    Node *root1 = buildTree(preOrder1, idx1);
    cout << "Before transformation: ";
    printInorder(root1);
    cout << "\n";
    sumTree(root1);
    cout << "After transformation:  ";
    printInorder(root1);
    cout << "\n\n";

    // Test Case 2: Single node
    cout << "Test Case 2: Single node\n";
    cout << "Original tree: 5, -1, -1\n";
    vector<int> preOrder2 = {5, -1, -1};
    int idx2 = 0;
    Node *root2 = buildTree(preOrder2, idx2);
    cout << "Before transformation: ";
    printInorder(root2);
    cout << "\n";
    sumTree(root2);
    cout << "After transformation:  ";
    printInorder(root2);
    cout << "\n\n";

    // Test Case 3: Left skewed tree
    cout << "Test Case 3: Left skewed tree\n";
    cout << "Original tree: 1, 2, 3, -1, -1, -1, -1\n";
    vector<int> preOrder3 = {1, 2, 3, -1, -1, -1, -1};
    int idx3 = 0;
    Node *root3 = buildTree(preOrder3, idx3);
    cout << "Before transformation: ";
    printInorder(root3);
    cout << "\n";
    sumTree(root3);
    cout << "After transformation:  ";
    printInorder(root3);
    cout << "\n\n";

    // Test Case 4: Perfect binary tree
    cout << "Test Case 4: Perfect binary tree\n";
    cout << "Original tree: 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1\n";
    vector<int> preOrder4 = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int idx4 = 0;
    Node *root4 = buildTree(preOrder4, idx4);
    cout << "Before transformation: ";
    printInorder(root4);
    cout << "\n";
    sumTree(root4);
    cout << "After transformation:  ";
    printInorder(root4);
    cout << "\n\n";

    // Test Case 5: Right skewed tree
    cout << "Test Case 5: Right skewed tree\n";
    cout << "Original tree: 1, -1, 2, -1, 3, -1, -1\n";
    vector<int> preOrder5 = {1, -1, 2, -1, 3, -1, -1};
    int idx5 = 0;
    Node *root5 = buildTree(preOrder5, idx5);
    cout << "Before transformation: ";
    printInorder(root5);
    cout << "\n";
    sumTree(root5);
    cout << "After transformation:  ";
    printInorder(root5);
    cout << "\n\n";

    cout << "All test cases completed!\n";
    cout << "Note: Sum tree transforms each node to contain sum of all nodes in its subtree.\n";

    return 0;
}