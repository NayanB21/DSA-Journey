/* Q.You are given the heads of two sorted linked lists list1 and list2.

     Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

     Return the head of the merged linked list.
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
    ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
    {
        // base-case
        if (head1 == NULL || head2 == NULL)
        {
            return head1 == NULL ? head2 : head1; // ternary statement
        }

        // main recursive logic
        if (head1->val <= head2->val)
        {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }

        else
        {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
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
        cout << "NULL";
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

int main()
{
    Solution solution;

    // Test case 1: Both lists have multiple elements [1,2,4] and [1,3,4]
    cout << "Test 1 - Both lists multiple elements:" << endl;
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    ListNode *list1 = createList(arr1, 3);
    ListNode *list2 = createList(arr2, 3);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    ListNode *merged1 = solution.mergeTwoLists(list1, list2);
    cout << "Merged: ";
    printList(merged1);
    cout << "Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4" << endl
         << endl;

    // Test case 2: One list is empty [] and [0]
    cout << "Test 2 - One list empty:" << endl;
    ListNode *list3 = nullptr;
    int arr4[] = {0};
    ListNode *list4 = createList(arr4, 1);

    cout << "List 1: ";
    printList(list3);
    cout << "List 2: ";
    printList(list4);

    ListNode *merged2 = solution.mergeTwoLists(list3, list4);
    cout << "Merged: ";
    printList(merged2);
    cout << "Expected: 0" << endl
         << endl;

    // Test case 3: Both lists are empty [] and []
    cout << "Test 3 - Both lists empty:" << endl;
    ListNode *list5 = nullptr;
    ListNode *list6 = nullptr;

    cout << "List 1: ";
    printList(list5);
    cout << "List 2: ";
    printList(list6);

    ListNode *merged3 = solution.mergeTwoLists(list5, list6);
    cout << "Merged: ";
    printList(merged3);
    cout << "Expected: NULL" << endl
         << endl;

    // Test case 4: Different lengths [1,2,3,4,5] and [6,7]
    cout << "Test 4 - Different lengths:" << endl;
    int arr7[] = {1, 2, 3, 4, 5};
    int arr8[] = {6, 7};
    ListNode *list7 = createList(arr7, 5);
    ListNode *list8 = createList(arr8, 2);

    cout << "List 1: ";
    printList(list7);
    cout << "List 2: ";
    printList(list8);

    ListNode *merged4 = solution.mergeTwoLists(list7, list8);
    cout << "Merged: ";
    printList(merged4);
    cout << "Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7" << endl
         << endl;

    // Test case 5: Single elements [5] and [1]
    cout << "Test 5 - Single elements:" << endl;
    int arr9[] = {5};
    int arr10[] = {1};
    ListNode *list9 = createList(arr9, 1);
    ListNode *list10 = createList(arr10, 1);

    cout << "List 1: ";
    printList(list9);
    cout << "List 2: ";
    printList(list10);

    ListNode *merged5 = solution.mergeTwoLists(list9, list10);
    cout << "Merged: ";
    printList(merged5);
    cout << "Expected: 1 -> 5" << endl;

    return 0;
}