# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        pre=x=y=flag=None
        while root:
            if root.left:
                flag=root.left
                while flag.right and flag.right!=root:
                    flag=flag.right

                if flag.right==None:
                    flag.right=root
                    root=root.left
                else:
                    if pre and pre.val>root.val:
                        y=root
                        if not x: x=pre
                    pre=root
                    flag.right=None
                    root=root.right

            else:
                if pre and pre.val>root.val:
                    y=root
                    if not x: x=pre
                pre=root
                root=root.right
                
        x.val,y.val=y.val,x.val