# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:

        def dfs(rt):
            if rt is None: return [True,0]
            leBalance,leheight=dfs(rt.left)
            riBalance,riheight=dfs(rt.right)

            if abs(leheight-riheight)<=1 and leBalance and riBalance:
                return [True,max(leheight,riheight)+1]
            else:
                return [False,max(leheight,riheight)+1]

        return dfs(root)[0]