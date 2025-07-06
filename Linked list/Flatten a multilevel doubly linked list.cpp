/* Q. You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer,
     and an additional child pointer. This child pointer may or may not point to a separate doubly linked list,
     also containing these special nodes. These child lists may have one or more children of their own, and so on,
     to produce a multilevel data structure.

     Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level,
     doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr
     and before curr.next in the flattened list.

     Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.
*/

#include <iostream>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node(int _val)
    {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution
{
public:
    void helper(Node *head)
    {
        Node *temp = head;

        Node *nextOne = NULL; // imp step
        if (temp == NULL)
            return; // imp step
        while (temp->next != NULL || temp->child != NULL)
        {

            if (temp->child != NULL)
            {
                nextOne = temp->next;
                temp->next = temp->child;
                temp->child->prev = temp; // imp step
                temp->child = NULL;       // imp step
                helper(temp->next);
            }
            else
            {
                temp = temp->next;
            }
        }
        if (temp)
            temp->next = nextOne;
        if (nextOne) // imp step
        {
            nextOne->prev = temp;
        } // imp step
    }

    Node *flatten(Node *head)
    {
        helper(head);
        return head;
    }
};

// Helper function to create a node
Node *createNode(int val)
{
    return new Node(val);
}

// Helper function to connect two nodes
void connectNodes(Node *node1, Node *node2)
{
    if (node1)
        node1->next = node2;
    if (node2)
        node2->prev = node1;
}

// Helper function to print flattened list
void printFlattenedList(Node *head)
{
    if (!head)
    {
        cout << "NULL" << endl;
        return;
    }

    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to verify all child pointers are null
bool verifyNoChildPointers(Node *head)
{
    while (head)
    {
        if (head->child != nullptr)
            return false;
        head = head->next;
    }
    return true;
}

// Helper function to verify doubly linked structure
bool verifyDoublyLinked(Node *head)
{
    Node *prev = nullptr;
    while (head)
    {
        if (head->prev != prev)
            return false;
        prev = head;
        head = head->next;
    }
    return true;
}

int main()
{
    Solution solution;

    // Test case 1: Multi-level list [1,2,3,7,8,11,12,9,10,4,5,6]
    cout << "Test 1 - Multi-level with branches:" << endl;
    Node *head1 = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);
    Node *node5 = createNode(5);
    Node *node6 = createNode(6);
    Node *node7 = createNode(7);
    Node *node8 = createNode(8);
    Node *node9 = createNode(9);
    Node *node10 = createNode(10);
    Node *node11 = createNode(11);
    Node *node12 = createNode(12);

    // Main level: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    connectNodes(head1, node2);
    connectNodes(node2, node3);
    connectNodes(node3, node4);
    connectNodes(node4, node5);
    connectNodes(node5, node6);

    // Child of 3: 7 <-> 8 <-> 9 <-> 10
    node3->child = node7;
    connectNodes(node7, node8);
    connectNodes(node8, node9);
    connectNodes(node9, node10);

    // Child of 8: 11 <-> 12
    node8->child = node11;
    connectNodes(node11, node12);

    cout << "Original structure: 1<->2<->3<->4<->5<->6 with branches" << endl;

    Node *flattened1 = solution.flatten(head1);
    cout << "Flattened: ";
    printFlattenedList(flattened1);
    cout << "Expected: 1 <-> 2 <-> 3 <-> 7 <-> 8 <-> 11 <-> 12 <-> 9 <-> 10 <-> 4 <-> 5 <-> 6" << endl;
    cout << "Child pointers nulled: " << (verifyNoChildPointers(flattened1) ? "Yes" : "No") << endl;
    cout << "Doubly linked verified: " << (verifyDoublyLinked(flattened1) ? "Yes" : "No") << endl
         << endl;

    // Test case 2: Simple single child [1,2,null,3]
    cout << "Test 2 - Single child:" << endl;
    Node *head2 = createNode(1);
    Node *node2_2 = createNode(2);
    Node *node3_2 = createNode(3);

    connectNodes(head2, node2_2);
    node2_2->child = node3_2;

    cout << "Original: 1 <-> 2 (child: 3)" << endl;

    Node *flattened2 = solution.flatten(head2);
    cout << "Flattened: ";
    printFlattenedList(flattened2);
    cout << "Expected: 1 <-> 2 <-> 3" << endl;
    cout << "Child pointers nulled: " << (verifyNoChildPointers(flattened2) ? "Yes" : "No") << endl
         << endl;

    // Test case 3: Single node [1]
    cout << "Test 3 - Single node:" << endl;
    Node *head3 = createNode(1);

    cout << "Original: 1" << endl;

    Node *flattened3 = solution.flatten(head3);
    cout << "Flattened: ";
    printFlattenedList(flattened3);
    cout << "Expected: 1" << endl;
    cout << "Child pointers nulled: " << (verifyNoChildPointers(flattened3) ? "Yes" : "No") << endl
         << endl;

    // Test case 4: Empty list
    cout << "Test 4 - Empty list:" << endl;
    Node *head4 = nullptr;

    cout << "Original: NULL" << endl;

    Node *flattened4 = solution.flatten(head4);
    cout << "Flattened: ";
    printFlattenedList(flattened4);
    cout << "Expected: NULL" << endl
         << endl;

    // Test case 5: Linear list with no children [1,2,3,4]
    cout << "Test 5 - No children:" << endl;
    Node *head5 = createNode(1);
    Node *node2_5 = createNode(2);
    Node *node3_5 = createNode(3);
    Node *node4_5 = createNode(4);

    connectNodes(head5, node2_5);
    connectNodes(node2_5, node3_5);
    connectNodes(node3_5, node4_5);

    cout << "Original: 1 <-> 2 <-> 3 <-> 4" << endl;

    Node *flattened5 = solution.flatten(head5);
    cout << "Flattened: ";
    printFlattenedList(flattened5);
    cout << "Expected: 1 <-> 2 <-> 3 <-> 4" << endl;
    cout << "Child pointers nulled: " << (verifyNoChildPointers(flattened5) ? "Yes" : "No") << endl;

    return 0;
}