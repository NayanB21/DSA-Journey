/* Q.A linked list of length n is given such that each node contains an additional random pointer,
     which could point to any node in the list, or null.

     Construct a deep copy of the list.
     The deep copy should consist of exactly n brand new nodes,
     where each new node has its value set to the value of its corresponding original node.
     Both the next and random pointer of the new nodes should point to new nodes in the copied list such that
     the pointers in the original list and copied list represent the same list state.
     None of the pointers in the new list should point to nodes in the original list.

     For example, if there are two nodes X and Y in the original list, where X.random --> Y,
     then for the corresponding two nodes x and y in the copied list, x.random --> y.

     Return the head of the copied linked list.

     The linked list is represented in the input/output as a list of n nodes.
     Each node is represented as a pair of [val, random_index] where:

     val: an integer representing Node.val
     random_index: the index of the node (range from 0 to n-1) that the random pointer points to,
     or null if it does not point to any node.
     Your code will only be given the head of the original linked list.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *head1 = head;
        if (head == NULL)
            return head;

        Node *copiedHead = new Node(head->val);
        Node *copy1 = copiedHead;
        unordered_map<Node *, Node *> um;
        um[head1] = copy1;
        while (head1->next != NULL)
        {
            copy1->next = new Node(head1->next->val);
            um[head1->next] = copy1->next;
            copy1 = copy1->next;
            head1 = head1->next;
        }

        head1 = head;
        copy1 = copiedHead;
        while (head1 != NULL)
        {
            copy1->random = um[head1->random];
            head1 = head1->next;
            copy1 = copy1->next;
        }

        return copiedHead;
    }
};

// Helper function to create a list with random pointers
Node *createListWithRandom(int vals[], int size, int randomIndices[])
{
    if (size == 0)
        return nullptr;

    // Create all nodes first
    Node *nodes[size];
    for (int i = 0; i < size; i++)
    {
        nodes[i] = new Node(vals[i]);
    }

    // Set next pointers
    for (int i = 0; i < size - 1; i++)
    {
        nodes[i]->next = nodes[i + 1];
    }

    // Set random pointers
    for (int i = 0; i < size; i++)
    {
        if (randomIndices[i] != -1)
        {
            nodes[i]->random = nodes[randomIndices[i]];
        }
    }

    return nodes[0];
}

// Helper function to print list with random pointers
void printListWithRandom(Node *head)
{
    if (!head)
    {
        cout << "NULL" << endl;
        return;
    }

    Node *current = head;
    int index = 0;

    // First pass: print values and find indices
    cout << "Values: ";
    while (current)
    {
        cout << current->val;
        if (current->next)
            cout << " -> ";
        current = current->next;
        index++;
    }
    cout << endl;

    // Second pass: print random pointers
    current = head;
    index = 0;
    cout << "Random: ";
    while (current)
    {
        if (current->random)
        {
            // Find index of random node
            Node *temp = head;
            int randomIndex = 0;
            while (temp && temp != current->random)
            {
                temp = temp->next;
                randomIndex++;
            }
            cout << "[" << index << "]->" << randomIndex;
        }
        else
        {
            cout << "[" << index << "]->NULL";
        }
        if (current->next)
            cout << ", ";
        current = current->next;
        index++;
    }
    cout << endl;
}

// Helper function to verify deep copy
bool verifyDeepCopy(Node *original, Node *copied)
{
    if (!original && !copied)
        return true;
    if (!original || !copied)
        return false;

    Node *orig = original;
    Node *copy = copied;

    while (orig && copy)
    {
        // Check if values match
        if (orig->val != copy->val)
            return false;

        // Check if nodes are different objects
        if (orig == copy)
            return false;

        orig = orig->next;
        copy = copy->next;
    }

    return (!orig && !copy);
}

int main()
{
    Solution solution;

    // Test case 1: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    cout << "Test 1 - Standard case:" << endl;
    int vals1[] = {7, 13, 11, 10, 1};
    int random1[] = {-1, 0, 4, 2, 0};
    Node *original1 = createListWithRandom(vals1, 5, random1);

    cout << "Original: " << endl;
    printListWithRandom(original1);

    Node *copied1 = solution.copyRandomList(original1);
    cout << "Copied: " << endl;
    printListWithRandom(copied1);
    cout << "Deep copy verified: " << (verifyDeepCopy(original1, copied1) ? "Yes" : "No") << endl
         << endl;

    // Test case 2: [[1,1],[2,1]]
    cout << "Test 2 - Two nodes:" << endl;
    int vals2[] = {1, 2};
    int random2[] = {1, 1};
    Node *original2 = createListWithRandom(vals2, 2, random2);

    cout << "Original: " << endl;
    printListWithRandom(original2);

    Node *copied2 = solution.copyRandomList(original2);
    cout << "Copied: " << endl;
    printListWithRandom(copied2);
    cout << "Deep copy verified: " << (verifyDeepCopy(original2, copied2) ? "Yes" : "No") << endl
         << endl;

    // Test case 3: [[3,null]]
    cout << "Test 3 - Single node:" << endl;
    int vals3[] = {3};
    int random3[] = {-1};
    Node *original3 = createListWithRandom(vals3, 1, random3);

    cout << "Original: " << endl;
    printListWithRandom(original3);

    Node *copied3 = solution.copyRandomList(original3);
    cout << "Copied: " << endl;
    printListWithRandom(copied3);
    cout << "Deep copy verified: " << (verifyDeepCopy(original3, copied3) ? "Yes" : "No") << endl
         << endl;

    // Test case 4: []
    cout << "Test 4 - Empty list:" << endl;
    Node *original4 = nullptr;

    cout << "Original: " << endl;
    printListWithRandom(original4);

    Node *copied4 = solution.copyRandomList(original4);
    cout << "Copied: " << endl;
    printListWithRandom(copied4);
    cout << "Deep copy verified: " << (verifyDeepCopy(original4, copied4) ? "Yes" : "No") << endl
         << endl;

    // Test case 5: [[1,0],[2,0]]
    cout << "Test 5 - Multiple nodes pointing to same random:" << endl;
    int vals5[] = {1, 2};
    int random5[] = {0, 0};
    Node *original5 = createListWithRandom(vals5, 2, random5);

    cout << "Original: " << endl;
    printListWithRandom(original5);

    Node *copied5 = solution.copyRandomList(original5);
    cout << "Copied: " << endl;
    printListWithRandom(copied5);
    cout << "Deep copy verified: " << (verifyDeepCopy(original5, copied5) ? "Yes" : "No") << endl;

    return 0;
}
