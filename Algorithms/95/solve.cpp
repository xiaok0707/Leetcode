class Solution {
public:
    vector<TreeNode*> generate_Trees(int le,int ri){
        vector<TreeNode*> res;
        if(le>ri){
            res.push_back(NULL);
            return res;
        }
        for(int i=le;i<=ri;++i){
            vector<TreeNode*> LNode=generate_Trees(le,i-1);
            vector<TreeNode*> RNode=generate_Trees(i+1,ri);
            for(int j=0;j<(int)LNode.size();++j){
                for(int k=0;k<(int)RNode.size();++k){
                    TreeNode* rt=new TreeNode(i);
                    rt->left=LNode[j];
                    rt->right=RNode[k];
                    res.push_back(rt);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(!n) return vector<TreeNode*>(0);
        return generate_Trees(1,n);
    }
};