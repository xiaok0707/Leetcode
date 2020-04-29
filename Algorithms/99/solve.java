/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public void recoverTree(TreeNode root) {
        Stack<TreeNode> stack=new Stack<>();
        TreeNode pre=null,x=null,y=null;
        while(root!=null || !stack.empty()){
            while(root!=null){
                stack.push(root);
                root=root.left;
            }
            TreeNode cur=stack.peek();stack.pop();
            if(pre!=null && pre.val>cur.val){
                y=cur;
                if(x==null) x=pre;
                else break;
            }
            pre=cur;
            root=cur.right;
        }
        int tmp=x.val;
        x.val=y.val;
        y.val=tmp;
    }
}