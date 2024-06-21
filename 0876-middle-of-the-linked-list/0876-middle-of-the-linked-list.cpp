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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        if(head==NULL) return NULL;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        cnt=cnt/2+1;
        int num=0;
        temp=head;
        while(num+1!=cnt){
            num++;
            temp=temp->next;
        }
        head=temp;
        return head;    
    }
};