## 思路

利用栈进行非递归的前序遍历.

每次从当前结点出发，将该结点计入答案，然后不断走向左子结点，并依次加入栈中，走到尽头，将该结点从栈中弹出，然后继续搜索该结点的右子结点. 不断重复直到搜索完整棵树.

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
```

