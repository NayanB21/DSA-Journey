#include <iostream>
#include <vector>
#include <queue>
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

void preOrder(Node *&root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *&root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);  
}

void postOrder(Node *&root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (q.size() > 0)
    {
        Node *curr = q.front(); // otherwise we have to call q.front() 5 times!!!

        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
        cout << curr->data << " ";
        q.pop();
    }
}

int main()
{
    cout << "Testing Binary Tree Traversal with 4 different algorithms:\n\n";

    // Test Case 1: Complete binary tree
    cout << "Test Case 1: Complete binary tree (1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1)\n";
    vector<int> preOrder1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    Node *root1 = buildTree(preOrder1);
    cout << "PreOrder:  ";
    preOrder(root1);
    cout << "\n";
    cout << "InOrder:   ";
    inOrder(root1);
    cout << "\n";
    cout << "PostOrder: ";
    postOrder(root1);
    cout << "\n";
    cout << "LevelOrder: ";
    levelOrder(root1);
    cout << "\n\n";

    // Test Case 2: Simple tree
    cout << "Test Case 2: Simple tree (10, 20, -1, -1, 30, -1, -1)\n";
    vector<int> preOrder2 = {10, 20, -1, -1, 30, -1, -1};
    Node *root2 = buildTree(preOrder2);
    cout << "PreOrder:  ";
    preOrder(root2);
    cout << "\n";
    cout << "InOrder:   ";
    inOrder(root2);
    cout << "\n";
    cout << "PostOrder: ";
    postOrder(root2);
    cout << "\n";
    cout << "LevelOrder: ";
    levelOrder(root2);
    cout << "\n\n";

    // Test Case 3: Left skewed tree
    cout << "Test Case 3: Left skewed tree (1, 2, 3, -1, -1, -1, -1)\n";
    vector<int> preOrder3 = {1, 2, 3, -1, -1, -1, -1};
    Node *root3 = buildTree(preOrder3);
    cout << "PreOrder:  ";
    preOrder(root3);
    cout << "\n";
    cout << "InOrder:   ";
    inOrder(root3);
    cout << "\n";
    cout << "PostOrder: ";
    postOrder(root3);
    cout << "\n";
    cout << "LevelOrder: ";
    levelOrder(root3);
    cout << "\n\n";

    // Test Case 4: Right skewed tree
    cout << "Test Case 4: Right skewed tree (1, -1, 2, -1, 3, -1, -1)\n";
    vector<int> preOrder4 = {1, -1, 2, -1, 3, -1, -1};
    Node *root4 = buildTree(preOrder4);
    cout << "PreOrder:  ";
    preOrder(root4);
    cout << "\n";
    cout << "InOrder:   ";
    inOrder(root4);
    cout << "\n";
    cout << "PostOrder: ";
    postOrder(root4);
    cout << "\n";
    cout << "LevelOrder: ";
    levelOrder(root4);
    cout << "\n\n";

    // Test Case 5: Single node
    cout << "Test Case 5: Single node tree (50, -1, -1)\n";
    vector<int> preOrder5 = {50, -1, -1};
    Node *root5 = buildTree(preOrder5);
    cout << "PreOrder:  ";
    preOrder(root5);
    cout << "\n";
    cout << "InOrder:   ";
    inOrder(root5);
    cout << "\n";
    cout << "PostOrder: ";
    postOrder(root5);
    cout << "\n";
    cout << "LevelOrder: ";
    levelOrder(root5);
    cout << "\n\n";

    cout << "All traversal algorithms tested successfully!\n";

    return 0;
}
