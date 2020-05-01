## 思路

前序遍历序列的首个元素是当前树的根，在中序遍历序列中找到这一项，由于中序遍历是先左后根然后才是右，所以在中序遍历序列中，这一项的左边是所有左子树的结点，右边是所有右子树的结点，对于左右子树，它们又可以看成规模更小但是完全相同的问题，因此根据这一点递归求解即可.

### Python

```python
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
```

