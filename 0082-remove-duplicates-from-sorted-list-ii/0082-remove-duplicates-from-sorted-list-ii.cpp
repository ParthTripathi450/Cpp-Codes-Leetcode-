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
    ListNode* deleteDuplicates(ListNode* head) {
       if(!head)return NULL;
       ListNode *dummy=new ListNode(-1);
       ListNode *h=dummy;
       while(head){
           if(head->next&&head->val==head->next->val){
               while(head->next&&head->val==head->next->val){
                   head=head->next;
               }
               if(!head->next){
                   break;
               }
            }
            else{
                h->next=head;
                h=h->next;
            }
            head=head->next;
        }
        if(h)h->next=NULL;
        return dummy->next;
    }
};