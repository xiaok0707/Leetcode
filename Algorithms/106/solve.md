## 思路

后序遍历序列的末尾元素是当前树的根，在中序遍历序列中找到这一项，由于中序遍历是先左后根然后才是右，所以在中序遍历序列中，这一项的左边是所有左子树的结点，右边是所有右子树的结点，对于左右子树，它们又可以看成规模更小但是完全相同的问题，因此根据这一点递归求解即可.

### Python

```python
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
```

