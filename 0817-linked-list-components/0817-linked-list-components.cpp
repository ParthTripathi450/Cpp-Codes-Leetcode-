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
    int numComponents(ListNode* head, vector<int>& nums) {
        struct ListNode* temp = head;
        int cnt=0;
        while(temp!= NULL){
            auto it = find(nums.begin(),nums.end(),temp->val);
            temp = temp->next;
            if( it!=nums.end() ) cnt++;
            while(temp!=NULL && it != nums.end()){
                it = find(nums.begin(),nums.end(),temp->val);
                temp = temp->next;
            }
        }
        return cnt;
    }
};