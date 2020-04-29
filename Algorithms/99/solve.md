## 思路

**不含重复元素的二叉搜索树的中序遍历序列是严格递增的**，根据这一点，我们可以预处理得到中序遍历序列，此时该序列的状态是几乎排好序的，或者说是一个已排好序的数组中将其中某两个元素交换后的结果. 只要找出这两个元素，然后在树上将它们的值换回来即可.

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
    vector<int> a;

    void getmid(TreeNode* root){
        if(!root) return;
        getmid(root->left);
        a.push_back(root->val);
        getmid(root->right);
    }

    void update(TreeNode* root,int x,int y){
        if(!root) return;
        if(root->val==x || root->val==y)
            root->val=(root->val==x)?y:x;
        update(root->left,x,y);
        update(root->right,x,y);
    }

    void recoverTree(TreeNode* root) {
        getmid(root);
        int x=-1,y;
        for(int i=0;i+1<(int)a.size();++i){
            if(a[i]>a[i+1]){
                y=a[i+1];
                if(x==-1) x=a[i];
                else break;
            }
        }
        update(root,x,y);
    }
};
```

可以不用预处理出中序遍历序列，而是一边搜索，一边比较，记录单调性不正确的结点，最后交换.

### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public void recoverTree(TreeNode root) {
        Stack<TreeNode> stack=new Stack<>();
        TreeNode pre=null,x=null,y=null;
        while(root!=null || !stack.empty()){
            while(root!=null){
                stack.push(root);
                root=root.left;
            }
            TreeNode cur=stack.peek();stack.pop();
            if(pre!=null && pre.val>cur.val){
                y=cur;
                if(x==null) x=pre;
                else break;
            }
            pre=cur;
            root=cur.right;
        }
        int tmp=x.val;
        x.val=y.val;
        y.val=tmp;
    }
}
```

### Morris 中序遍历

$O(1)$ 空间复杂度，具体思想如下：

Morris 算法的思想是在节点和它的中序遍历直接前驱之间设置一个临时的链接：让前驱指向当前根。每次从该节点开始，找到它的直接前驱并验证是否存在链接。

- 如果没有链接，设置连接并走向左子树。
- 如果有连接，断开连接并走向右子树。

注意：如果该节点没有左孩子，即没有左子树，则我们直接走向右子树。

### Python

```python
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
            if root.left:#有左子树
                flag=root.left
                while flag.right and flag.right!=root:#找root的前驱
                    flag=flag.right

                if flag.right==None:#无链接则建立链接然后继续搜索左子树
                    flag.right=root
                    root=root.left
                else:#有链接说明左子树已经搞定，删除链接然后搜索右子树
                    if pre and pre.val>root.val:
                        y=root
                        if not x: x=pre
                    pre=root
                    flag.right=None
                    root=root.right

            else:#无左子树直接搜索右子树
                if pre and pre.val>root.val:
                    y=root
                    if not x: x=pre
                pre=root
                root=root.right
                
        x.val,y.val=y.val,x.val
```

