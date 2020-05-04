## 思路

递归搜索记录答案即可.


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
    int ans=0x7fffffff;

    void dfs(TreeNode* rt,int dep){
        if(!rt->left && !rt->right){
            ans=min(ans,dep);
            return;
        }
        if(rt->left) dfs(rt->left,dep+1);
        if(rt->right) dfs(rt->right,dep+1);
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root,1);
        return ans;
    }
};
```

