# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:

        def dfs(rt):
            nonlocal maxpath
            if rt is None: return float('-inf')
            le=max(0,dfs(rt.left))
            ri=max(0,dfs(rt.right))
            maxpath=max(maxpath,le+ri+rt.val)
            return max(le,ri)+rt.val

        maxpath=float('-inf')
        dfs(root)
        return maxpath