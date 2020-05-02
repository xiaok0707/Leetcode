## 思路

先遍历链表得到有序数组，然后每次取中间元素为根，然后分别递归左右两部分作为左右子树.

### Python

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        nums=[]
        while head:
            nums.append(head.val)
            head=head.next
        
        def dfs(le,ri):
            if le>ri: return None
            mid=(le+ri)>>1
            rt=TreeNode(nums[mid])
            rt.left=dfs(le,mid-1)
            rt.right=dfs(mid+1,ri)
            return rt

        return dfs(0,len(nums)-1)
```

