#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Inorder traversal to get sorted array
void inorder(Node *root, vector<int> &vec)
{
    if (!root)
        return;
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}

// Build balanced BST from sorted array
Node *buildBST(vector<int> &arr, int start, int end)
{
    if (start > end)
        return nullptr;
    int mid = start + (end - start) / 2;
    Node *root = new Node(arr[mid]);
    root->left = buildBST(arr, start, mid - 1);
    root->right = buildBST(arr, mid + 1, end);
    return root;
}

// Print inorder for verification
void printInorder(Node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

Node *merge(Node *root1, Node *root2)
{
    vector<int> vec1, vec2;
    inorder(root1, vec1);
    inorder(root2, vec2);

    vector<int> temp;
    int i = 0, j = 0;

    // Merging two sorted arrays
    while (i < vec1.size() && j < vec2.size())
    {
        if (vec1[i] < vec2[j])
            temp.push_back(vec1[i++]);
        else
            temp.push_back(vec2[j++]);
    }
    while (i < vec1.size())
        temp.push_back(vec1[i++]);
    while (j < vec2.size())
        temp.push_back(vec2[j++]);

    return buildBST(temp, 0, temp.size() - 1);
}

int main()
{
    cout << "Testing Merge Two BSTs:\n======================\n\n";

    // Create BST1: [2,1,3]
    Node *root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    // Create BST2: [5,4,6]
    Node *root2 = new Node(5);
    root2->left = new Node(4);
    root2->right = new Node(6);

    cout << "BST1 inorder: ";
    printInorder(root1);
    cout << "\nBST2 inorder: ";
    printInorder(root2);
    cout << "\n\n";

    Node *merged = merge(root1, root2);
    cout << "Merged BST inorder: ";
    printInorder(merged);
    cout << " (Expected: 1 2 3 4 5 6)\n\n";

    cout << "✓ Algorithm: Extract inorder arrays → merge sorted arrays → build balanced BST\n";
    cout << "✓ Time: O(m+n), Space: O(m+n) where m,n are sizes of BSTs\n";

    return 0;
}