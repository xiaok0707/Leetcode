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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        while(head){
            ListNode* nxthead=head->next;
            ListNode* pre=dummy,*cur=pre->next;
            while(cur && cur->val<head->val){
                pre=cur;
                cur=cur->next;
            }
            pre->next=head;
            head->next=cur;
            head=nxthead;
        }
        return dummy->next;
    }
};