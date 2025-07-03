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
    ListNode *reverseList(ListNode *head)
    {

        ListNode *h1 = head;
        if (h1 == NULL || h1->next == NULL)
            return head;
        ListNode *h2 = head->next;
        h1->next = NULL;
        while (h2 != NULL)
        {
            ListNode *h3 = h2->next;
            h2->next = h1;
            h1 = h2;
            h2 = h3;
        }
        return h1;
    }
};

int main()
{
    // Test the solution
    Solution solution;

    // Create a test linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print original list
    cout << "Original: ";
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Reverse the list
    ListNode *reversed = solution.reverseList(head);

    // Print reversed list
    cout << "Reversed: ";
    temp = reversed;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
