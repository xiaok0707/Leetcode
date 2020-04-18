/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
const int inf=2e9;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre=NULL,*cur=head;
        ListNode *newhead=NULL,*newpre=NULL;
        while(cur){
            int a=-inf,b=cur->val,c=inf;
            if(pre) a=pre->val;
            if(cur->next) c=cur->next->val;
            if(a!=b && b!=c){
                ListNode *newcur=new ListNode(b);
                if(newhead){
                    newpre->next=newcur;
                    newpre=newcur;
                }
                else{
                    newhead=newcur;
                    newpre=newcur;
                }
            }
            pre=cur;
            cur=cur->next;
        }
        return newhead;
    }
};