## 两次遍历

删除从列表开头数起的第 $L−n+1$ 个结点，$L$ 是列表的长度。第一次遍历找列表长度，第二次遍历删除结点. 题目里链表没有表头结点，为了便于处理特殊情况（比如删除链表中的第一个结点）可以在 head 之前增加一个表头结点.

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
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy=new ListNode(0),cur=head;
        dummy.next=head;
        int len=0;
        while(cur!=null){
            ++len;
            cur=cur.next;
        }
        len-=n;
        cur=dummy;
        while(len>0){
            --len;
            cur=cur.next;
        }
        cur.next=cur.next.next;
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
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy=ListNode(0)
        dummy.next=head
        cur=head
        length=0
        while cur!=None:
            length+=1
            cur=cur.next
        cur=dummy
        length-=n
        while length>0:
            length-=1
            cur=cur.next
        cur.next=cur.next.next
        return dummy.next
```

## 一次遍历

可以使用两个指针，左指针指向表头，右指针指向从列表的开头向前移动 n+1 步。保持这两个指针的距离始终为 n 个结点，然后同时向后移动两个指针，直到右指针为空，此时左指针将指向倒数第 n+1 个结点，根据指针的指向关系将倒数第 n 个结点删除即可.

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        ListNode le=dummy,ri=dummy;
        for(int i=0;i<n+1;++i) ri=ri.next;
        while(ri!=null){
            le=le.next;
            ri=ri.next;
        }
        le.next=le.next.next;
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
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy=ListNode(0)
        dummy.next=head
        le,ri=dummy,dummy
        for i in range(n+1):
            ri=ri.next
        while ri!=None:
            le=le.next
            ri=ri.next
        le.next=le.next.next
        return dummy.next
```

