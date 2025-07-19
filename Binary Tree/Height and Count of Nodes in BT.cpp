#include <iostream>
#include <vector>
#include <algorithm>
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

Node *buildTree(vector<int> &preOrder)
{
    static int idx = -1;
    idx++;
    if (preOrder[idx] == -1)
        return NULL;

    Node *newNode = new Node(preOrder[idx]);
    newNode->left = buildTree(preOrder);
    newNode->right = buildTree(preOrder);

    return newNode;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

int count(Node *root)
{
    if (root == NULL)
        return 0;

    return count(root->left) + count(root->right) + 1;
}

int main()
{
    cout << "Testing Height and Count of Nodes in Binary Tree:\n\n";

    // Test Case 1: Complete binary tree
    cout << "Test Case 1: Complete binary tree\n";
    cout << "Tree structure: 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1\n";
    vector<int> preOrder1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    Node *root1 = buildTree(preOrder1);
    cout << "Height: " << height(root1) << "\n";
    cout << "Count of nodes: " << count(root1) << "\n\n";

    // Test Case 2: Single node
    cout << "Test Case 2: Single node tree\n";
    cout << "Tree structure: 10, -1, -1\n";
    vector<int> preOrder2 = {10, -1, -1};
    Node *root2 = buildTree(preOrder2);
    cout << "Height: " << height(root2) << "\n";
    cout << "Count of nodes: " << count(root2) << "\n\n";

    // Test Case 3: Left skewed tree
    cout << "Test Case 3: Left skewed tree\n";
    cout << "Tree structure: 1, 2, 3, 4, -1, -1, -1, -1, -1\n";
    vector<int> preOrder3 = {1, 2, 3, 4, -1, -1, -1, -1, -1};
    Node *root3 = buildTree(preOrder3);
    cout << "Height: " << height(root3) << "\n";
    cout << "Count of nodes: " << count(root3) << "\n\n";

    // Test Case 4: Right skewed tree
    cout << "Test Case 4: Right skewed tree\n";
    cout << "Tree structure: 1, -1, 2, -1, 3, -1, 4, -1, -1\n";
    vector<int> preOrder4 = {1, -1, 2, -1, 3, -1, 4, -1, -1};
    Node *root4 = buildTree(preOrder4);
    cout << "Height: " << height(root4) << "\n";
    cout << "Count of nodes: " << count(root4) << "\n\n";

    // Test Case 5: Larger balanced tree
    cout << "Test Case 5: Larger balanced tree\n";
    cout << "Tree structure: 1, 2, 4, 8, -1, -1, 9, -1, -1, 5, 10, -1, -1, 11, -1, -1, 3, 6, -1, -1, 7, -1, -1\n";
    vector<int> preOrder5 = {1, 2, 4, 8, -1, -1, 9, -1, -1, 5, 10, -1, -1, 11, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    Node *root5 = buildTree(preOrder5);
    cout << "Height: " << height(root5) << "\n";
    cout << "Count of nodes: " << count(root5) << "\n\n";

    cout << "All test cases completed successfully!\n";

    return 0;
}