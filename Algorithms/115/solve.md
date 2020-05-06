## 思路

$dp[i][j]$ 表示 $s[0,i-1]$ 的子序列包含 $t[0,j-1]$ 的个数，$Ans=dp[lens][lent]$

$dp[i][j]=dp[i-1][j],(s[i-1] \neq t[j-1])$

$dp[i][j]=dp[i-1][j]+dp[i-1][j-1],(s[i-1]=t[j-1])$

$dp[0][0]=1$

计算 $dp[i][j]$ 只需要用到 $i-1$ 的结果，所以可以省略第一维度节省空间.

### Python

```python
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n,m=len(s),len(t)
        dp=[0]*(m+1)
        dp[0]=1
        for i in range(1,n+1):
            for j in range(m,0,-1):
                if s[i-1]==t[j-1]:
                    dp[j]+=dp[j-1]
        return dp[m]
```

