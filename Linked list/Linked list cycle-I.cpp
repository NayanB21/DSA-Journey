/*Q. Given head, the head of a linked list,
     determine if the linked list has a cycle in it.
*/
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

// Helper function to create a linear linked list
ListNode *createLinearList(int arr[], int size)
{
    if (size == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Helper function to create a cyclic linked list
ListNode *createCyclicList(int arr[], int size, int cyclePos)
{
    if (size == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    ListNode *cycleNode = nullptr;

    // Create nodes
    for (int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    // Find the cycle position node
    current = head;
    for (int i = 0; i < cyclePos && current != nullptr; i++)
    {
        current = current->next;
    }
    cycleNode = current;

    // Go to the last node
    current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    // Create cycle by pointing last node to cycleNode
    current->next = cycleNode;

    return head;
}

// Helper function to print linked list (only for non-cyclic lists)
void printList(ListNode *head, int maxNodes = 10)
{
    int count = 0;
    while (head && count < maxNodes)
    {
        cout << head->val;
        if (head->next && count < maxNodes - 1)
            cout << " -> ";
        head = head->next;
        count++;
    }
    if (count == maxNodes)
        cout << " ...";
    cout << endl;
}

int main()
{
    Solution solution;

    // Test case 1: No cycle [3,2,0,-4]
    cout << "Test 1 - No cycle: ";
    int arr1[] = {3, 2, 0, -4};
    ListNode *head1 = createLinearList(arr1, 4);
    printList(head1);

    bool hasCycle1 = solution.hasCycle(head1);
    cout << "Has cycle: " << (hasCycle1 ? "Yes" : "No") << endl;
    cout << "Expected: No" << endl
         << endl;

    // Test case 2: Cycle at position 1 [3,2,0,-4] -> cycle from -4 to 2
    cout << "Test 2 - With cycle: ";
    int arr2[] = {3, 2, 0, -4};
    ListNode *head2 = createCyclicList(arr2, 4, 1);
    cout << "3 -> 2 -> 0 -> -4 -> (back to 2)" << endl;

    bool hasCycle2 = solution.hasCycle(head2);
    cout << "Has cycle: " << (hasCycle2 ? "Yes" : "No") << endl;
    cout << "Expected: Yes" << endl
         << endl;

    // Test case 3: Single node without cycle [1]
    cout << "Test 3 - Single node: ";
    ListNode *head3 = new ListNode(1);
    cout << "1" << endl;

    bool hasCycle3 = solution.hasCycle(head3);
    cout << "Has cycle: " << (hasCycle3 ? "Yes" : "No") << endl;
    cout << "Expected: No" << endl
         << endl;

    // Test case 4: Single node with cycle [1] -> cycle to itself
    cout << "Test 4 - Single node with cycle: ";
    ListNode *head4 = new ListNode(1);
    head4->next = head4; // Point to itself
    cout << "1 -> (back to 1)" << endl;

    bool hasCycle4 = solution.hasCycle(head4);
    cout << "Has cycle: " << (hasCycle4 ? "Yes" : "No") << endl;
    cout << "Expected: Yes" << endl
         << endl;

    // Test case 5: Empty list
    cout << "Test 5 - Empty list: ";
    ListNode *head5 = nullptr;
    cout << "NULL" << endl;

    bool hasCycle5 = solution.hasCycle(head5);
    cout << "Has cycle: " << (hasCycle5 ? "Yes" : "No") << endl;
    cout << "Expected: No" << endl;

    return 0;
}
