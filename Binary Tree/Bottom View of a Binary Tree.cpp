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

void bottomView(Node *root)
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

        m[curr.second] = curr.first->val; // just one line modification
                                          // to make it bottom view from top view
    }

    for (auto it : m)
    { // for each loop to traverse a map
        cout << it.second << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Testing Bottom View of Binary Tree:\n\n";

    // Test Case 1: Standard binary tree
    cout << "Test Case 1: Standard binary tree\n";
    cout << "Tree structure: 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1\n";
    cout << "Expected bottom view: 4 5 6 7\n";
    vector<int> preOrder1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int idx1 = 0;
    Node *root1 = buildTree(preOrder1, idx1);
    cout << "Actual bottom view: ";
    bottomView(root1);
    cout << "\n";

    // Test Case 2: Right skewed tree
    cout << "Test Case 2: Right skewed tree\n";
    cout << "Tree structure: 1, -1, 2, -1, 3, -1, 4, -1, -1\n";
    cout << "Expected bottom view: 1 2 3 4\n";
    vector<int> preOrder2 = {1, -1, 2, -1, 3, -1, 4, -1, -1};
    int idx2 = 0;
    Node *root2 = buildTree(preOrder2, idx2);
    cout << "Actual bottom view: ";
    bottomView(root2);
    cout << "\n";

    // Test Case 3: Left skewed tree
    cout << "Test Case 3: Left skewed tree\n";
    cout << "Tree structure: 1, 2, 3, 4, -1, -1, -1, -1, -1\n";
    cout << "Expected bottom view: 4 3 2 1\n";
    vector<int> preOrder3 = {1, 2, 3, 4, -1, -1, -1, -1, -1};
    int idx3 = 0;
    Node *root3 = buildTree(preOrder3, idx3);
    cout << "Actual bottom view: ";
    bottomView(root3);
    cout << "\n";

    // Test Case 4: Single node
    cout << "Test Case 4: Single node\n";
    cout << "Tree structure: 10, -1, -1\n";
    cout << "Expected bottom view: 10\n";
    vector<int> preOrder4 = {10, -1, -1};
    int idx4 = 0;
    Node *root4 = buildTree(preOrder4, idx4);
    cout << "Actual bottom view: ";
    bottomView(root4);
    cout << "\n";

    // Test Case 5: Complex tree with overlapping nodes
    cout << "Test Case 5: Complex tree\n";
    cout << "Tree structure: 20, 8, 5, -1, -1, 3, 10, -1, -1, 14, -1, -1, 22, -1, 25, -1, -1\n";
    cout << "Expected bottom view: 5 10 3 14 25\n";
    vector<int> preOrder5 = {20, 8, 5, -1, -1, 3, 10, -1, -1, 14, -1, -1, 22, -1, 25, -1, -1};
    int idx5 = 0;
    Node *root5 = buildTree(preOrder5, idx5);
    cout << "Actual bottom view: ";
    bottomView(root5);
    cout << "\n";

    cout << "All test cases completed!\n";
    cout << "Note: Bottom view shows the last node encountered at each horizontal distance.\n";

    return 0;
}
