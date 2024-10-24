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
    ListNode* partition(ListNode* head, int x) {

        struct ListNode* left = new ListNode(0);
        struct ListNode* right = new ListNode(0);
        struct ListNode* lres = left;
        struct ListNode* rres = right;
        while(head!=NULL){
            if(head->val<x){
                left->next = head;
                left = left->next;
            }
            else{
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        right->next = NULL;
        left->next = rres->next;
        return lres->next;
    }
};