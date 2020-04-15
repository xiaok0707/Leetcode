## 思路

简单搜索.

### Python

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans,tmp=[],[]
        used=[False for i in range(n)]

        def dfs(cur):
            if cur==k:
                ans.append(tmp[:])
                return
            for i in range(n):
                if not used[i] and (len(tmp)==0 or i+1>tmp[-1]):
                    used[i]=True
                    tmp.append(i+1)
                    dfs(cur+1)
                    used[i]=False
                    tmp.pop()
        dfs(0)
        return ans
```

