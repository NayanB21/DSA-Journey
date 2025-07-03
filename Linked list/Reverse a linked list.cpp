/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
            
            ListNode* h1=head;
            if(h1==NULL||h1->next==NULL)return head;
            ListNode* h2=head->next;
            h1->next=NULL;
            while(h2!=NULL){
                ListNode* h3=h2->next;
                h2->next=h1;
                h1=h2;
                h2=h3;


            }
            return h1;




    }
       
};
