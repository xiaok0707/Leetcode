## 思路

递归考虑问题，要求一颗根结点是 $root$ 二叉树的最大路径和，树中的最大路径可能有以下三种情况：

1. 最大路径出现在 $root->left$ ，即出现在左子树，和根以及右子树无关
2. 最大路径出现在 $root->right$，即出现在右子树，和根以及左子树无关
3. 最大路径包含根 $root->val$，且分别在左右子树 $root->left,root->right$ 中尽量延伸使得路径和尽可能大

对于上面的3，又可以递归地解决，假设 $dp(rt)$ 表示以 $rt$ 为根的二叉树中，从 $rt$ 出发，能得到的最大路径和，则：

$dp(rt)=max(dp(rt->left),dp(rt->right),0)+rt->val$

根据这一递推式，先 dfs 一遍整个树求出每个结点的 $dp$ 值，然后再递归求解原问题的答案.


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
    unordered_map<TreeNode*,int> dp;
    
    int dfs(TreeNode* rt){
        if(!rt) return INT_MIN;
        int ans=max(max(dfs(rt->left),dfs(rt->right)),0)+rt->val;
        return dp[rt]=ans;
    }

    int solve(TreeNode* rt){
        if(!rt) return INT_MIN;
        int ans=max(solve(rt->left),solve(rt->right));
        ans=max(ans,rt->val+max(0,dp[rt->left])+max(0,dp[rt->right]));
        return ans;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return solve(root);
    }
};
```

也可以只进行一次递归，$dfs(rt)$ 返回以 $rt$ 为根的二叉树中，从 $rt$ 出发，能得到的最大路径和. 每次除了 $dfs(rt.left),dfs(rt.right)$ 中原本就有的路径，可以新形成一条经过 $rt$ ，跨越两个左右子树的新路径，这样在递归过程中可以搜索到所有的路径，取最大值即可.

### Python

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:

        def dfs(rt):
            nonlocal maxpath
            if rt is None: return float('-inf')
            le=max(0,dfs(rt.left))
            ri=max(0,dfs(rt.right))
            maxpath=max(maxpath,le+ri+rt.val)
            return max(le,ri)+rt.val

        maxpath=float('-inf')
        dfs(root)
        return maxpath
```

