/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy=new ListNode(0),cur=head;
        dummy.next=head;
        int len=0;
        while(cur!=null){
            ++len;
            cur=cur.next;
        }
        len-=n;
        cur=dummy;
        while(len>0){
            --len;
            cur=cur.next;
        }
        cur.next=cur.next.next;
        return dummy.next;
    }
}