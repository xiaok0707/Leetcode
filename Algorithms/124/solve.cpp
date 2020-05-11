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