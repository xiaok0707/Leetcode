## 思路

判断一颗树是否是二叉搜索树有三个条件：

- 左、右子树都是二叉搜索树
- 根结点的值比左子树的所有结点值都大，也就是比左子树的最大值还大
- 根结点的值比右子树的所有结点值都小，也就是比右子树的最小值还小

根据这三个条件，可以递归深搜，每次返回三个值 $Max,Min,isBST$，分别表示当前树中的最大值、最小值、这棵树是否是二叉搜索树.

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
```

上面的方法是自底向上统计最大值和最小值，我们也可以自顶向下给树中的结点做限制，在搜索时确定两个参数 $lower,upper$，表示当前树中的所有结点值都必须在 $(lower,upper)$ 之间，否则认为当前树不是二叉搜索树.

下面代码使用广搜.

### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Node{
    TreeNode rt;
    Integer lower,upper;
    Node(){}
    Node(TreeNode r,Integer l,Integer u){
        rt=r;lower=l;upper=u;
    }
}

public class Solution {
    public boolean isValidBST(TreeNode root) {
        Queue<Node> que=new LinkedList<>();
        que.offer(new Node(root,null,null));
        while(!que.isEmpty()){
            Node x=que.poll();
            TreeNode rt=x.rt;
            Integer lower=x.lower,upper=x.upper;
            if(rt==null) continue;
            if(lower!=null && rt.val<=lower) return false;
            if(upper!=null && rt.val>=upper) return false;
            que.offer(new Node(rt.left,lower,rt.val));
            que.offer(new Node(rt.right,rt.val,upper));
        }
        return true;
    }
}
```

更加巧妙的一种思想：根据中序遍历的特性`左子树 -> 结点 -> 右子树` 的顺序，意味着对于二叉搜索树而言，在中序遍历序列中每个元素都应该比下一个元素小，只需要求解中序遍历序列然后检测即可.

### Python

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        stack=[]
        pre=-float('inf')
        while root!=None or len(stack)>0:
            while root!=None:
                stack.append(root)
                root=root.left
            cur=stack.pop()
            if pre>=cur.val: return False
            pre=cur.val
            root=cur.right
        return True
```

