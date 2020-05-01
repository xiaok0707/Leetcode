# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:

        def solve(il,ir,pl,pr):
            if il>ir: return None
            rt=TreeNode(postorder[pr])
            i=il
            while i<ir and postorder[pr]!=inorder[i]: i+=1
            rt.left=solve(il,i-1,pl,pr-ir+i-1)
            rt.right=solve(i+1,ir,pr-ir+i,pr-1)
            return rt

        return solve(0,len(inorder)-1,0,len(postorder)-1)