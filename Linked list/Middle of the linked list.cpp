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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        while (head != NULL && head->next != NULL)
        {
            head = head->next->next;
            temp = temp->next;
        }
        return temp;
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

    // Test case 1: Odd number of nodes [1,2,3,4,5]
    cout << "Test 1 - Odd length list: ";
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode *head1 = createList(arr1, 5);
    printList(head1);

    ListNode *middle1 = solution.middleNode(head1);
    cout << "Middle node: " << middle1->val << endl;
    cout << "Expected: 3" << endl
         << endl;

    // Test case 2: Even number of nodes [1,2,3,4,5,6]
    cout << "Test 2 - Even length list: ";
    int arr2[] = {1, 2, 3, 4, 5, 6};
    ListNode *head2 = createList(arr2, 6);
    printList(head2);

    ListNode *middle2 = solution.middleNode(head2);
    cout << "Middle node: " << middle2->val << endl;
    cout << "Expected: 4 (second middle)" << endl
         << endl;

    // Test case 3: Single node [1]
    cout << "Test 3 - Single node: ";
    int arr3[] = {1};
    ListNode *head3 = createList(arr3, 1);
    printList(head3);

    ListNode *middle3 = solution.middleNode(head3);
    cout << "Middle node: " << middle3->val << endl;
    cout << "Expected: 1" << endl
         << endl;

    // Test case 4: Two nodes [1,2]
    cout << "Test 4 - Two nodes: ";
    int arr4[] = {1, 2};
    ListNode *head4 = createList(arr4, 2);
    printList(head4);

    ListNode *middle4 = solution.middleNode(head4);
    cout << "Middle node: " << middle4->val << endl;
    cout << "Expected: 2 (second middle)" << endl;

    return 0;
}