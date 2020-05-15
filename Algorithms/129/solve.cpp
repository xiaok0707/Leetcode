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
    int ans=0;
    vector<int> nums;

    void dfs(TreeNode* rt){
        nums.push_back(rt->val);
        if(!rt->left && !rt->right){
            int cur=0;
            for(int i=0;i<(int)nums.size();++i) cur=cur*10+nums[i];
            ans+=cur;
        }
        else{
            if(rt->left) dfs(rt->left);
            if(rt->right) dfs(rt->right);
        }
        nums.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        if(root) dfs(root);
        return ans;
    }
};