class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        if(!head->next) return false;

        ListNode *low=head->next,*fast=low->next;
        if(!fast) return false;
        
        while(fast!=low){
            fast=fast->next;
            if(!fast) return false;
            fast=fast->next;
            if(!fast) return false;
            low=low->next;
        }
        return true;
    }
};