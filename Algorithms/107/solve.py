# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root is None: return []
        ans,que=[],[root]
        while len(que)>0:
            sz=len(que)
            tmp=[]
            for i in range(sz):
                rt=que.pop(0)
                tmp.append(rt.val)
                if rt.left: que.append(rt.left)
                if rt.right: que.append(rt.right)
            ans.append(tmp)
        return ans[::-1]