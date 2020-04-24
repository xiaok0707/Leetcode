## 思路

三重循环暴力枚举分割点即可，注意不能有前导 0.

### Python

```python
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n=len(s)
        if n<4 or n>12: return []
        ans=[]
        for i in range(1,n):
            for j in range(i+1,n):
                for k in range(j+1,n):
                    if (i>1 and s[0]=='0') or int(s[0:i])>255: continue
                    if (j>i+1 and s[i]=='0') or int(s[i:j])>255: continue
                    if (k>j+1 and s[j]=='0') or int(s[j:k])>255: continue
                    if (n>k+1 and s[k]=='0') or int(s[k:])>255: continue
                    tmp=s[:i]+'.'+s[i:j]+'.'+s[j:k]+'.'+s[k:]
                    ans.append(tmp)
        return ans
```

