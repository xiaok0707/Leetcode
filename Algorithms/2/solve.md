## 思路

考察单向链表的使用，使用链表去模拟即可，需要注意两个数字的位数可能不等，计算完毕如果最后进位标志不为0那么还要再新建一个结点。

时间复杂度 $O(n)$

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1=l1,*p2=l2,*head,*pre,*cur;
        int flag=0;
        pre=new ListNode(0);
        head=pre;
        while(p1 && p2){
            int x=(p1->val)+(p2->val)+flag;
            flag=x/10;
            cur=new ListNode(x%10);
            pre->next=cur;
            pre=cur;
            p1=p1->next;
            p2=p2->next;
        }
        while(p1){
            int x=(p1->val)+flag;
            flag=x/10;
            cur=new ListNode(x%10);
            pre->next=cur;
            pre=cur;
            p1=p1->next;
        }
        while(p2){
            int x=(p2->val)+flag;
            flag=x/10;
            cur=new ListNode(x%10);
            pre->next=cur;
            pre=cur;
            p2=p2->next;
        }
        if(flag){
            cur=new ListNode(flag);
            pre->next=cur;
        }
        return head->next;
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode p1=l1,p2=l2,head,pre,cur;
        pre=new ListNode(0);
        head=pre;
        int flag=0;
        while(p1!=null && p2!=null){
            int x=p1.val+p2.val+flag;
            flag=x/10;
            cur=new ListNode(x%10);
            pre.next=cur;
            pre=cur;
            p1=p1.next;
            p2=p2.next;
        }
        while(p1!=null){
            int x=p1.val+flag;
            flag=x/10;
            cur=new ListNode(x%10);
            pre.next=cur;
            pre=cur;
            p1=p1.next;
        }
        while(p2!=null){
            int x=p2.val+flag;
            flag=x/10;
            cur=new ListNode(x%10);
            pre.next=cur;
            pre=cur;
            p2=p2.next;
        }
        if(flag!=0){
            cur=new ListNode(flag);
            pre.next=cur;
        }
        return head.next;
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
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        p1=l1
        p2=l2
        pre=ListNode(0)
        head=pre
        flag=0
        while p1!=None and p2!=None:
            x=p1.val+p2.val+flag
            flag=x//10;
            cur=ListNode(x%10)
            pre.next=cur
            pre=cur
            p1=p1.next
            p2=p2.next
        while p1!=None:
            x=p1.val+flag
            flag=x//10;
            cur=ListNode(x%10)
            pre.next=cur
            pre=cur
            p1=p1.next
        while p2!=None:
            x=p2.val+flag
            flag=x//10
            cur=ListNode(x%10)
            pre.next=cur
            pre=cur
            p2=p2.next
        if flag!=0:
            cur=ListNode(flag)
            pre.next=cur
        return head.next
```

