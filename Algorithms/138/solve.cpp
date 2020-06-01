/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newhead=NULL,*newpre=NULL;
        Node* old=head;
        unordered_map<Node*,Node*> mp;
        while(old){
            Node* cur=new Node(old->val);
            mp[old]=cur;
            if(!newhead) newhead=newpre=cur;
            else{
                newpre->next=cur;
                newpre=cur;
            }
            old=old->next;
        }
        old=head;
        Node *ptr=newhead;
        while(ptr){
            if(old->random) ptr->random=mp[old->random];
            ptr=ptr->next;
            old=old->next;
        }
        return newhead;
    }
};