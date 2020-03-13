# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy=ListNode(0)
        dummy.next=head
        cur=head
        length=0
        while cur!=None:
            length+=1
            cur=cur.next
        cur=dummy
        length-=n
        while length>0:
            length-=1
            cur=cur.next
        cur.next=cur.next.next
        return dummy.next