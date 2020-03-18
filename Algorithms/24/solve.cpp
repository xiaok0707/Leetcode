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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre=head,*cur=head->next,*res=head->next;
        while(1){
            ListNode* tmp=cur->next;
            cur->next=pre;
            if(!tmp || !tmp->next){
                pre->next=tmp;
                break;
            }
            pre->next=tmp->next;
            pre=tmp;
            cur=pre->next;
        }
        return res;
    }
};