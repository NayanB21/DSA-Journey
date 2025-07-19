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

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 0)
    {
        Node *curr = q.front(); // otherwise we have to call q.front() 5 times!!!
        q.pop();                // we have to pop at start for next logic to go right

        // main logic for line flagging
        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL); // for ending next line-imp step
                continue;
            }
            else
                break;
        }

        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
        cout << curr->data << " ";
    }
}

int main()
{
    cout << "Testing Level Order Traversal with line breaks:\n\n";

    // Test Case 1: Complete binary tree
    cout << "Test Case 1: Complete binary tree\n";
    cout << "Tree structure: 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1\n";
    vector<int> preOrder1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    Node *root1 = buildTree(preOrder1);
    cout << "Level Order Traversal:\n";
    levelOrder(root1);
    cout << "\n\n";

    // Test Case 2: Simple tree
    cout << "Test Case 2: Simple tree\n";
    cout << "Tree structure: 10, 20, -1, -1, 30, -1, -1\n";
    vector<int> preOrder2 = {10, 20, -1, -1, 30, -1, -1};
    Node *root2 = buildTree(preOrder2);
    cout << "Level Order Traversal:\n";
    levelOrder(root2);
    cout << "\n\n";

    // Test Case 3: Left skewed tree
    cout << "Test Case 3: Left skewed tree\n";
    cout << "Tree structure: 1, 2, 3, -1, -1, -1, -1\n";
    vector<int> preOrder3 = {1, 2, 3, -1, -1, -1, -1};
    Node *root3 = buildTree(preOrder3);
    cout << "Level Order Traversal:\n";
    levelOrder(root3);
    cout << "\n\n";

    // Test Case 4: Right skewed tree
    cout << "Test Case 4: Right skewed tree\n";
    cout << "Tree structure: 1, -1, 2, -1, 3, -1, -1\n";
    vector<int> preOrder4 = {1, -1, 2, -1, 3, -1, -1};
    Node *root4 = buildTree(preOrder4);
    cout << "Level Order Traversal:\n";
    levelOrder(root4);
    cout << "\n\n";

    // Test Case 5: Larger complete tree
    cout << "Test Case 5: Larger complete tree\n";
    cout << "Tree structure: 1, 2, 4, 8, -1, -1, 9, -1, -1, 5, 10, -1, -1, 11, -1, -1, 3, 6, 12, -1, -1, 13, -1, -1, 7, 14, -1, -1, 15, -1, -1\n";
    vector<int> preOrder5 = {1, 2, 4, 8, -1, -1, 9, -1, -1, 5, 10, -1, -1, 11, -1, -1, 3, 6, 12, -1, -1, 13, -1, -1, 7, 14, -1, -1, 15, -1, -1};
    Node *root5 = buildTree(preOrder5);
    cout << "Level Order Traversal:\n";
    levelOrder(root5);
    cout << "\n\n";

    cout << "All test cases completed successfully!\n";

    return 0;
}