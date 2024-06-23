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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* temp = head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(n==1){
            temp=head;
            while(temp!=NULL){
                if(temp->next->next==NULL){
                    temp->next=NULL;
                    return head;
                }
                temp=temp->next;
            }
        }
        int k=cnt-n+1;
        if(k==1){
            head=head->next;
            return head;
        }
        int counter=0;
        temp=head;
        while(temp!=NULL){
            counter++;
            if(counter==k-1){

                ListNode* prev=temp;
                prev->next=prev->next->next;
                return head;
            }

            temp=temp->next;
        }
        return NULL;
    }
};