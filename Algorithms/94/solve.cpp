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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur=root;
        stack<TreeNode*> st;
        while(cur!=NULL || st.size()){
            while(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();st.pop();
            ans.push_back(cur->val);
            cur=cur->right;
        }
        return ans;
    }
};