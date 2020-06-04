/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        if(!head->next) return NULL;
        ListNode *slow=head->next,*fast=slow->next;
        while(fast && slow!=fast){
            slow=slow->next;
            fast=fast->next;
            if(!fast) return NULL;
            fast=fast->next;
        }
        if(!fast) return NULL;
        fast=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};