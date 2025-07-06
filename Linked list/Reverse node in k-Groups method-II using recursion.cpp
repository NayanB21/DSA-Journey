/* Q. Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
     k is a positive integer and is less than or equal to the length of the linked list.
     If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

     You may not alter the values in the list's nodes, only nodes themselves may be changed.

     This is the RECURSIVE approach to solve the problem.
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = head;

        int size = 0;
        while (temp)
        {
            size++;
            temp = temp->next;
        }

        if (size < k)
            return head;

        ListNode *start = head;

        temp = head->next;
        ListNode *prev = head;
        ListNode *next = temp->next;

        for (int i = 1; i < k; i++)
        {
            if (temp)
                temp->next = prev;
            prev = temp;
            temp = next;
            if (next)
                next = next->next;
        }

        ListNode *joint = reverseKGroup(temp, k);
        start->next = joint;
        return prev;
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

    // Test case 1: [1,2,3,4,5] with k=2
    cout << "Test 1 - k=2, list length 5 (recursive approach):" << endl;
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode *head1 = createList(arr1, 5);

    cout << "Original: ";
    printList(head1);

    ListNode *result1 = solution.reverseKGroup(head1, 2);
    cout << "Reversed in groups of 2: ";
    printList(result1);
    cout << "Expected: 2 -> 1 -> 4 -> 3 -> 5" << endl
         << endl;

    // Test case 2: [1,2,3,4,5] with k=3
    cout << "Test 2 - k=3, list length 5 (recursive approach):" << endl;
    int arr2[] = {1, 2, 3, 4, 5};
    ListNode *head2 = createList(arr2, 5);

    cout << "Original: ";
    printList(head2);

    ListNode *result2 = solution.reverseKGroup(head2, 3);
    cout << "Reversed in groups of 3: ";
    printList(result2);
    cout << "Expected: 3 -> 2 -> 1 -> 4 -> 5" << endl
         << endl;

    // Test case 3: [1,2,3,4,5,6] with k=3
    cout << "Test 3 - k=3, list length 6 (exact multiple, recursive):" << endl;
    int arr3[] = {1, 2, 3, 4, 5, 6};
    ListNode *head3 = createList(arr3, 6);

    cout << "Original: ";
    printList(head3);

    ListNode *result3 = solution.reverseKGroup(head3, 3);
    cout << "Reversed in groups of 3: ";
    printList(result3);
    cout << "Expected: 3 -> 2 -> 1 -> 6 -> 5 -> 4" << endl
         << endl;

    // Test case 4: [1] with k=1
    cout << "Test 4 - Single node, k=1 (recursive approach):" << endl;
    int arr4[] = {1};
    ListNode *head4 = createList(arr4, 1);

    cout << "Original: ";
    printList(head4);

    ListNode *result4 = solution.reverseKGroup(head4, 1);
    cout << "Reversed in groups of 1: ";
    printList(result4);
    cout << "Expected: 1" << endl
         << endl;

    // Test case 5: [1,2,3,4,5,6,7,8] with k=4
    cout << "Test 5 - k=4, list length 8 (exact multiple, recursive):" << endl;
    int arr5[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *head5 = createList(arr5, 8);

    cout << "Original: ";
    printList(head5);

    ListNode *result5 = solution.reverseKGroup(head5, 4);
    cout << "Reversed in groups of 4: ";
    printList(result5);
    cout << "Expected: 4 -> 3 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5" << endl;

    return 0;
}