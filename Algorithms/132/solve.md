## 思路

先使用区间 DP 预处理出任意一子串 $s[i,j]$ 是否为回文串，然后设 $dp[i]$ 为分割 $s[0,i]$ 的最小次数，则有递推方程$dp[i]=dp[j]+1,s[j+1,i]为回文串且j<i$.

### Python

```python
class Solution:
    def minCut(self, s: str) -> int:
        n=len(s)
        if 0==n: return 0
        ok=[[False]*n for i in range(n)]
        for i in range(n): ok[i][i]=True
        for i in range(n-1): ok[i][i+1]=True if s[i]==s[i+1] else False
        for L in range(2,n):
            for i in range(n-L):
                j=i+L
                ok[i][j]=ok[i+1][j-1] and s[i]==s[j]

        dp=[0]*n
        for i in range(1,n):
            if ok[0][i]:
                dp[i]=0
                continue
            dp[i]=0x7fffffff
            for j in range(1,i+1):
                if ok[j][i]: dp[i]=min(dp[i],1+dp[j-1])

        return dp[n-1]
```

