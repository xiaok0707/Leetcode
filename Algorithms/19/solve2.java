/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        ListNode le=dummy,ri=dummy;
        for(int i=0;i<n+1;++i) ri=ri.next;
        while(ri!=null){
            le=le.next;
            ri=ri.next;
        }
        le.next=le.next.next;
        return dummy.next;
    }
}