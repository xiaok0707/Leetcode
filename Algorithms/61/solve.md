## 思路

假设链表长度为 n，那么向后循环移动 k 位其实就是将第 n-k+1 个元素作为开头，修改相应指针指向关系即可.

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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode *tail=NULL,*new_head=head,*new_tail=NULL,*p=head;
        while(p){
            ++n;
            tail=p;
            p=p->next;
        }
        if(n==0) return NULL;
        k%=n;
        if(k==0) return head;
        for(int i=0;i<n-k;++i){
            new_tail=new_head;
            new_head=new_head->next;
        }
        tail->next=head;
        new_tail->next=NULL;
        return new_head;
    }
};
```

