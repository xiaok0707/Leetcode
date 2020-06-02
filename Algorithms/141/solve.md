## 思路

快慢指针，快指针一次走两步，慢指针一次走一步，如果两个指针能相遇则说明有环存在，如果快指针走到 NULL 说明没有环存在.

### C++

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        if(!head->next) return false;

        ListNode *low=head->next,*fast=low->next;
        if(!fast) return false;
        
        while(fast!=low){
            fast=fast->next;
            if(!fast) return false;
            fast=fast->next;
            if(!fast) return false;
            low=low->next;
        }
        return true;
    }
};
```
