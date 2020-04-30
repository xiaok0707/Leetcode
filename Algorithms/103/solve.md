## 思路

用一个变量记录层数，使用队列BFS，层数为奇数时将该层BFS序列翻转.

### Python

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None: return []
        que,ans,floor=[root],[],0
        while len(que)>0:
            sz,res=len(que),[]
            for i in range(sz):
                tp=que.pop(0)
                res.append(tp.val)
                if tp.left: que.append(tp.left)
                if tp.right: que.append(tp.right)
            if floor%2==1: res=res[::-1]
            ans.append(res)
            floor+=1
        return ans
```

