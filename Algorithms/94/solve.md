## 思路

利用栈进行非递归的中序遍历.

每次从当前结点出发，不断走向左子结点，并依次加入栈中. 走到尽头，将该结点从栈中弹出，计入答案，然后继续搜索该结点的右子结点. 不断重复直到搜索完整棵树.

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
```

