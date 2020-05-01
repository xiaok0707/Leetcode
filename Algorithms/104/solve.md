## 思路

DFS或BFS都可以，记录当前结点的高度.


### C++

```c++
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> que;
        int floor=0;
        que.push(root);
        while(!que.empty()){
            int len=que.size();
            for(int i=0;i<len;++i){
                TreeNode* x=que.front();que.pop();
                if(x->left) que.push(x->left);
                if(x->right) que.push(x->right);
            }
            floor+=1;
        }
        return floor;
    }
};
```

