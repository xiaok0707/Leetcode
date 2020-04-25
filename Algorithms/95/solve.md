## 思路

递归思路不太好想，递归函数 $generate\_Trees(le,ri)$ 返回一个列表，这个列表包含了所有 $ri-le+1$ 个结点对应的二叉树，同时 $[le,ri]$ 对应着树上结点的值，每个值只出现一次.

很明显，$Ans=generate\_Trees(1,n)$，函数内部遍历 $i \in [le,ri]$ ，每次把 $i$ 作为根，然后将 $[le,i-1]$ 作为左子树部分，$[i+1,ri]$ 作为右子树部分，继续递归求解 $generate\_Trees(le,i-1)，generate\_Trees(i+1,ri)$，然后双重循环遍历这两个列表，将根与左右子树相连，返回当前的结果.


### C++

```c++
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
```

