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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt=0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp=temp->next;
        }
        temp=head;
        int mid=cnt/2;
        cnt=0;
        if (mid == 0) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }
        while(cnt<mid-1){
            cnt++;
            temp=temp->next;
        }
        ListNode* del = temp->next;
        temp->next = temp->next ->next;
        delete del;
        return head;
    }
};