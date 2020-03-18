/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode pre=head,cur=head.next,res=cur;
        while(true){
            ListNode tmp=cur.next;
            cur.next=pre;
            if(tmp==null || tmp.next==null){
                pre.next=tmp;
                break;
            }
            pre.next=tmp.next;
            pre=tmp;
            cur=pre.next;
        }
        return res;
    }
}