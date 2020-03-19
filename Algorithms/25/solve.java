/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(1==k) return head;
        ListNode le=head,res=null;
        while(true){
            ListNode pre=le,cur=pre.next,tmp=null;
            for(int i=0;i<k-1;++i){
                tmp=cur.next;
                cur.next=pre;
                pre=cur;
                cur=tmp;
            }
            if(res==null) res=pre;
            boolean flag=false;
            for(int i=0;i<k-1;++i){
                if(tmp==null){
                    flag=true;
                    break;
                }
                tmp=tmp.next;
            }
            if(tmp==null) flag=true;
            if(flag){
                le.next=cur;
                break;
            }
            else{
                le.next=tmp;
                le=cur;
            }
        }
        return res;
    }
}