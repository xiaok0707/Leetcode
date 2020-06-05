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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur=root;
        while(cur || st.size()){
            while(cur){
                ans.push_back(cur->val);
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();st.pop();
            cur=cur->right;
        }
        return ans;
    }
};