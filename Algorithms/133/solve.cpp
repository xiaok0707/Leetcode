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