/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode merge2Lists(ListNode l1,ListNode l2) {
        ListNode dummy=new ListNode(0),cur=dummy;
        while(l1!=null && l2!=null){
            if(l1.val<l2.val){
                cur.next=l1;
                l1=l1.next;
            }
            else{
                cur.next=l2;
                l2=l2.next;
            }
            cur=cur.next;
        }
        cur.next=l1!=null?l1:l2;
        return dummy.next;
    }
    
    public ListNode mergeKLists(ListNode[] lists) {
        int len=lists.length;
        int interval=1;
        while(interval<len){
            for(int i=0;i+interval<len;i+=interval*2){
                lists[i]=merge2Lists(lists[i],lists[i+interval]);
            }
            interval*=2;
        }
        return len>0?lists[0]:null;
    }
}