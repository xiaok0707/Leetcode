## 思路

DFS或BFS，需要借助哈希表完成结点的复制，哈希表的键是原图中的结点，值是克隆图中的结点。每次创建当前点的克隆结点，然后建立指向邻接点的边。

### C++

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


class Solution {
public:
    unordered_map<Node*,Node*> done;

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(done.find(node)!=done.end()){
            return done[node];
        }
        Node* clonenode=new Node(node->val);
        done[node]=clonenode;
        int m=node->neighbors.size();
        for(int i=0;i<m;++i){
            clonenode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return clonenode;
    }
};
```

### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if(node==null) return null;
        HashMap<Node,Node> getNewNode=new HashMap<>();
        HashMap<Node,Boolean> done=new HashMap<>();
        Queue<Node> que=new LinkedList<>();
        que.offer(node);

        while(!que.isEmpty()){
            Node cur=que.poll();
            if(done.containsKey(cur)) continue;
            done.put(cur,true);

            Node clone=null;
            if(getNewNode.containsKey(cur)) clone=getNewNode.get(cur);
            else{
                clone=new Node(cur.val,new ArrayList<>());
                getNewNode.put(cur,clone);
            }

            for(Node nxt:cur.neighbors){
                Node clone_nxt=null;
                if(getNewNode.containsKey(nxt)) clone_nxt=getNewNode.get(nxt);
                else{
                    clone_nxt=new Node(nxt.val,new ArrayList<>());
                    getNewNode.put(nxt,clone_nxt);
                }
                clone.neighbors.add(clone_nxt);
                que.offer(nxt);
            }
        }

        return getNewNode.get(node);
    }
}
```

