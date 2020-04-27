## 思路

$dp[i][j]$ 表示 $s1[0,i-1],s2[0,j-1]$ 能否构成 $s3[0,i+j-1]$.

$dp[i][j]=(dp[i-1][j] \ \ and \ \ s1[i-1]=s3[i+j-1]) \ \ or \ \ (dp[i][j-1] \ \ and \ \ s2[j-1]==s3[i+j-1])$

### Python

```python
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n,m=len(s1),len(s2)
        if n+m!=len(s3): return False
        dp=[[False]*(m+1) for i in range(n+1)]
        dp[0][0]=True
        ok=True
        for j in range(1,m+1):
            if s2[j-1]==s3[j-1] and ok: dp[0][j]=True
            else: dp[0][j],ok=False,False

        for i in range(1,n+1):
            for j in range(m+1):
                if s1[i-1]==s3[i+j-1]: dp[i][j]=dp[i][j] or dp[i-1][j]
                if j>=1 and s2[j-1]==s3[i+j-1]: dp[i][j]=dp[i][j] or dp[i][j-1]

        return dp[n][m]
```

