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
        if (head==NULL) return NULL;
        struct ListNode* temp = head->next;
        struct ListNode* prev = head;
        int key = 0;
        while(temp!=NULL){
            if(prev->val == temp->val){
                key = temp->val;
                while(temp!=NULL && temp->val == key){
                    temp = temp->next;
                }
                prev->next = temp;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};