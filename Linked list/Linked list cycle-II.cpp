/* Q.Given the head of a linked list, return the node where the cycle begins.
     If there is no cycle, return null.
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        bool isCycle = false;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                isCycle = true;
                break;
            }
        }
        if (!isCycle)
            return NULL;

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
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

// Helper function to find position of a node in the list
int findPosition(ListNode *head, ListNode *target)
{
    if (!target)
        return -1;

    int pos = 0;
    ListNode *current = head;
    while (current)
    {
        if (current == target)
            return pos;
        current = current->next;
        pos++;
    }
    return -1;
}

int main()
{
    Solution solution;

    // Test case 1: No cycle [3,2,0,-4]
    cout << "Test 1 - No cycle: ";
    int arr1[] = {3, 2, 0, -4};
    ListNode *head1 = createLinearList(arr1, 4);
    printList(head1);

    ListNode *cycleStart1 = solution.detectCycle(head1);
    cout << "Cycle starts at: " << (cycleStart1 ? to_string(cycleStart1->val) : "NULL") << endl;
    cout << "Expected: NULL" << endl
         << endl;

    // Test case 2: Cycle at position 1 [3,2,0,-4] -> cycle from -4 to 2
    cout << "Test 2 - Cycle at position 1: ";
    int arr2[] = {3, 2, 0, -4};
    ListNode *head2 = createCyclicList(arr2, 4, 1);
    cout << "3 -> 2 -> 0 -> -4 -> (back to 2)" << endl;

    ListNode *cycleStart2 = solution.detectCycle(head2);
    cout << "Cycle starts at: " << (cycleStart2 ? to_string(cycleStart2->val) : "NULL") << endl;
    cout << "Expected: 2 (position 1)" << endl
         << endl;

    // Test case 3: Cycle at position 0 [1,2] -> cycle from 2 to 1
    cout << "Test 3 - Cycle at position 0: ";
    int arr3[] = {1, 2};
    ListNode *head3 = createCyclicList(arr3, 2, 0);
    cout << "1 -> 2 -> (back to 1)" << endl;

    ListNode *cycleStart3 = solution.detectCycle(head3);
    cout << "Cycle starts at: " << (cycleStart3 ? to_string(cycleStart3->val) : "NULL") << endl;
    cout << "Expected: 1 (position 0)" << endl
         << endl;

    // Test case 4: Single node with cycle [1] -> cycle to itself
    cout << "Test 4 - Single node with cycle: ";
    ListNode *head4 = new ListNode(1);
    head4->next = head4; // Point to itself
    cout << "1 -> (back to 1)" << endl;

    ListNode *cycleStart4 = solution.detectCycle(head4);
    cout << "Cycle starts at: " << (cycleStart4 ? to_string(cycleStart4->val) : "NULL") << endl;
    cout << "Expected: 1 (position 0)" << endl
         << endl;

    // Test case 5: Empty list
    cout << "Test 5 - Empty list: ";
    ListNode *head5 = nullptr;
    cout << "NULL" << endl;

    ListNode *cycleStart5 = solution.detectCycle(head5);
    cout << "Cycle starts at: " << (cycleStart5 ? to_string(cycleStart5->val) : "NULL") << endl;
    cout << "Expected: NULL" << endl;

    return 0;
}
