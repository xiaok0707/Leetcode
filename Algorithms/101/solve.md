## 思路

递归直接判断.


### C++

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* p,TreeNode* q){
        if(!p) return !q;
        if(!q) return !p;
        return p->val==q->val && check(p->left,q->right) && check(p->right,q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left,root->right);
    }
};
```

也可以迭代，利用BFS的思想，每次从队列中取两个元素出来，分别对应原来树上两个对称的位置，比较它们的值，然后把它们的左右子结点以相反的顺序加入队列.

### Python

```python
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
```

