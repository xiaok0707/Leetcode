class Node {
    String str;
    int a,b;
    Node(){}
    Node(String str,int a,int b){
        this.str=str;
        this.a=a;
        this.b=b;
    }
}

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans=new LinkedList<>();
        Queue<Node> que=new LinkedList<>();
        que.offer(new Node("",0,0));
        while(!que.isEmpty()){
            Node x=que.poll();
            if(x.a+x.b==n*2)
                ans.add(x.str);
            if(x.a<n)
                que.offer(new Node(x.str+"(",x.a+1,x.b));
            if(x.b<x.a && x.b<n)
                que.offer(new Node(x.str+")",x.a,x.b+1));
        }
        return ans;
    }
}