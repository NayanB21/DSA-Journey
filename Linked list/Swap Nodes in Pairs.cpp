/* Q. Given a linked list, swap every two adjacent nodes and return its head.
     You must solve the problem without modifying the values in the list's nodes
     (i.e., only nodes themselves may be changed.)

     Example: [1,2,3,4] becomes [2,1,4,3]
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *ans = head->next;
        ListNode *joint; // also can use vector here,to store joints

        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *next = curr->next;

        while (1)
        {
            curr->next = prev;
            if (next == NULL)
            {
                prev->next = NULL;
                break;
            }
            if (next->next == NULL)
            {
                prev->next = next;
                break;
            }

            joint = prev;
            prev = next;
            curr = next->next;
            next = next->next->next;
            joint->next = curr;
        }

        return ans;
    }
};

// Helper function to create a linked list from array
ListNode *createList(int arr[], int size)
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

// Helper function to print linked list
void printList(ListNode *head)
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
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to get list length
int getLength(ListNode *head)
{
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}

int main()
{
    Solution solution;

    // Test case 1: [1,2,3,4] - Even number of nodes
    cout << "Test 1 - Even number of nodes:" << endl;
    int arr1[] = {1, 2, 3, 4};
    ListNode *head1 = createList(arr1, 4);

    cout << "Original: ";
    printList(head1);

    ListNode *result1 = solution.swapPairs(head1);
    cout << "After swapping pairs: ";
    printList(result1);
    cout << "Expected: 2 -> 1 -> 4 -> 3" << endl
         << endl;

    // Test case 2: [1,2,3,4,5] - Odd number of nodes
    cout << "Test 2 - Odd number of nodes:" << endl;
    int arr2[] = {1, 2, 3, 4, 5};
    ListNode *head2 = createList(arr2, 5);

    cout << "Original: ";
    printList(head2);

    ListNode *result2 = solution.swapPairs(head2);
    cout << "After swapping pairs: ";
    printList(result2);
    cout << "Expected: 2 -> 1 -> 4 -> 3 -> 5" << endl
         << endl;

    // Test case 3: [1] - Single node
    cout << "Test 3 - Single node:" << endl;
    int arr3[] = {1};
    ListNode *head3 = createList(arr3, 1);

    cout << "Original: ";
    printList(head3);

    ListNode *result3 = solution.swapPairs(head3);
    cout << "After swapping pairs: ";
    printList(result3);
    cout << "Expected: 1" << endl
         << endl;

    // Test case 4: [] - Empty list
    cout << "Test 4 - Empty list:" << endl;
    ListNode *head4 = nullptr;

    cout << "Original: ";
    printList(head4);

    ListNode *result4 = solution.swapPairs(head4);
    cout << "After swapping pairs: ";
    printList(result4);
    cout << "Expected: NULL" << endl
         << endl;

    // Test case 5: [1,2] - Two nodes only
    cout << "Test 5 - Two nodes only:" << endl;
    int arr5[] = {1, 2};
    ListNode *head5 = createList(arr5, 2);

    cout << "Original: ";
    printList(head5);

    ListNode *result5 = solution.swapPairs(head5);
    cout << "After swapping pairs: ";
    printList(result5);
    cout << "Expected: 2 -> 1" << endl;

    return 0;
}