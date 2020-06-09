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
    ListNode* mergeSortedList(ListNode* A,ListNode* B){
        ListNode* dummy=new ListNode(0),*last=dummy;
        while(A && B){
            if(A->val<B->val){
                ListNode* nxtA=A->next;
                A->next=last->next;
                last->next=A;
                last=A;
                A=nxtA;
            }
            else{
                ListNode* nxtB=B->next;
                B->next=last->next;
                last->next=B;
                last=B;
                B=nxtB;
            }
        }
        if(A) last->next=A;
        if(B) last->next=B;
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        int len=0;
        ListNode *pre=NULL,*cur=head;
        while(cur) { ++len;cur=cur->next; }
        cur=head;
        for(int i=0;i<len/2;++i) { pre=cur;cur=cur->next; }
        pre->next=NULL;
        ListNode* A=sortList(head);
        ListNode* B=sortList(cur);
        return mergeSortedList(A,B);
    }
};