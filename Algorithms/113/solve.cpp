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
    int target;
    vector<int> cur;
    vector<vector<int>> ans;

    void dfs(TreeNode*rt,int val){
        cur.push_back(rt->val);
        if(!rt->left && !rt->right){
            if(val==target) ans.push_back(cur);
        }
        else{
            if(rt->left) dfs(rt->left,val+rt->left->val);
            if(rt->right) dfs(rt->right,val+rt->right->val);
        }
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        target=sum;
        if(root) dfs(root,root->val);
        return ans;
    }
};