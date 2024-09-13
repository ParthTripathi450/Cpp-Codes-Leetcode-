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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        else{
            struct ListNode* temp = head;
            struct ListNode* prev = NULL;
            while(head!=NULL && head->val == val){
                head = temp->next;
                temp = temp->next;
            }
            while(temp!=NULL){
                if(temp->val == val){
                    while(temp!=NULL && temp->val == val) temp = temp->next;
                    prev->next=temp;
                }
                else{
                    prev = temp;
                    temp = temp->next;
                }
             
            }
        }
        return head;
    }
};