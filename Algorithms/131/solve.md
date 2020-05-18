## 思路

先使用区间 DP 预处理出任意一子串 $s[i,j]$ 是否为回文串，然后递归搜索.

### Python

```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n=len(s)
        if 0==n: return 0
        ok=[[False]*n for i in range(n)]
        for i in range(n): ok[i][i]=True
        for i in range(n-1): ok[i][i+1]=True if s[i]==s[i+1] else False
        for L in range(2,n):
            for i in range(n-L):
                j=i+L
                ok[i][j]=ok[i+1][j-1] and s[i]==s[j]

        ans,tmp=[],[]

        def dfs(i):
            if i==-1:
                ans.append(tmp[::-1])
                return
            for j in range(-1,i):
                if ok[j+1][i]:
                    tmp.append(s[j+1:i+1])
                    dfs(j)
                    tmp.pop()

        dfs(n-1)
        return ans
```

