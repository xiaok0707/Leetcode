# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        p1=l1
        p2=l2
        pre=ListNode(0)
        head=pre
        flag=0
        while p1!=None and p2!=None:
            x=p1.val+p2.val+flag
            flag=x//10;
            cur=ListNode(x%10)
            pre.next=cur
            pre=cur
            p1=p1.next
            p2=p2.next
        while p1!=None:
            x=p1.val+flag
            flag=x//10;
            cur=ListNode(x%10)
            pre.next=cur
            pre=cur
            p1=p1.next
        while p2!=None:
            x=p2.val+flag
            flag=x//10
            cur=ListNode(x%10)
            pre.next=cur
            pre=cur
            p2=p2.next
        if flag!=0:
            cur=ListNode(flag)
            pre.next=cur
        return head.next