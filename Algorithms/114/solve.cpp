/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root){
            if(root->left){
                TreeNode* most_right=root->left;
                while(most_right->right) most_right=most_right->right;
                most_right->right=root->right;
                root->right=root->left;
                root->left=NULL;
            }
            root=root->right;
        }
    }
};