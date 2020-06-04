## 思路

快慢指针，快指针一次走两步，慢指针一次走一步，如果两个指针能相遇则说明有环存在，如果快指针走到 NULL 说明没有环存在.

如果有环存在，假设链表中不在环中的结点有 $A$ 个，环上的结点有 $B$ 个，假设快慢指针相遇时，快指针走的步数是 $F$，慢指针走的步数是 $S$ ，有如下两个等式：
$$
F=2S \\
F=S+kB, \ k=1,2,3...
$$
联立可得，$F=2kB,S=kB$，由于要寻找入环结点的位置，如果从链表头结点出发，走 $A+kB,\ k=1,2,3...$ 步可以到达入环结点，而在快慢指针相遇时 $S=kB$，也就是慢指针还差 $A$ 步能走到入环结点，此时将快指针重新指向链表头结点，然后让两者同时向前移动直到相遇，两者就会同时指向入环结点.

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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        if(!head->next) return NULL;
        ListNode *slow=head->next,*fast=slow->next;
        while(fast && slow!=fast){
            slow=slow->next;
            fast=fast->next;
            if(!fast) return NULL;
            fast=fast->next;
        }
        if(!fast) return NULL;
        fast=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};
```
