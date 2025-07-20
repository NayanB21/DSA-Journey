#include <iostream>
#include <queue>
#include <map>
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

void topView(Node *root)
{
    queue<pair<Node *, int>> q; // pair of<Nodes,hDistance>
    map<int, int> m;

    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> curr = q.front();
        q.pop();
        if (curr.first->left != NULL)
        {
            q.push({curr.first->left, curr.second - 1});
        }
        if (curr.first->right != NULL)
        {
            q.push({curr.first->right, curr.second + 1});
        }

        if (m.find(curr.second) == m.end())
        {
            m[curr.second] = curr.first->val;
        }
    }

    for (auto it : m)
    { // for each loop to traverse a map
        cout << it.second << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Testing Top View of Binary Tree:\n\n";

    // Test Case 1: Standard binary tree
    cout << "Test Case 1: Standard binary tree\n";
    cout << "Tree structure: 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1\n";
    cout << "Expected top view: 4 2 1 3 7\n";
    vector<int> preOrder1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int idx1 = 0;
    Node *root1 = buildTree(preOrder1, idx1);
    cout << "Actual top view: ";
    topView(root1);
    cout << "\n";

    // Test Case 2: Right skewed tree
    cout << "Test Case 2: Right skewed tree\n";
    cout << "Tree structure: 1, -1, 2, -1, 3, -1, 4, -1, -1\n";
    cout << "Expected top view: 1 2 3 4\n";
    vector<int> preOrder2 = {1, -1, 2, -1, 3, -1, 4, -1, -1};
    int idx2 = 0;
    Node *root2 = buildTree(preOrder2, idx2);
    cout << "Actual top view: ";
    topView(root2);
    cout << "\n";

    // Test Case 3: Left skewed tree
    cout << "Test Case 3: Left skewed tree\n";
    cout << "Tree structure: 1, 2, 3, 4, -1, -1, -1, -1, -1\n";
    cout << "Expected top view: 4 3 2 1\n";
    vector<int> preOrder3 = {1, 2, 3, 4, -1, -1, -1, -1, -1};
    int idx3 = 0;
    Node *root3 = buildTree(preOrder3, idx3);
    cout << "Actual top view: ";
    topView(root3);
    cout << "\n";

    // Test Case 4: Single node
    cout << "Test Case 4: Single node\n";
    cout << "Tree structure: 10, -1, -1\n";
    cout << "Expected top view: 10\n";
    vector<int> preOrder4 = {10, -1, -1};
    int idx4 = 0;
    Node *root4 = buildTree(preOrder4, idx4);
    cout << "Actual top view: ";
    topView(root4);
    cout << "\n";

    // Test Case 5: Complex tree with overlapping nodes
    cout << "Test Case 5: Complex tree\n";
    cout << "Tree structure: 1, 2, 4, 8, -1, -1, 9, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1\n";
    cout << "Expected top view: 8 4 2 1 3 7\n";
    vector<int> preOrder5 = {1, 2, 4, 8, -1, -1, 9, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int idx5 = 0;
    Node *root5 = buildTree(preOrder5, idx5);
    cout << "Actual top view: ";
    topView(root5);
    cout << "\n";

    cout << "All test cases completed!\n";
    cout << "Note: Top view shows the first node encountered at each horizontal distance.\n";

    return 0;
}
