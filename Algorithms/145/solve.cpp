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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(st.size()){
            TreeNode* cur=st.top();st.pop();
            if(cur){
                st.push(cur);
                st.push(NULL);
                if(cur->right) st.push(cur->right);
                if(cur->left) st.push(cur->left);
            }
            else{
                ans.push_back(st.top()->val);
                st.pop();
            }
        }
        return ans;
    }
};