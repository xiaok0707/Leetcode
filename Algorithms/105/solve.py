# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:

        def solve(pl,pr,il,ir):
            if pl>pr: return None
            rt=TreeNode(preorder[pl])
            i=il
            while i<ir and inorder[i]!=preorder[pl]: i+=1
            rt.left=solve(pl+1,pl+i-il,il,i-1)
            rt.right=solve(pl+i-il+1,pr,i+1,ir)
            return rt

        return solve(0,len(preorder)-1,0,len(inorder)-1)