## 思路

每次比较 l1 和 l2 对应结点值的大小，把较小的结点连接到结果链表之后，l1 和 l2 不断向后移动，直到遍历整个链表.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0),*cur=dummy;
        while(l1 && l2){
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        while(l1){
            cur->next=l1;
            l1=l1->next;
            cur=cur->next;
        }
        while(l2){
            cur->next=l2;
            l2=l2->next;
            cur=cur->next;
        }
        return dummy->next;
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy=new ListNode(0),cur=dummy;
        while(l1!=null && l2!=null){
            if(l1.val<l2.val){
                cur.next=l1;
                l1=l1.next;
            }
            else{
                cur.next=l2;
                l2=l2.next;
            }
            cur=cur.next;
        }
        while(l1!=null){
            cur.next=l1;
            l1=l1.next;
            cur=cur.next;
        }
        while(l2!=null){
            cur.next=l2;
            l2=l2.next;
            cur=cur.next;
        }
        return dummy.next;
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
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy=ListNode(0)
        cur=dummy
        while l1 and l2:
            if l1.val<l2.val:
                cur.next=l1
                l1=l1.next
            else:
                cur.next=l2
                l2=l2.next
            cur=cur.next
        while l1:
            cur.next=l1
            l1=l1.next
            cur=cur.next
        while l2:
            cur.next=l2
            l2=l2.next
            cur=cur.next
        return dummy.next
```

