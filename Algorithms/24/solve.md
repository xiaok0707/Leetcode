## 思路

迭代修改相邻两项以及每两项之间的指针指向关系即可.

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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre=head,*cur=head->next,*res=head->next;
        while(1){
            ListNode* tmp=cur->next;
            cur->next=pre;
            if(!tmp || !tmp->next){
                pre->next=tmp;
                break;
            }
            pre->next=tmp->next;
            pre=tmp;
            cur=pre->next;
        }
        return res;
    }
};
```

### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode pre=head,cur=head.next,res=cur;
        while(true){
            ListNode tmp=cur.next;
            cur.next=pre;
            if(tmp==null || tmp.next==null){
                pre.next=tmp;
                break;
            }
            pre.next=tmp.next;
            pre=tmp;
            cur=pre.next;
        }
        return res;
    }
}
```

### Python

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        pre,cur,res=head,head.next,head.next
        while True:
            tmp=cur.next
            cur.next=pre
            if not tmp or not tmp.next:
                pre.next=tmp
                break
            pre.next=tmp.next
            pre=tmp
            cur=pre.next
        return res
```

