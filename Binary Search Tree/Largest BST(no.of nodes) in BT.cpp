#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Info
{
public:
    int min;
    int max;
    int size;

    Info(int min, int max, int size)
    {
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

Info helper(Node *root)
{
    if (root == NULL)
    {
        return Info(INT_MAX, INT_MIN, 0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if (root->val > left.max && root->val < right.min)
    {
        int currMin = min(root->val, left.min);  // these comparision(max,min) is just
        int currMax = max(root->val, right.max); // to tackle NULL Info case
        int currSize = left.size + right.size + 1;

        return Info(currMin, currMax, currSize);
    }
    else
        return Info(INT_MIN, INT_MAX, max(left.size, right.size));
}

int LargestBST(Node *root)
{ // return no. of nodes in largest BST
    Info ans = helper(root);
    return ans.size;
}

// Create test binary trees
Node *createTestTree(int type)
{
    if (type == 1)
    { // Mixed tree with BST subtree
        Node *root = new Node(10);
        root->left = new Node(5);
        root->right = new Node(15);
        root->left->left = new Node(1);
        root->left->right = new Node(8);
        root->right->right = new Node(7); // Invalid BST (7 < 15)
        return root;
    }
    if (type == 2)
    { // Complete BST
        Node *root = new Node(5);
        root->left = new Node(3);
        root->right = new Node(7);
        root->left->left = new Node(2);
        root->left->right = new Node(4);
        return root;
    }
    if (type == 3)
    { // Single node
        return new Node(42);
    }
    return nullptr;
}

int main()
{
    cout << "Testing Largest BST in Binary Tree:\n==================================\n\n";

    vector<int> testTypes = {1, 2, 3};
    vector<int> expected = {3, 5, 1};
    vector<string> names = {"Mixed tree", "Complete BST", "Single node"};

    for (int i = 0; i < testTypes.size(); i++)
    {
        Node *root = createTestTree(testTypes[i]);
        int result = LargestBST(root);

        cout << "Test " << (i + 1) << " (" << names[i] << "): "
             << result << " nodes (Expected: " << expected[i] << ")\n";
    }

    cout << "\n✓ Uses bottom-up approach with Info class (min, max, size)\n";
    cout << "✓ Time: O(n), Space: O(h) recursion stack\n";

    return 0;
}