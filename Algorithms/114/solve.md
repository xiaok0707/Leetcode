## 思路

这道题技巧性较强，如果不使用额外空间，可以通过以下迭代的方式完成对二叉树的修改：

1. 若当前根有左子树，则找到当前根的左子树中最右边的结点most_right
2. 将根的右子树修改成most_right的右子树，将根的右子树丢弃（修改成指向左子树）
3. 继续遍历下一根结点（root=root->right）

把根的右子树作为most_right的右子树，这样做仍然可以保持树的前序遍历顺序不被打乱.


### C++

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root){
            if(root->left){
                TreeNode* most_right=root->left;
                while(most_right->right) most_right=most_right->right;
                most_right->right=root->right;
                root->right=root->left;
                root->left=NULL;
            }
            root=root->right;
        }
    }
};
```

