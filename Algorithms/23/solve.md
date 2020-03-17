## 思路

### 使用集合或优先队列

每次比较 k 个指针所指向值的大小，把它们都加入集合（或优先队列）中，然后每次取出最小值加入新链表，再将该节点的下一个节点对应的值加入集合，重复这一过程直到集合为空.

时间复杂度 $O(nlogk)$，n 为节点总数.

空间复杂度 $O(n) $.

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

bool operator<(const ListNode& a, const ListNode& b){
    return a.val<b.val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<ListNode> s;
        multiset<ListNode>::iterator it;
        ListNode* dummy=new ListNode(0),*pre=dummy;
        int k=lists.size();
        for(int i=0;i<k;++i) if(lists[i]) s.insert(*lists[i]);
        while(!s.empty()){
            it=s.begin();
            ListNode* cur=new ListNode(it->val);
            pre->next=cur;
            pre=cur;
            ListNode* nxt=it->next;
            s.erase(it);
            if(nxt) s.insert(*nxt);
        }
        return dummy->next;
    }
};
```

### 分治

1. 将 k 个链表配对并将同一对中的链表合并.
2. 第一轮合并以后，k 个链表被合并成 k/2 个链表，平均长度为 2n/k，之后是 k/4 个链表，k/8 个链表...
3. 重复这一过程，直到我们得到了最终的有序链表.

因此，我们在每一次配对合并的过程中都会遍历几乎全部 $n$ 个结点，重复这一过程 $log_{2}k$ 次.

![6f70a6649d2192cf32af68500915d84b476aa34ec899f98766c038fc9cc54662-image.png](https://i.loli.net/2020/03/17/kCw7UJmGAnXbRyF.png)

时间复杂度 $O(nlogk)$，n 为节点总数.

空间复杂度 $O(1) $.

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
    public ListNode merge2Lists(ListNode l1,ListNode l2) {
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
        cur.next=l1!=null?l1:l2;
        return dummy.next;
    }
    
    public ListNode mergeKLists(ListNode[] lists) {
        int len=lists.length;
        int interval=1;
        while(interval<len){
            for(int i=0;i+interval<len;i+=interval*2){
                lists[i]=merge2Lists(lists[i],lists[i+interval]);
            }
            interval*=2;
        }
        return len>0?lists[0]:null;
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
    def merge2Lists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(0)
        cur = dummy
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        cur.next = l1 if l1 else l2
        return dummy.next

    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        amount = len(lists)
        interval = 1
        while interval < amount:
            for i in range(0, amount - interval, interval * 2):
                lists[i] = self.merge2Lists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0] if amount > 0 else None
```

