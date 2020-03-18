# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        pre,cur,res=head,head.next,head.next
        while True:
            tmp=cur.next
            cur.next=pre
            if not tmp or not tmp.next:
                pre.next=tmp
                break
            pre.next=tmp.next
            pre=tmp
            cur=pre.next
        return res