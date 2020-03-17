/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool operator<(const ListNode& a, const ListNode& b){
    return a.val<b.val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<ListNode> s;
        multiset<ListNode>::iterator it;
        ListNode* dummy=new ListNode(0),*pre=dummy;
        int k=lists.size();
        for(int i=0;i<k;++i) if(lists[i]) s.insert(*lists[i]);
        while(!s.empty()){
            it=s.begin();
            ListNode* cur=new ListNode(it->val);
            pre->next=cur;
            pre=cur;
            ListNode* nxt=it->next;
            s.erase(it);
            if(nxt) s.insert(*nxt);
        }
        return dummy->next;
    }
};