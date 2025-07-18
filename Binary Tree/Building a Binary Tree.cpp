#include <iostream>
#include <vector>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to print preorder traversal for verification
void printPreorder(Node *root)
{
    if (root == NULL)
    {
        cout << "-1 ";
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

Node *buildTree(vector<int> &preOrder)
{

    static int idx = -1; // can be define globaly also
    idx++;
    if (preOrder[idx] == -1)
        return NULL;

    Node *newNode = new Node(preOrder[idx]);
    newNode->left = buildTree(preOrder);
    newNode->right = buildTree(preOrder);

    return newNode; // imp
}

int main()
{
    cout << "Testing Binary Tree Building with 5 test cases:\n\n";

    // Test Case 1: Simple tree with root and two children
    cout << "Test Case 1: Simple tree (1, 2, -1, -1, 3, -1, -1)\n";
    vector<int> preOrder1 = {1, 2, -1, -1, 3, -1, -1};
    Node *root1 = buildTree(preOrder1);
    cout << "Built tree preorder: ";
    printPreorder(root1);
    cout << "\n\n";

    // Test Case 2: Only root node
    cout << "Test Case 2: Single node tree (5, -1, -1)\n";
    vector<int> preOrder2 = {5, -1, -1};
    Node *root2 = buildTree(preOrder2);
    cout << "Built tree preorder: ";
    printPreorder(root2);
    cout << "\n\n";

    // Test Case 3: Left skewed tree
    cout << "Test Case 3: Left skewed tree (1, 2, 3, -1, -1, -1, -1)\n";
    vector<int> preOrder3 = {1, 2, 3, -1, -1, -1, -1};
    Node *root3 = buildTree(preOrder3);
    cout << "Built tree preorder: ";
    printPreorder(root3);
    cout << "\n\n";

    // Test Case 4: Right skewed tree
    cout << "Test Case 4: Right skewed tree (1, -1, 2, -1, 3, -1, -1)\n";
    vector<int> preOrder4 = {1, -1, 2, -1, 3, -1, -1};
    Node *root4 = buildTree(preOrder4);
    cout << "Built tree preorder: ";
    printPreorder(root4);
    cout << "\n\n";

    // Test Case 5: Complete binary tree
    cout << "Test Case 5: Complete binary tree (1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1)\n";
    vector<int> preOrder5 = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    Node *root5 = buildTree(preOrder5);
    cout << "Built tree preorder: ";
    printPreorder(root5);
    cout << "\n\n";

    cout << "All test cases completed successfully!\n";

    return 0;
}
