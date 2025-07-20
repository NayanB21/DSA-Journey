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

// int count=1;
void kthLevel(Node *root, int k)
{ // also parallely we can do like this

    if (root == NULL)
        return; // if(root==NULL)return;
    if (k == 1)
    { // if(k==count){cout<<root->val<<" ";
      // return;}
        cout << root->val << " ";
        return;
    }

    kthLevel(root->left, k - 1);  // kthLevel(root->left,k-1);
    kthLevel(root->right, k - 1); // kthLevel(root->right,k-1);
                                  // count--;//backtrack
}

int main()
{
    cout << "Testing kth Level of Binary Tree by Recursion:\n\n";

    // Test Case 1: Standard binary tree
    cout << "Test Case 1: Standard binary tree\n";
    cout << "Tree structure: 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1\n";
    vector<int> preOrder1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int idx1 = 0;
    Node *root1 = buildTree(preOrder1, idx1);
    cout << "Level 1 (k=1): ";
    kthLevel(root1, 1);
    cout << "\n";
    cout << "Level 2 (k=2): ";
    kthLevel(root1, 2);
    cout << "\n";
    cout << "Level 3 (k=3): ";
    kthLevel(root1, 3);
    cout << "\n";
    cout << "Level 4 (k=4): ";
    kthLevel(root1, 4);
    cout << "\n\n";

    // Test Case 2: Right skewed tree
    cout << "Test Case 2: Right skewed tree\n";
    cout << "Tree structure: 1, -1, 2, -1, 3, -1, 4, -1, -1\n";
    vector<int> preOrder2 = {1, -1, 2, -1, 3, -1, 4, -1, -1};
    int idx2 = 0;
    Node *root2 = buildTree(preOrder2, idx2);
    cout << "Level 1 (k=1): ";
    kthLevel(root2, 1);
    cout << "\n";
    cout << "Level 2 (k=2): ";
    kthLevel(root2, 2);
    cout << "\n";
    cout << "Level 3 (k=3): ";
    kthLevel(root2, 3);
    cout << "\n";
    cout << "Level 4 (k=4): ";
    kthLevel(root2, 4);
    cout << "\n\n";

    // Test Case 3: Left skewed tree
    cout << "Test Case 3: Left skewed tree\n";
    cout << "Tree structure: 1, 2, 3, 4, -1, -1, -1, -1, -1\n";
    vector<int> preOrder3 = {1, 2, 3, 4, -1, -1, -1, -1, -1};
    int idx3 = 0;
    Node *root3 = buildTree(preOrder3, idx3);
    cout << "Level 1 (k=1): ";
    kthLevel(root3, 1);
    cout << "\n";
    cout << "Level 2 (k=2): ";
    kthLevel(root3, 2);
    cout << "\n";
    cout << "Level 3 (k=3): ";
    kthLevel(root3, 3);
    cout << "\n";
    cout << "Level 4 (k=4): ";
    kthLevel(root3, 4);
    cout << "\n\n";

    // Test Case 4: Single node
    cout << "Test Case 4: Single node\n";
    cout << "Tree structure: 10, -1, -1\n";
    vector<int> preOrder4 = {10, -1, -1};
    int idx4 = 0;
    Node *root4 = buildTree(preOrder4, idx4);
    cout << "Level 1 (k=1): ";
    kthLevel(root4, 1);
    cout << "\n";
    cout << "Level 2 (k=2): ";
    kthLevel(root4, 2);
    cout << "\n\n";

    // Test Case 5: Larger balanced tree
    cout << "Test Case 5: Larger balanced tree\n";
    cout << "Tree structure: 1, 2, 4, 8, -1, -1, 9, -1, -1, 5, 10, -1, -1, 11, -1, -1, 3, 6, -1, -1, 7, -1, -1\n";
    vector<int> preOrder5 = {1, 2, 4, 8, -1, -1, 9, -1, -1, 5, 10, -1, -1, 11, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int idx5 = 0;
    Node *root5 = buildTree(preOrder5, idx5);
    cout << "Level 1 (k=1): ";
    kthLevel(root5, 1);
    cout << "\n";
    cout << "Level 2 (k=2): ";
    kthLevel(root5, 2);
    cout << "\n";
    cout << "Level 3 (k=3): ";
    kthLevel(root5, 3);
    cout << "\n";
    cout << "Level 4 (k=4): ";
    kthLevel(root5, 4);
    cout << "\n\n";

    cout << "All test cases completed!\n";
    cout << "Note: kth level shows all nodes at depth k (1-indexed).\n";

    return 0;
}