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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre=NULL,*cur=head;
        ListNode *newhead=NULL,*newpre=NULL;
        while(cur){
            if(!pre || pre->val!=cur->val){
                ListNode *newcur=new ListNode(cur->val);
                if(newhead){
                    newpre->next=newcur;
                    newpre=newcur;
                }
                else{
                    newpre=newhead=newcur;
                }
            }
            pre=cur;
            cur=cur->next;
        }
        return newhead;
    }
};