# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy=ListNode(0)
        dummy.next=head
        le,ri=dummy,dummy
        for i in range(n+1):
            ri=ri.next
        while ri!=None:
            le=le.next
            ri=ri.next
        le.next=le.next.next
        return dummy.next