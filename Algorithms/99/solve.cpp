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
    vector<int> a;

    void getmid(TreeNode* root){
        if(!root) return;
        getmid(root->left);
        a.push_back(root->val);
        getmid(root->right);
    }

    void update(TreeNode* root,int x,int y){
        if(!root) return;
        if(root->val==x || root->val==y)
            root->val=(root->val==x)?y:x;
        update(root->left,x,y);
        update(root->right,x,y);
    }

    void recoverTree(TreeNode* root) {
        getmid(root);
        int x=-1,y;
        for(int i=0;i+1<(int)a.size();++i){
            if(a[i]>a[i+1]){
                y=a[i+1];
                if(x==-1) x=a[i];
                else break;
            }
        }
        update(root,x,y);
    }
};