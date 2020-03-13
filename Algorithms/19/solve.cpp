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
        ListNode* dummy=new ListNode(0),*cur=head;
        dummy->next=head;
        int len=0;
        while(cur){
            ++len;
            cur=cur->next;
        }
        len-=n;
        cur=dummy;
        while(len){
            --len;
            cur=cur->next;
        }
        ListNode* del=cur->next;
        cur->next=cur->next->next;
        delete del;
        return dummy->next;
    }
};