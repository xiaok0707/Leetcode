## 思路

模拟修改指针指向关系即可.

### C++

```c++
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* ple,*le,*ri,*cur=head,*pre=dummy;
        int index=1;
        while(cur){
            if(index==m) { le=cur;ple=pre; }
            if(index==n) ri=cur;
            ++index;
            pre=cur;
            cur=cur->next;
        }
        cur=le->next;
        pre=le;
        le->next=ri->next;
        ple->next=ri;
        for(int i=0;i<n-m;++i){
            ListNode *tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return dummy->next;
    }
};
```

