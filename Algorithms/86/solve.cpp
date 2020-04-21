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
    ListNode* partition(ListNode* head, int x) {
        ListNode *newhead=NULL,*cur=head,*newtail=NULL;
        while(cur){
            if(cur->val<x){
                ListNode *p=new ListNode(cur->val);
                if(!newhead) newhead=newtail=p;
                else{
                    newtail->next=p;
                    newtail=p;
                }
            }
            cur=cur->next;
        }
        cur=head;
        while(cur){
            if(cur->val>=x){
                ListNode *p=new ListNode(cur->val);
                if(!newhead) newhead=newtail=p;
                else{
                    newtail->next=p;
                    newtail=p;
                }
            }
            cur=cur->next;
        }
        return newhead;
    }
};