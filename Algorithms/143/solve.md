## 思路

以链表 $[1,2,3,4,5,6,7]$ 为例，

1. 首先将其拆分成左右两部分，分别是 $[1,2,3,4]$ 和 $[5,6,7]$.
2. 将右半部分翻转，变成 $[1,2,3,4]$ 和 $[7,6,5]$.
3. 依次从左右两个链表的头部取出元素，将这两个链表合并，最终变成 $[1,7,2,6,3,5,4]$.

### C++

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* pre=NULL,*cur=head;
        while(cur){
            ListNode* newcur=cur->next;
            cur->next=pre;
            pre=cur;
            cur=newcur;
        }
        return pre;
    }

    ListNode* mergeList(ListNode* A,ListNode* B){
        ListNode* cura=A,*curb=B;
        while(cura && curb){
            ListNode* newcura=cura->next,*newcurb=curb->next;
            cura->next=curb;
            curb->next=newcura;
            cura=newcura;
            curb=newcurb;
        }
        return A;
    }

    void reorderList(ListNode* head) {
        int cnt=0;
        ListNode* pre=NULL,*cur=head;
        while(cur) { ++cnt; cur=cur->next; }
        if(cnt<=2) return;
        cur=head;
        for(int i=0;i<(1+cnt)/2;++i) { pre=cur; cur=cur->next; }
        pre->next=NULL;
        ListNode* head2=reverseList(cur);
        mergeList(head,head2);
    }
};
```

