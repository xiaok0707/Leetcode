# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if 1==k:
            return head
        le,res=head,None
        while True:
            pre=le
            cur=pre.next
            for i in range(k-1):
                tmp=cur.next
                cur.next=pre
                pre=cur
                cur=tmp
            if res==None:
                res=pre
            flag=False
            for i in range(k-1):
                if tmp==None:
                    flag=True
                    break
                tmp=tmp.next
            if tmp==None:
                flag=True
            if flag:
                le.next=cur
                break
            else:
                le.next=tmp
                le=cur
        return res