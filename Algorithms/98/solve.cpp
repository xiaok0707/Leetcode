/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef long long ll;
const ll inf=1e18;

struct Node{
    ll Max,Min;
    bool isBST;
    Node(ll Ma,ll Mi,bool is):Max(Ma),Min(Mi),isBST(is){}
};

class Solution {
public:
    Node dfs(TreeNode* rt){
        if(!rt) return Node(-inf,inf,true);
        Node le=dfs(rt->left);
        Node ri=dfs(rt->right);
        ll Max=max(max(le.Max,ri.Max),1LL*rt->val);
        ll Min=min(min(le.Min,ri.Min),1LL*rt->val);
        bool isBST=le.isBST && ri.isBST && (le.Max<rt->val) && (ri.Min>rt->val);
        return Node(Max,Min,isBST);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root).isBST;
    }
};