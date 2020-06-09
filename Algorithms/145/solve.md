## 思路

投机取巧的办法：可以直接求逆前序遍历序列（就是按照根—>右—>左的顺序遍历），最后将该序列翻转即可得到后序遍历序列.

常规做法：使用栈模拟递归函数的调用过程，第一次出栈时紧随其后加入 NULL 标记，然后将左右子树压栈，当 NULL 出栈时意味着某个结点第二次出栈，加入后序遍历结果中.

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
```

