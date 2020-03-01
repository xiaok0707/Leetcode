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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1=l1,*p2=l2,*head,*pre,*cur;
        int flag=0;
        pre=new ListNode(0);
        head=pre;
        while(p1 && p2){
            int x=(p1->val)+(p2->val)+flag;
            flag=x/10;
            cur=new ListNode(x%10);
            pre->next=cur;
            pre=cur;
            p1=p1->next;
            p2=p2->next;
        }
        while(p1){
            int x=(p1->val)+flag;
            flag=x/10;
            cur=new ListNode(x%10);
            pre->next=cur;
            pre=cur;
            p1=p1->next;
        }
        while(p2){
            int x=(p2->val)+flag;
            flag=x/10;
            cur=new ListNode(x%10);
            pre->next=cur;
            pre=cur;
            p2=p2->next;
        }
        if(flag){
            cur=new ListNode(flag);
            pre->next=cur;
        }
        return head->next;
    }
};