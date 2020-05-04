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
    bool ok=false;
    int target;

    void dfs(TreeNode* rt){
        if(!rt->left && !rt->right){
            if(rt->val==target) ok=true;
            return;
        }
        if(ok) return;

        if(rt->left){
            rt->left->val+=rt->val;
            dfs(rt->left);
        }
        if(rt->right){
            rt->right->val+=rt->val;
            dfs(rt->right);
        }
    }

    bool hasPathSum(TreeNode* root, int sum) {
        target=sum;
        if(root) dfs(root);
        return ok;
    }
};