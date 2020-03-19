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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(1==k) return head;
        ListNode* le=head,*pre,*cur,*res=NULL,*tmp;
        while(1){
            pre=le;
            cur=pre->next;
            for(int i=0;i<k-1;++i){
                tmp=cur->next;
                cur->next=pre;
                pre=cur;
                cur=tmp;
            }
            if(!res) res=pre;
            bool flag=false;
            for(int i=0;i<k-1;++i){
                if(!tmp){
                    flag=true;
                    break;
                }
                tmp=tmp->next;
            }
            if(!tmp) flag=true;
            if(flag){
                le->next=cur;
                break;
            }
            else{
                le->next=tmp;
                le=cur;
            }
        }
        return res;
    }
};