/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode p1=l1,p2=l2,head,pre,cur;
        pre=new ListNode(0);
        head=pre;
        int flag=0;
        while(p1!=null && p2!=null){
            int x=p1.val+p2.val+flag;
            flag=x/10;
            cur=new ListNode(x%10);
            pre.next=cur;
            pre=cur;
            p1=p1.next;
            p2=p2.next;
        }
        while(p1!=null){
            int x=p1.val+flag;
            flag=x/10;
            cur=new ListNode(x%10);
            pre.next=cur;
            pre=cur;
            p1=p1.next;
        }
        while(p2!=null){
            int x=p2.val+flag;
            flag=x/10;
            cur=new ListNode(x%10);
            pre.next=cur;
            pre=cur;
            p2=p2.next;
        }
        if(flag!=0){
            cur=new ListNode(flag);
            pre.next=cur;
        }
        return head.next;
    }
}