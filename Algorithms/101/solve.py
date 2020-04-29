# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None: return True
        if root.left is None and root.right is None: return True
        if root.left is None or root.right is None: return False
        que=[root.left,root.right]
        while len(que)>0:
            p=que.pop()
            q=que.pop()
            if p is None and q is None: continue
            if p is None or q is None: return False
            if p.val!=q.val: return False
            que.append(p.left)
            que.append(q.right)
            que.append(p.right)
            que.append(q.left)
        return True