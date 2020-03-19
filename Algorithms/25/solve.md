## 思路

比较复杂的模拟，迭代修改指针指向关系.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(1==k) return head;
        ListNode* le=head,*pre,*cur,*res=NULL,*tmp;
        while(1){
            pre=le;
            cur=pre->next;
            for(int i=0;i<k-1;++i){
                tmp=cur->next;
                cur->next=pre;
                pre=cur;
                cur=tmp;
            }
            if(!res) res=pre;
            bool flag=false;
            for(int i=0;i<k-1;++i){
                if(!tmp){
                    flag=true;
                    break;
                }
                tmp=tmp->next;
            }
            if(!tmp) flag=true;
            if(flag){
                le->next=cur;
                break;
            }
            else{
                le->next=tmp;
                le=cur;
            }
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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(1==k) return head;
        ListNode le=head,res=null;
        while(true){
            ListNode pre=le,cur=pre.next,tmp=null;
            for(int i=0;i<k-1;++i){
                tmp=cur.next;
                cur.next=pre;
                pre=cur;
                cur=tmp;
            }
            if(res==null) res=pre;
            boolean flag=false;
            for(int i=0;i<k-1;++i){
                if(tmp==null){
                    flag=true;
                    break;
                }
                tmp=tmp.next;
            }
            if(tmp==null) flag=true;
            if(flag){
                le.next=cur;
                break;
            }
            else{
                le.next=tmp;
                le=cur;
            }
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
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if 1==k:
            return head
        le,res=head,None
        while True:
            pre=le
            cur=pre.next
            for i in range(k-1):
                tmp=cur.next
                cur.next=pre
                pre=cur
                cur=tmp
            if res==None:
                res=pre
            flag=False
            for i in range(k-1):
                if tmp==None:
                    flag=True
                    break
                tmp=tmp.next
            if tmp==None:
                flag=True
            if flag:
                le.next=cur
                break
            else:
                le.next=tmp
                le=cur
        return res
```

