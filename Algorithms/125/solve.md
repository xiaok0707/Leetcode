## 思路

简单模拟.

### Python

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s=[ch for ch in s if ch.isdigit() or ch.isalpha()]
        n=len(s)
        i,j=0,n-1
        while i<j:
            if s[i].lower()!=s[j].lower(): return False
            i+=1
            j-=1
        return True
```

