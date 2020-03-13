/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* le=dummy,*ri=dummy;
        for(int i=0;i<n+1;++i) ri=ri->next;
        while(ri){
            le=le->next;
            ri=ri->next;
        }
        ListNode* del=le->next;
        le->next=le->next->next;
        delete del;
        return dummy->next;
    }
};